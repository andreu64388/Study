
using System.Diagnostics;

namespace laba_6;

class User
{
    


    #region Fields
    private string _name = "Not name";
    private int age;
    private const int MAX_LENGHT = 10;
    #endregion


    #region Properties
    public string Name
    {
        get { return _name; }
        set { _name = value; }
    }

    public int Age
    {
        get { return age; }
        set { age = value; }
    }
    #endregion


    #region Methods 


   
    public void CreateUser()
    {
        this.Name = AddName();
        this.Age = AddAge();
    }
    private string AddName()
    {

        Console.WriteLine("Enter your name");
        string name = Console.ReadLine();
        if (name.Length > MAX_LENGHT || name.Length < 1)
        {
            throw new Exceptions("Name is too long or too short");
        }
        if (name == null)
        {
            throw new Exceptions("Name is null");
        }
        return name;
    }
    private int AddAge()
    {

       
        Console.WriteLine("Enter your age");
        int age;
        string ageS = Console.ReadLine() ?? "Error";

        if (int.TryParse(ageS, out age))
        {
            if (age < 0 || age > 100)
            {
                throw new Exceptions("Age is too big or too small");
            }

        }
        else
        {
            throw new Exception("It is not number");
        }
        if (ageS == "Error")
        {
            throw new Exceptions("Age is null");
        }

        return age;

    }

      public void AssertTest()
      {


              Debug.Assert(Name != null, "Name is null");
              Debug.Assert(Age < 0, "Age is null");
              Debug.Assert(Age > 100, "Age is too big");
              Debug.Assert(Name.Length < MAX_LENGHT, "Name is too long");
              Debug.Assert(Name.Length < 0, "Name is too short");

      }
    
    public override string ToString()
    {
        return $"Name: {Name}, Age: {Age}";
    }
  #endregion

}




/* Добавьте код в одной из функций макрос Assert. Объясните что он
проверяет, как будет выполняться программа в случае не выполнения
условия. Объясните назначение Assert*/


// что такое макрос Assert?
// как он работает?







//Отличие Parse от TryParse
//Parse - преобразует строку в число, если строка не является числом, то выдает исключение
// TryParse - преобразует строку в число, если строка не является числом, то возвращает false

//как в vs автоматически отформатировать код в vs 2022


// нужно скачать плагин CodeMaid
