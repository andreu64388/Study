

namespace Control_work_1;


class Date
{
    public int Day { get; set; }
    public int Month { get; set; }
    public int Year { get; }
    public Date(int day, int month, int year)
    {
        Day = day;
        Month = month;
        Year = year;
    }



    public override string ToString()
    {
        return $"{Day}.{Month}.{Year}";
    }

    public override bool Equals(object obj)
    {
        if (obj is Date date)
        {
            return Day == date.Day && Month == date.Month && Year == date.Year;
        }
        return false;
    }

    
    public static int operator %(Date date, int i)
    {
        if (i == 1)
        {
            return date.Day;
        }
        else if (i == 2)
        {
            return date.Month;
        }
        else
        {
            throw new Exception("Неверный индекс");
        }
    }



}

#region 3ex
interface IGood {
    void Plus();
}

interface IBad
{
    void Plus();
}



class BelDate : Date, IGood, IBad
{
    public string Status { get; set; }
    public BelDate(int day, int month, int year, string status) : base(day, month, year)
    {
        Status = status;
    }


    void IGood.Plus()
    {
        Day++;
    }

    void IBad.Plus()
    {
        Day--;
    }

    public override string ToString()
    {
        return $"{Day}.{Month}.{Year} {Status}";
    }
}

#endregion