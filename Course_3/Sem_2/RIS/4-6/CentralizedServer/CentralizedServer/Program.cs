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
        public static string ip = "192.168.51.218";
        static void Main(string[] args)
        {
            Console.WriteLine("Начало работы: сервер");

            //Лабораторная 4--------------------
            //ListenFirstClientForStatus();   
            //ListenFirstClientForData(); 

            //ListenSecondClientForStatus();
            //ListenSecondClientForData();
            //---------------------------------

            //Лабораторная 5--------------------
            //GenerateAndSendData();
            //---------------------------------

            //Лабораторная 6-----------------------------
            ReplicateData();
            Console.WriteLine();
            //-------------------------------------------
            while (true)
            {
            }
        }

        public static void ReplicateData()
        {
            // Создаем объект UnitOfWork для центральной базы данных
            using (UnitOfWork centralUnitOfWork = new UnitOfWork("ServerDBConnect"))
            {
                while (true)
                {
                    try
                    {
                        // Получаем данные из центральной базы данных
                        var data = centralUnitOfWork.DataRepository.GetItems();

                        // Репликация данных в FirstDB
                        using (UnitOfWork firstDbUnitOfWork = new UnitOfWork("FirstDBConnect"))
                        {
                            Console.WriteLine("Репликация данных в FirstDB...");
                            foreach (var item in data)
                            {
                                firstDbUnitOfWork.DataRepository.AddItem(item); // Предположим, что здесь используется метод AddItem() для добавления данных
                            }
                            firstDbUnitOfWork.Save();
                        }

                        // Репликация данных в SecondDB
                        using (UnitOfWork secondDbUnitOfWork = new UnitOfWork("SecondDBConnect"))
                        {
                            Console.WriteLine("Репликация данных в SecondDB...");
                            foreach (var item in data)
                            {
                                secondDbUnitOfWork.DataRepository.AddItem(item); // Предположим, что здесь используется метод AddItem() для добавления данных
                            }
                            secondDbUnitOfWork.Save();
                        }

                        Thread.Sleep(6000);
                    }
                    catch (Exception ex)
                    {
                        // Обработка ошибок репликации
                        Console.WriteLine($"Ошибка при репликации данных: {ex.Message}");
                    }
                }
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

                    Console.WriteLine("Выполняется репликация данных в центральную базу данных...");

                    ReplicateDataToCentralDB("ServerDBConnect", forInsert);

                    Thread.Sleep(10000);
                }
            });
        }

        public static void ReplicateDataToCentralDB(string connectionStringName, Data data)
        {
            try
            {
                using (UnitOfWork unitOfWork = new UnitOfWork(connectionStringName))
                {
                    Console.WriteLine($"Запись данных в центральную бд ({connectionStringName})...");
                    unitOfWork.DataRepository.AddItem(data);
                    unitOfWork.Save();
                    Console.WriteLine($"Данные успешно записаны в центральную бд ({connectionStringName})");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при записи данных в центральную бд ({connectionStringName}): {ex.Message}");
            }
        }
    }
}