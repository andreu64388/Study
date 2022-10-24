using System;

namespace laba;
class Program
{ 
    static void Main  ()
    {
        /*    Определите две локальные функции. Разместите в одной из них блок checked, в котором определите
           переменную типа int с максимальным возможным значением
           этого типа.Во второй функции определите блок unchecked с
           таким же содержимым.*/

        
        void CheckedFunc()
        {
            checked
            {
                int Max = int.MaxValue; 
                Console.WriteLine(Max+1);
            }
        }
        void Unchecked()
        {
            unchecked
            {
                int Max = int.MaxValue;
                Console.WriteLine(Max+1);
            }
        }
        CheckedFunc();
          Unchecked();


        /*
        Формальные параметры функции – массив
целых и строка. Функция должна вернуть кортеж, содержащий:
максимальный и минимальный элементы массива, сумму элементов
массива и первую букву строки*/
        (int, int, int,char) func(int[] a, string s)
        {
            int max = a[0];
            int min = a[0];
            int sum = 0;
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] > max)
                    max = a[i];
                if (a[i] < min)
                    min = a[i];
                sum += a[i];
            }
            // return (max.Max(), min.Min(), sum.Sum(), s[0]);
            return (max, min, sum, s[0]);
        }
        int[] a = { 1, 2, 3, 4, 5 };
        string s = "Hello";
        var (max, min, sum, first) = func(a, s);
       /* Console.WriteLine($"max={max}, min={min}, sum={sum}, first={first}");*/
    }
   
   







}