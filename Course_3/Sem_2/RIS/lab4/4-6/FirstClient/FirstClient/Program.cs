using Models;
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.Threading;
using System.Threading.Tasks;

namespace FirstClient
{
    class Program
    {
        static string ip = "192.168.69.33";
        static void Main(string[] args)
        {
            //Лабораторная 4 и часть 5----------------------------
            Console.WriteLine("Начало работы: первый клиент");
            GetRequestFromServerForData();
            GetRequestFromServerForState();
            //----------------------------------------------------
            while (true)
            {

            }
        }

        async public static void GetRequestFromServerForData()
        {
            await Task.Run(() => {
                while (true)
                {
                    try
                    {
                        int port = 2001;
                        IPEndPoint ipPoint = new(IPAddress.Parse(ip), port);
                        Socket socket = new(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                        socket.Connect(ipPoint);

                        //Request zone-------------------------------------------
                        StringBuilder request = new();
                        byte[] inMessage = new byte[256];
                        int getByte = 0;
                        do
                        {
                            Console.WriteLine("\nFOR DATA: Отправка запроса серверу на получение данных...");
                            getByte = socket.Receive(inMessage);
                            request.Append(Encoding.Default.GetString(inMessage));

                        } while (socket.Available > 0);
                        //-------------------------------------------------------

                        //Response zone------------------------------------------
                        byte[] outMessage;
                        int sendBytes = 0;


                        Console.WriteLine("FOR DATA: Подтягивание данных с базы данных...");
                        Data data = null;
                        while (data == null)
                        {
                            data = FirstListWork.GetElement();
                            Thread.Sleep(1000);
                        }
                        string jsonString = JsonSerializer.Serialize(data);
                        outMessage = Encoding.Default.GetBytes(jsonString);

                        Console.WriteLine("FOR DATA: Отправка серверу ответа с данными...");
                        sendBytes = socket.Send(outMessage);
                        //-------------------------------------------------------

                        socket.Shutdown(SocketShutdown.Both);
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

        async public static void GetRequestFromServerForState()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    try
                    {
                        int port = 2003;
                        IPEndPoint ipPoint = new(IPAddress.Parse(ip), port);
                        Socket socket = new(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                        socket.Connect(ipPoint);

                        //Request zone-------------------------------------------
                        StringBuilder request = new();
                        byte[] inMessage = new byte[256];
                        int getByte = 0;
                        do
                        {
                            Console.WriteLine("\nFOR STATE: Ожидание запроса на получение состояния от сервера...");
                            getByte = socket.Receive(inMessage);
                            request.Append(Encoding.Default.GetString(inMessage));

                        } while (socket.Available > 0);
                        //-------------------------------------------------------

                        //Response zone------------------------------------------
                        byte[] outMessage;
                        int sendBytes = 0;

                        Console.WriteLine("FOR STATE: Анализ состояния...");
                        outMessage = Encoding.Default.GetBytes(FirstListWork.GetLength().ToString());

                        Console.WriteLine("FOR STATE: Отправка серверу ответа с состоянием...");
                        sendBytes = socket.Send(outMessage);
                        //-------------------------------------------------------

                        socket.Shutdown(SocketShutdown.Both);
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


    }
}
