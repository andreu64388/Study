
namespace laba_6;


/*
Создайте класс Logger, который будет заниматься логгированием
различных событий и исключений.Логгер должен уметь логгировать
ошибки/исключения, предупреждения и просто какую-то информацию.*/
 class Logger
{
    #region Fields
    private string PathS = "log.txt";

    private DateTime Datas;


    private string Message;


    #endregion
    #region Constructors
    public Logger()
    {
           this.Datas = DateTime.Now;
    }
    #endregion
    #region Methods
    public void LogWrite(string message)
    {   
        using StreamWriter sw = new StreamWriter(PathS, true);
        {
            Message = message;
            sw.WriteLine($"{Datas} {Message}");
        } 
        
        
    }
    public void LogRead()
    {
        using StreamReader sr = new StreamReader(PathS);
        {
            Console.WriteLine(sr.ReadToEnd());
        }
    }
    public void WriteError(string MessageError)
    {

        using StreamWriter sw = new StreamWriter(PathS, true);
        {
            sw.WriteLine($"{Datas} {MessageError}");
        }


    }
    #endregion


}
