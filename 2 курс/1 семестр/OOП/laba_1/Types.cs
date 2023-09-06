using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba;

static class Types

{
    public static void PrintTypes()
    { /*
Определите переменные всех возможных примитивных типов
С# и проинициализируйте их. Осуществите ввод и вывод их
значений используя консоль. */
   
        // Целочисленные типы данных
        // byte
        byte a = 255;
        Console.WriteLine("byte a = " + a);
        //  sbyte
        sbyte b = -128;
        Console.WriteLine("sbyte b = " + b);
        // short
        short c = -32768;
        Console.WriteLine("short c = " + c);
        //  ushort
        ushort d = 65535;
        Console.WriteLine("ushort d = " + d);
        // int
        int e = -2147483648;
        Console.WriteLine("int e = " + e);
        // uint
        uint f = 4294967295;
        Console.WriteLine("uint f = " + f);
        //  long
        long g = -9223372036854775808;
        Console.WriteLine("long g = " + g);
        //  ulong
        ulong h = 18446744073709551615;
        Console.WriteLine("ulong h = " + h);
        //  Числа с плавающей точкой
        //  float
        float i = 3.402F;
        Console.WriteLine("float i = " + i);
        //  double
        double j = 1.797693d;
        Console.WriteLine("double j = " + j);
        //  decimal
        decimal k = 1005.8M;
        Console.WriteLine("decimal k = " + k);
        //  Символьный тип данных
        //  char
        char l = 'A';
        Console.WriteLine("char l = " + l);
        //  Логический тип данных
        //  bool
        bool m = true;
        Console.WriteLine("bool m = " + m);
        //  Строковый тип данных
        //  string
        Console.WriteLine("Enter the name");
        string name = Console.ReadLine();
    
        Console.WriteLine($"Hello, {name}!");

    }
    public static void PrintOperation()
        
    {
        //Выполните 5 операций явного и 5 неявного приведения  типов данных


        //явное приведение типов
        int numberFirst = 5;
        int numberSecond = 10;
        byte numberThird = (byte)(numberFirst + numberSecond);
        Console.WriteLine("numberThird = " + numberThird);


        char symbolFirst = 'A';
        string symbolSecond = symbolFirst.ToString();
        Console.WriteLine(symbolSecond);

        string name = "21";
        int age = Convert.ToInt32(name);


        double numberDouble = 5.5d;
        float numberfloat = (float)numberDouble;


        string numberString = "5";
        int numberInt = int.Parse(numberString);


        // неявное приведение типов
        byte b = 5;
        short s = b;
        int i = b;
        long l = b;
        float f = b;
        Console.WriteLine($"{b}-{b.GetType()},{s}-{s.GetType()},{i}-{i.GetType()} " );

    }
    public static void PrintUnpacking()
    {
        //Выполните упаковку и распаковку значимых типов
        //Упаковка значимых типов
        int number = 5;
        object obj = number;
        Console.WriteLine(obj);
            
        //Распаковка значимых типов
        object obj2 = 5;
        int number2 = (int)obj2;
        Console.WriteLine(number2);        

    }
    public static void PrintImplicit()
    {
        // Продемонстрируйте работу с неявно типизированнойпеременной.

        var number = 5;
        Console.WriteLine($"number = {number} - {number.GetType()}");
        var name = "Vasya";
        Console.WriteLine($"name = {name} - {name.GetType()}");
        var symbol = 'A';
        Console.WriteLine($"symbol = {symbol} - {symbol.GetType()}");
        var numberDouble = 5.5d;
        Console.WriteLine($"numberDouble = {numberDouble} - {numberDouble.GetType()}");
        var numberFloat = 5.5f;
        Console.WriteLine($"numberFloat = {numberFloat} - {numberFloat.GetType()}");

    }
    public static void PrintNullable()
    {
        //Продемонстрируйте работу с Nullable переменной.

        int? number = null;
        Console.WriteLine(number);
        number = 5;
        Console.WriteLine(number);
        // 
        Console.WriteLine(number.HasValue);
        Console.WriteLine(number.Value);


    }
    public static void PrintVar()
    {
        /*
    Определите переменную типа var и присвойте ей любое
    значение. Затем следующей инструкцией присвойте ей значение
    другого типа. Объясните причину ошибки.
             */
        var number = 5;
       // number = "five";
       
    }
}
