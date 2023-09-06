namespace laba_10;
class Airplane
{


    #region Fields
    
    public static int count = 0;
    private readonly int ID;
    private string destination;
    private int flightNumber;
    private string planeType;
    private string departureTime;
    private string daysOfWeek;
    private const int a = 5;

    #endregion

    #region Properties
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

    #endregion

    #region Consructors
    public Airplane()

    {
        ID = a;
        destination = "Minsk";
        flightNumber = 123;
        planeType = "Boeing";
        departureTime = "12:00";
        daysOfWeek = "Monday";
    }

 
    public Airplane(int id, string destination, int flightNumber, string planeType, string departureTime, string daysOfWeek)
    {
        ID = id;
        this.destination = destination;
        this.flightNumber = flightNumber;
        this.planeType = planeType;
        this.departureTime = departureTime;
        this.daysOfWeek = daysOfWeek;
    }
    
    private Airplane(int id)
    {
        ID = id;
    }

    #endregion

    #region Metdos
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
    public void Print(ref int a, out int b)
    {
        a = 10;
        b = 20;
    }

    public override bool Equals(object obj)
    {
        if (obj == null)
            return false;
        Airplane p = obj as Airplane;
        if (p as Airplane == null)
            return false;
        return (ID == p.ID) && (destination == p.destination) && (flightNumber == p.flightNumber) && (planeType == p.planeType) && (departureTime == p.departureTime) && (daysOfWeek == p.daysOfWeek);
    }

    public override int GetHashCode()
    {
        return ID.GetHashCode() ^ destination.GetHashCode() ^ flightNumber.GetHashCode() ^ planeType.GetHashCode() ^ departureTime.GetHashCode() ^ daysOfWeek.GetHashCode();
    }
 
    public override string ToString()
    {
        return "ID: " + ID + " Destination: " + destination + " FlightNumber: " + flightNumber + " PlaneType: " + planeType + " DepartureTime: " + departureTime + " DaysOfWeek: " + daysOfWeek;
    }

    #endregion

}