
using System.Text.Json;

namespace laba_12;



static class KAVLog
{
    #region Fields

    private const string PATH_TO_FILE = "kavlogfile.json";

    #endregion

    #region Methods 

    public static void WriteToFile(string methodName, string className)
    {
        Data datas = new(methodName, className);
        datas.Print();

        var newData = JsonSerializer.Serialize(datas);

        using (StreamWriter sw = new(PATH_TO_FILE, true))
        {
            sw.WriteLine(newData);
        }

    }
    public static void FindByRangeDate(DateTime start, DateTime end)
    {
        using (StreamReader sr = new(PATH_TO_FILE))
        {
            var data = sr.ReadToEnd();

            var datas = JsonSerializer.Deserialize<Data>(data);
            List<Data> datas1 = new();
            datas1.Add(datas);
        
            datas1.Where(d => d.date >= start && d.date <= end).ToList().ForEach(d => d.Print());
        }


    }
    public static void FindDate(DateTime date)
    {
        using (StreamReader sr = new(PATH_TO_FILE))
        {
            var data = sr.ReadToEnd();

            var datas = JsonSerializer.Deserialize<Data>(data);

            List<Data> datas1 = new();
            datas1.Add(datas);

            datas1.Where(x => x.date == date).ToList().ForEach(x => x.Print());


        }




    }
    #endregion
}
//созадть методы методами записи в текстовый файл, чтения, поиска нужной    информации.









class Data
{
    #region Property

    public string Name { get; set; }

    public DateTime date{ get; set; }
    public string NameClass { get; set; }

    #endregion

    #region Consructors
    public Data(string methodName  , string className)
    {
        Name = methodName ?? "undefined";
        NameClass = className ?? "undefined";
        date = DateTime.Now;
    }
    #endregion

    #region Methods 
      
    public void Print()
    {
        Console.WriteLine($"{Name} {date} {NameClass}");
    }
     
    #endregion
}
