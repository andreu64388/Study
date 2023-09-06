using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;



enum TypeTesting
{
    Test,
    Exam
}
abstract class Testing : IComparable
{
    
    #region Fields
    protected  string _name;
    protected int _time;
    protected TypeTesting Type;
    


    public Week Day = Week.Saturday;
    #endregion

    #region Properties
    public virtual string Name
    {
        get=>_name;
        set => _name = value;
    }

    public virtual int Time
    {
        get => _time;
        set => _time = value;
    }

    
    #endregion

    #region Constructors
    public  Testing()
    {
        Name = "Default";
        Time = 0;
        
    }

    public Testing(string name, int time)
    {
        Name = name;
        Time = time;
       
    }
    #endregion

    #region Methods
    
    public override string ToString()
    {
        return $"Name: {Name}, Time: {Time}";
    }

    public virtual void Successfully() => Console.WriteLine("Успешно испытание");

    public abstract void Failed();

    public int CompareTo(object? obj)
    {
        if (obj is Testing)
        {
            Testing testing = (Testing)obj;
            return this.Time.CompareTo(testing.Time);
        }
        else
        {
            throw new Exception("Невозможно сравнить два объекта");
        }




    }

    #endregion

}





enum Week
{
    Monday,
    Tuesday,
    Wendesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
        

}

// enum это перечисление, оно позволяет создать список констант, которые можно использовать в коде.