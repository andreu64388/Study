using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba
{
    static class Array
    {

        static public void PrintArrayTwo()
        {
            /*Создайте целый двумерный массив и выведите его на консоль в
отформатированном виде (матрица)
            
            */
            //возвращает индекс последнего элемента
            int[,] array = new [,] {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 } };
            // вывести массив в виде матрицы 

            int rows = array.GetLength(0); // количество строк
            int columns = array.GetLength(1); // количество столбцов
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    Console.Write(array[i, j]);
                }
                Console.WriteLine();
            }


        }
        static public void PrintConsole()
        {
            /*Создайте одномерный массив строк. Выведите на консоль его
содержимое, длину массива. Поменяйте произвольный элемент
(пользователь определяет позицию и значение).*/
            string[] array = new string[] { "one", "two", "three", "four", "five" };
            Console.WriteLine("Массив:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i]);
            }
            Console.WriteLine();
            Console.WriteLine("Длина массива: {0}", array.Length);
            Console.WriteLine("Введите номер элемента массива:");
            int index = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите новое значение элемента массива:");
            string value = Console.ReadLine();
            array[index] = value;
            Console.WriteLine("Массив после изменения:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write("{0} ", array[i]);
            }


        }
        //вопрос
        static public void PrintStepwise()
        {
            /*Создайте ступечатый (не выровненный) массив вещественных
чисел с 3-мя строками, в каждой из которых 2, 3 и 4 столбцов
соответстве'нно. Значения массива введите с консоли cтупенчатй массив*/
            double[][] arrays = new double[3][];
            arrays[0] = new double[2];
            arrays[1] = new double[3];
            arrays[2] = new double[4];

            for (int i = 0; i < arrays.Length; i++)
            {
                for (int j = 0; j < arrays[i].Length; j++)
                {
                    Console.WriteLine("Введите значение элемента массива {0}:{1}", i, j);
                    arrays[i][j] = double.Parse(Console.ReadLine());
                }
            }





        }
        static public void PrintiImplicitly()
        {
            //Создайте неявно типизированные переменные для хранения  массива и строки в одномерном массиве.

            var array = new[] { 1, 2, 3, 4, 5 };
            var str = "Hello";
            Console.WriteLine("Массив:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write("{0} ", array[i]);
            }
            Console.WriteLine();
            Console.WriteLine("Строка:");
            for (int i = 0; i < str.Length; i++)
            {
                Console.Write(str[i]);
            }
             
           

        }
    }
}
