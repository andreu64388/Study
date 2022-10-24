using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_2;

public class Test
{

    /* Создать класс Airline: Пункт назначения, Номер рейса,
Тип самолета, Время вылета, Дни недели. Свойства и
конструкторы д*/

    // статическое поле 
    public static int count = 0;


    private readonly int ID;
    private string destination;
    private int flightNumber;
    private string planeType;
    private string departureTime;
    private string daysOfWeek;


    //свойства
        public string Destination
        {
            get => destination; set
            {
                if (value.Length > 0)
                {
                    destination = value;
            }
            else
            {
                Console.WriteLine("Некорректное значение");
            }
        }

    }
    public int FlightNumber
    {
        get => flightNumber; set
        {
            if (value > 0)
            {
                flightNumber = value;
            }
            else
            {
                Console.WriteLine("Номер рейса не может быть отрицательным");
            }
        }
    }
    public string PlaneType { get => planeType; set => planeType = value; }
    public string DepartureTime { get => departureTime; set => departureTime = value; }
    public string DaysOfWeek { get => daysOfWeek; set => daysOfWeek = value; }
    public int ID1 { get => ID; }

    private const int a = 5;

    //конструкторы

    //конструктор по умолчанию
    public Test()

    {
        ID = a;
        destination = "Minsk";
        flightNumber = 123;
        planeType = "Boeing";
        departureTime = "12:00";
        daysOfWeek = "Monday";
    }

    //конструктор с параметрами
    public Test(int id, string destination, int flightNumber, string planeType, string departureTime, string daysOfWeek)
    {
        ID = id;
        this.destination = destination;
        this.flightNumber = flightNumber;
        this.planeType = planeType;
        this.departureTime = departureTime;
        this.daysOfWeek = daysOfWeek;
    }
    // закрытый конструктор
    private Test(int id)
    {
        ID = id;
    }

    //методы
    public void Print()
    {
        Console.WriteLine("ID: " + ID);
        Console.WriteLine("Destination: " + destination);
        Console.WriteLine("FlightNumber: " + flightNumber);
        Console.WriteLine("PlaneType: " + planeType);
        Console.WriteLine("DepartureTime: " + departureTime);
        Console.WriteLine("DaysOfWeek: " + daysOfWeek);
    }



    public static void PrintCount()
    {
        Console.WriteLine("Count: " + count);
    }


    //в одном из методов класса для работы с аргументами используйте ref - и out-параметры  
    public void Print(ref int a, out int b)
    {
        a = 10;
        b = 20;
    }

    /*   переопределяете методы класса Object: Equals, для сравнения объектов,
   GetHashCode; для алгоритма вычисления хэша руководствуйтесь
   стандартными рекомендациями, ToString – вывода строки –
   информации об объекте.*/
    public override bool Equals(object obj)
    {
        if (obj == null)
            return false;
        Test p = obj as Test;
        if (p as Test == null)
            return false;
        return (ID == p.ID) && (destination == p.destination) && (flightNumber == p.flightNumber) && (planeType == p.planeType) && (departureTime == p.departureTime) && (daysOfWeek == p.daysOfWeek);
    }

    //GetHashCode 
    public override int GetHashCode()
    {
        return ID.GetHashCode() ^ destination.GetHashCode() ^ flightNumber.GetHashCode() ^ planeType.GetHashCode() ^ departureTime.GetHashCode() ^ daysOfWeek.GetHashCode();
    }
    // переопределение метода ToString
    public override string ToString()
    {
        return "ID: " + ID + " Destination: " + destination + " FlightNumber: " + flightNumber + " PlaneType: " + planeType + " DepartureTime: " + departureTime + " DaysOfWeek: " + daysOfWeek;
    }









}