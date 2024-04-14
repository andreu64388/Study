using DatabaseClasses.Pattern;
using Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.Threading;
using System.Threading.Tasks;

namespace CentralizedServer
{
    class Program
    {
        public static string ip = "192.168.69.33";
        static void Main(string[] args)
        {
            //Лабораторная 6-----------------------------
            Console.WriteLine("Начало работы: сервер");
            GenerateAndSendData();
            Console.WriteLine();
            //-------------------------------------------

            //Лабораторная 4 и 5--------------------
            //ListenFirstClientForStatus();   // Слушаем первого клиента на состояние
            //ListenFirstClientForData();     // Слушаем первого клиента на данные

            //ListenSecondClientForStatus();
            //ListenSecondClientForData();
            //---------------------------------

            while (true)
            {
            }
        }

        async public static void ListenFirstClientForData() 
        {
            await Task.Run(() =>
            {
                while(true)
                {
                    int port = 2001;
                    IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(ip), port); // Создаем "указатель" для сокета
                    Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    try
                    {
                        socket.Bind(ipPoint);   // Привязываем сокет к указателю
                        socket.Listen(10);  

                        Console.WriteLine("Ожидание подключения первого клиента: работа с данными...");
                        Socket handler = socket.Accept();   

                        //Request zone-------------------------------------------
                        string request = "GetData";
                        byte[] outMessage = Encoding.Default.GetBytes(request); // Кодируем сообщение в байты
                        int sendBytes = 0;

                        Console.WriteLine("\nОтправка запроса на данные первому клиенту...");
                        sendBytes = handler.Send(outMessage);   
                        //-------------------------------------------------------

                        //Response zone------------------------------------------
                        byte[] inMessage = new byte[256];
                        int getBytes = 0;
                        do
                        {
                            Console.WriteLine("Ожидание ответа с данными от первого клиента...");
                            getBytes = handler.Receive(inMessage);

                        } while (handler.Available > 0);    // Ждем пока не придут все данные

                        byte[] onlyGoodData = new byte[getBytes];   // Убираем лишние байты
                        for (int i = 0; i < getBytes; i++)
                        {
                            onlyGoodData[i] = inMessage[i];
                        }

                        Data data = JsonSerializer.Deserialize<Data>(onlyGoodData);

                        Console.WriteLine("Данные от первого клиента-----------------------\n" 
                                        + "id: " + data.CreatorNumber + " Time: " + data.Time + "\n"
                                        + "------------------------------------------------");

                        using (UnitOfWork unitOfWork = new UnitOfWork("ServerDBConnect")) // Записываем данные в центральную бд
                        {
                            Console.WriteLine("Запись только что полученных данных от первго клиента в центральную бд...");
                            unitOfWork.DataRepository.AddItem(data);
                            unitOfWork.Save();
                        }
                        //-------------------------------------------------------

                        handler.Shutdown(SocketShutdown.Both);
                        handler.Close();
                        socket.Close();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
               
            });   
        }

        async public static void ListenFirstClientForStatus()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    int port = 2003;
                    IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(ip), port);
                    Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    try
                    {
                        socket.Bind(ipPoint);
                        socket.Listen(10);

                        Console.WriteLine("Ожидание подключения первого клиента: работа с состоянием...");
                        Socket handler = socket.Accept();

                        //Request zone-------------------------------------------
                        string request = "GetState";
                        byte[] outMessage = Encoding.Default.GetBytes(request);
                        int sendBytes = 0;


                        Console.WriteLine("\nОтправка запроса на состояние первому клиенту...");
                        sendBytes = handler.Send(outMessage);
                        //-------------------------------------------------------

                        //Response zone------------------------------------------
                        byte[] inMessage = new byte[256];
                        int getBytes = 0;
                        do
                        {
                            Console.WriteLine("Ожидание ответа с состоянием от первого клиента...");
                            getBytes = handler.Receive(inMessage);

                        } while (handler.Available > 0);

                        Console.WriteLine("Состояние первого клиента: длина коллекции с данными: " + Encoding.Default.GetString(inMessage));
                        //-------------------------------------------------------

                        handler.Shutdown(SocketShutdown.Both);
                        handler.Close();
                        socket.Close();

                        Thread.Sleep(2000);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
            });
        }

        async public static void ListenSecondClientForData()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    int port = 2002;
                    IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(ip), port);
                    Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    try
                    {
                        socket.Bind(ipPoint);
                        socket.Listen(10);

                        Console.WriteLine("Ожидание подключения второго клиента: работа с данными...");
                        Socket handler = socket.Accept();

                        //Request zone-------------------------------------------
                        string request = "GetData";
                        byte[] outMessage = Encoding.Default.GetBytes(request);
                        int sendBytes = 0;

                        Console.WriteLine("\nОтправка запроса на данные второму клиенту...");
                        sendBytes = handler.Send(outMessage);
                        //-------------------------------------------------------

                        //Response zone------------------------------------------
                        byte[] inMessage = new byte[256];
                        int getBytes = 0;
                        do
                        {
                            Console.WriteLine("Ожидание ответа с данными от второго клиента...");
                            getBytes = handler.Receive(inMessage);

                        } while (handler.Available > 0);

                        byte[] onlyGoodData = new byte[getBytes];
                        for (int i = 0; i < getBytes; i++)
                        {
                            onlyGoodData[i] = inMessage[i];
                        }

                        Data data = JsonSerializer.Deserialize<Data>(onlyGoodData);

                        Console.WriteLine("Данные от второго клиента-----------------------\n"
                                        + "id: " + data.CreatorNumber + " Time: " + data.Time + "\n"
                                        + "------------------------------------------------");

                        using (UnitOfWork unitOfWork = new UnitOfWork("ServerDBConnect"))
                        {
                            Console.WriteLine("Запись только что полученных данных от второго клиента в центральную бд...");
                            unitOfWork.DataRepository.AddItem(data);
                            unitOfWork.Save();
                        }
                        //-------------------------------------------------------

                        handler.Shutdown(SocketShutdown.Both);
                        handler.Close();
                        socket.Close();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
            });
        }

        async public static void ListenSecondClientForStatus()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    int port = 2004;
                    IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(ip), port);
                    Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    try
                    {
                        socket.Bind(ipPoint);
                        socket.Listen(10);

                        Console.WriteLine("Ожидание подключения второго клиента: работа с состоянием...");
                        Socket handler = socket.Accept();

                        //Request zone-------------------------------------------
                        string request = "GetState";
                        byte[] outMessage = Encoding.Default.GetBytes(request);
                        int sendBytes = 0;


                        Console.WriteLine("\nОтправка запроса на состояние второму клиенту...");
                        sendBytes = handler.Send(outMessage);
                        //-------------------------------------------------------

                        //Response zone------------------------------------------
                        byte[] inMessage = new byte[256];
                        int getBytes = 0;
                        do
                        {
                            Console.WriteLine("Ожидание ответа с состоянием от второго клиента...");
                            getBytes = handler.Receive(inMessage);

                        } while (handler.Available > 0);

                        Console.WriteLine("Состояние второго клиента: длина коллекции с данными: " + Encoding.Default.GetString(inMessage));
                        //-------------------------------------------------------

                        handler.Shutdown(SocketShutdown.Both);
                        handler.Close();
                        socket.Close();

                        Thread.Sleep(2000);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
            });
        }

        async public static void GenerateAndSendData()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    Console.WriteLine("Генерация данных для сервера...");
                    DateTime time = DateTime.Now;
                    Data forInsert = new Data { CreatorNumber = 3, Time = time.ToString(), ItNew = false };

                    Console.WriteLine("Отправка сгенерированыых данных в центральную бд");
                    using (UnitOfWork unitOfWork = new UnitOfWork("ServerDBConnect"))
                    {
                        unitOfWork.DataRepository.AddItem(forInsert);
                        unitOfWork.Save();
                    }

                    Console.WriteLine("Отправка сгенерированыых данных в бд первого клиента");
                    using (UnitOfWork unitOfWork = new UnitOfWork("FirstDBConnect"))
                    {
                        unitOfWork.DataRepository.AddItem(forInsert);
                        unitOfWork.Save();
                    }

                    Console.WriteLine("Отправка сгенерированыых данных в бд второго клиента");
                    using (UnitOfWork unitOfWork = new UnitOfWork("SecondDBConnect"))
                    {
                        unitOfWork.DataRepository.AddItem(forInsert);
                        unitOfWork.Save();
                    }
                    Thread.Sleep(10000);
                }
            });
        }
    }
}