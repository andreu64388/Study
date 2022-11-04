

namespace laba_11;

/*Добавьте в Reflector обобщенный метод Create, который создает объект
переданного типа (на основе имеющихся публичных конструкторов) и возвращает
его пользователю*/

static class Reflector
{
    public static T Create<T>()
    {
        return (T)Activator.CreateInstance(typeof(T));
    }
    
}

class Test: ITest
{
    #region Property

    public string Name { get; set; }

    public int Age { get; set; }


    #endregion


    #region Constructor

    public Test()
    {
        Name = "Default";
        Age = 0;
    }

    public Test(string name, int age)
    {
        Name = name;
        Age = age;
    }

    #endregion

    #region Method

    public void Print()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }

    #endregion

}
interface ITest
{ 
    void Print();
}