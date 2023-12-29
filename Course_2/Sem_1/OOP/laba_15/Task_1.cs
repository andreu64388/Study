using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_15;
static class Task_1
{
    public static Task task1;

    public static void SieveOfEratosthenes()
    {
        int n = 1000;
        Console.WriteLine("Текущий ID таска: " + Task.CurrentId.ToString());

        var numbers = new List<uint>();

        // Заполнение списка numbers числами от 2 до n-1

        for (var i = 2u; i < n; i++)
        {
            numbers.Add(i);
        }

        for (var i = 0; i < numbers.Count; i++)
        {
            for (var j = 2u; j < n; j++)
            {
                numbers.Remove(numbers[i] * j);
            }
        }

        foreach (int a in numbers)
        {
            Console.WriteLine(a);
        }
    }

    //перемножение матриц
    public static void MatrixMultiplication(int[,] matrix1, int[,] matrix2)
    {
        int[,] matrix3 = new int[matrix1.GetLength(0), matrix2.GetLength(1)];
        for (int i = 0; i < matrix1.GetLength(0); i++)
        {
            for (int j = 0; j < matrix2.GetLength(1); j++)
            {
                for (int k = 0; k < matrix1.GetLength(1); k++)
                {
                    matrix3[i, j] += matrix1[i, k] * matrix2[k, j];
                }
            }
        }

    
        for (int i = 0; i < matrix3.GetLength(0); i++)
        {
            for (int j = 0; j < matrix3.GetLength(1); j++)
            {
                Console.Write(matrix3[i, j] + " ");
            }
            Console.WriteLine();
        }
    }

    /*Реализуйте второй вариант этой же задачи с токеном отмены 
CancellationToken и отмените задачу./*/

    public static void SieveOfEratosthenesWithCancel()
    {
        int n = 1000;
        Console.WriteLine("Текущий ID таска: " + Task.CurrentId.ToString());

        var numbers = new List<uint>();

        // Заполнение списка numbers числами от 2 до n-1

        for (var i = 2u; i < n; i++)
        {
            numbers.Add(i);
        }

        for (var i = 0; i < numbers.Count; i++)
        {
            for (var j = 2u; j < n; j++)
            {
                numbers.Remove(numbers[i] * j);
            }
        }

        foreach (int a in numbers)
        {
            Console.WriteLine(a);
        }
    }

}