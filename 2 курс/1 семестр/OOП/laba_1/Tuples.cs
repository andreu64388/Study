using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba;

static class Tuples
{
    static public void PrintTuples() {
        /*
          Задайте кортеж из 5 элементов с типами int, string, char, string,ulong.
         */
        var tuple = (1, "two", '3', "four", 5ul);
       
        //Выведите кортеж на консоль целиком и выборочно ( например 1,  3, 4 элементы)
        Console.WriteLine(tuple);
        Console.WriteLine(tuple.Item1);
        Console.WriteLine(tuple.Item3);
        Console.WriteLine(tuple.Item4);

        //Выполните распаковку кортежа в переменные
        var (a, b, c, d, e) = tuple;
        Console.WriteLine(a);
        Console.WriteLine(b);
        Console.WriteLine(c);
        //Продемонстрируйте различные способы распаковки кортежа. Продемонстрируйте использование переменной(_). 
        var (f, _, _, _, _) = tuple;
        Console.WriteLine(f);
        
            


        //Сравните два кортежа.

        var tuple2 = (1, "two", '3', "four", 5ul);
        Console.WriteLine(tuple == tuple2);
        


    }
}
