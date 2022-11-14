






using System.Net;
using System.Net.Sockets;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.Json;

class Program
{
    public static void Main()
    {
        const int PORT = 8005;
        const string IP = "127.0.0.1";

        var buffer = new byte[1000];
        string msg = string.Empty;

        var iPEndPoint = new IPEndPoint(IPAddress.Parse(IP), PORT);

        var socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        
        socket.Connect(iPEndPoint); // подключаемся к удаленной точке

        var bytes = socket.Receive(buffer); // получаем ответ

        msg = Encoding.UTF8.GetString(buffer, 0, bytes);

        var peoples = JsonSerializer.Deserialize<List<People>>(msg);

        foreach (var people in peoples)
        {
            Console.WriteLine(people);
        }

        socket.Shutdown(SocketShutdown.Both); // закрываем сокет
        socket.Close(); // закрываем сокет
        









    }    
}



class People
{
    public string Name { get; set; }
    public string FirstName { get; set; }
    public int Age { get; set; }

    public People(string name, string firstName, int age)
    {
        Name = name;
        FirstName = firstName;
        Age = age;
    }

    public override string ToString() => string.Format("Name: {0}, FirstName: {1}, Age: {2}", Name, FirstName, Age);
}
