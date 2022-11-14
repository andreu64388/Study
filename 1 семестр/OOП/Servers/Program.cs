using System.Net.Sockets;
using System.Net;
using System.Text;

class Server
{
    public static void Main()
    {
        const string ip = "127.0.0.1";
        const int port = 8282;

        IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(ip), port);

        Socket listenSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        try
        {
            // сделать чат ,чтобы одн одного пользователя к другому
            listenSocket.Bind(ipPoint);

            listenSocket.Listen(10);

            Console.WriteLine("Сервер запущен. Ожидание подключений...");

            Socket handler = listenSocket.Accept();

            string message = "Привет клиент";

            byte[] data = Encoding.Unicode.GetBytes(message);

            handler.Send(data);

            data = new byte[256];

            StringBuilder builder = new StringBuilder();

            int bytes = 0;

            do
            {
                bytes = handler.Receive(data);
                builder.Append(Encoding.Unicode.GetString(data, 0, bytes));
            }
            while (handler.Available > 0);

            Console.WriteLine(DateTime.Now.ToShortTimeString() + ": " + builder.ToString());

            handler.Shutdown(SocketShutdown.Both);

            handler.Close();

        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    }


}