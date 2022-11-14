
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;

class Program
{
   public static void Main()
    {
        List<People> peoples = new()
        {
            new  ("Andrey 1","Korenckuck",12),
            new  ("Andrey 2","Korenckuck",22),
            new  ("Andrey 3","Korenckuck",32),
            
        };

        //сокет

        const int PORT = 8005;
        const string IP = "127.0.0.1";
        
        string msg = null;
        var buffer = new byte[1000]; 
        
        

        IPEndPoint iPEndPoint = new(IPAddress.Parse(IP),PORT);

        Socket socket = new(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        socket.Bind(iPEndPoint); // связываем сокет с локальной точкой

        socket.Listen(1); // 1 - кол-во подключений

        var listener = socket.Accept(); // принимаем подключение

        msg = JsonSerializer.Serialize(peoples);

        buffer = Encoding.UTF8.GetBytes(msg);

        listener.Send(buffer); // отправляем данные

        listener.Shutdown(SocketShutdown.Both); // закрываем сокет

        listener.Close(); // закрываем сокет








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

    public override string ToString()=> string.Format("Name: {0}, FirstName: {1}, Age: {2}", Name, FirstName, Age);
    

}



