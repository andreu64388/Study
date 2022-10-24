using System;


namespace Control_work_1;

class Program
{
    static void Main(string[] args)
    {
        //Вариант 5


        #region Первое задание

        string str = "123";
        string str1 = "123456";

        if (str1.Contains(str))
        {
            Console.WriteLine("Строка содержит число 123");
        }
        else
        {
            Console.WriteLine("Строка не содержит число 123");
        }

        double[] arr = new double[10];
        Random rnd = new Random();
        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = rnd.Next(0, 100);
        }
       
        for (int i = 0; i < arr.Length; i++)
        {
            Console.WriteLine(arr[i]);
        }
        #endregion



        Console.WriteLine("---------------------------------");

        Date date = new Date(1, 2, 3);
        Date date1 = new Date(1, 2, 3);

      if(date.Equals(date1))
        {
            Console.WriteLine("Равны");
        }
        else
        {
            Console.WriteLine("Не равны");
        }

        Console.WriteLine(date % 3);
        Console.WriteLine(date % 2);


        Console.WriteLine("---------------------------------");
        BelDate bel = new(1, 2, 4, "good");

        ((IGood)bel).Plus();
        ((IBad)bel).Plus();


        Console.WriteLine(bel);
        Console.WriteLine("---------------------------------");

    }
}




