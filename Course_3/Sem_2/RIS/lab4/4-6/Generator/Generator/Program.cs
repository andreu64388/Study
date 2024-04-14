﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace interleaving
{
    class Program
    {
        static void Main(string[] args)
        {
            int lenghtK = 15;
            int k = 6;
            int r = LenghtHemminga(k);
            int n = k + r;
            int lenghtN = lenghtK + (r * k);

            int[] masXk = new int[k];
            StrInMas(masXk, encodingMessage);
            int[] masG = new int[G.Length];
            StrInMas(masG, G);

            Console.WriteLine("Входная строка: " + message);
            Console.WriteLine($"Введенное сообщение в двоичном виде: {encodingMessage}");
            Console.WriteLine("Порождающий полином: " + G);
            Console.WriteLine($"k = {k}, r = {r}, n = {n}");

            int[,] generationMatrix = new int[k, n];
            CreateGenerationMatrix(generationMatrix, masG, k, n);
            Console.WriteLine("\nПорождающая матрица:");
            OutMatrix(generationMatrix, k, n);

            Console.WriteLine();
            Console.WriteLine("Сложение следующих строк:");
            CreateCanonicalMatrix(generationMatrix, k, n);
            Console.WriteLine("\nКаноническая матрица:");
            OutMatrix(generationMatrix, k, n);

            int[,] checkMatrix = new int[n, r];
            CreateCheckMatrix(checkMatrix, generationMatrix, k, n);
            Console.WriteLine("\nПроверочная матрица в канонической форме:");
            OutMatrixProv(checkMatrix, r, n);

            int[] masXn = new int[n];
            Shift(masXn, masXk, r);

            SearchResidue(masXn, masG);
            Console.WriteLine("\nОстаток:");
            OutMass(masXn);

            Console.WriteLine("Кодовое слово:");
            Shift(masXn, masXk, r);
            OutMass(masXn);
            //Находим количество проверочных символов
             static int HemingLenght(int k)
            {
                int r = (int)(Math.Log(k, 2) + 1.99f);
                return r;
            }


             static int[] SearchError(int[] masXn, int[] masG, int[,] checkMatrix, int r)
            {
                int n = masXn.Length;
                int k = n - r;

                int[] masXnSecond = new int[n];

                for (int i = 0; i < n; i++)
                {
                    masXnSecond[i] = masXn[i];
                }

                Console.WriteLine("\nДеление");
                SearchResidue(masXnSecond, masG);

                Console.WriteLine("\nОстаток:");
                OutMass(masXnSecond);

                for (int i = 0; i < n; i++)
                {
                    int coincidence = 0;
                    for (int j = 0; j < r; j++)
                    {
                        if (checkMatrix[i, j] == masXnSecond[k + j])
                        {
                            coincidence++;
                        }
                    }
                    if (coincidence == r)
                    {
                        masXn[i] = (masXn[i] + 1) % 2;
                        break;
                    }
                }
                //Console.WriteLine("");
                //Console.WriteLine("Синдром ошибки:");
                //Console.WriteLine("00000000000011001");
                //Console.WriteLine("Вектор ошибки:");
                //Console.WriteLine("10000000000000000");

                Console.WriteLine("\nИсправленная строка:");
                OutMass(masXn);
                return masXn;
            }


             static int[] SearchResidue(int[] masXn, int[] masXr)
            {
                int end = masXn.Length - masXr.Length + 1;

                for (int i = 0; i < end; i++)
                {
                    if (masXn[i] == 1)
                    {
                        AddingMasMod2(masXn, masXr, i);
                        OutMass(masXn);
                    }
                }
                return masXn;
            }
            //Сложение массивов по модулю 2 с опр. позиции
             static int[] AddingMasMod2(int[] mas1, int[] mas2, int pos)
            {
                int end = pos + mas2.Length;

                for (int i = pos; i < end; i++)
                {
                    mas1[i] = (mas1[i] + mas2[i - pos]) % 2;
                }
                return mas1;
            }


            //Смещение на массива r 
             static int[] Shift(int[] shiftMas, int[] mas, int r)
            {
                for (int i = 0; i < mas.Length; i++)
                {
                    shiftMas[i] = mas[i];
                }
                return shiftMas;
            }


            //Преобразование сторки в массив
             static int[] StrInMas(int[] mas, string str)
            {
                for (int i = 0; i < str.Length; i++)
                {
                    if (str[i] == 49)
                        mas[i] = 1;
                    else mas[i] = 0;
                }
                return mas;
            }


            //Создание Порождающей матрицы 
            static int[,] CreateGenerationMatrix(int[,] generationMatrix, int[] mas, int k, int n)
            {
                //Заполняем первую строку в проверочной матрице
                for (int i = 0; i < n; i++)
                {
                    if (i < mas.Length)
                    {
                        generationMatrix[0, i] = mas[i];
                    }
                    else
                    {
                        generationMatrix[0, i] = 0;
                    }
                }

                //Сдвигаем каждую строки вправо от предыдущей
                for (int i = 1; i < k; i++)
                {
                    for (int j = 0; j < n - 1; j++)
                    {
                        generationMatrix[i, j + 1] = generationMatrix[i - 1, j];
                    }
                    generationMatrix[i, 0] = generationMatrix[i - 1, n - 1];
                }
                return generationMatrix;
            }


            //Приведение порождающей матрицы к каноническому виду
            static int[,] CreateCanonicalMatrix(int[,] generationMatrix, int k, int n)
            {
                //Перебираем строки для преведения к каноническому виду
                for (int i = 0; i < k; i++)
                {
                    int i2 = i + 1;
                    //Перебираем элементы строки, но только до k-элемента
                    for (int j = i + 1; j < k; j++)
                    {
                        //если мы нашли единицу в строке, то...
                        if (generationMatrix[i, j] == 1)
                        {
                            //перебираем этот столбец, пока не найдем единицу
                            for (; i2 < k; i2++)
                            {
                                bool repeat = false;
                                //Если нашли, то складываем обе строки
                                if (generationMatrix[i2, j] == 1)
                                {
                                    for (int j2 = j - 1; j2 > 0; j2--)
                                    {
                                        //Проверяем, есть ли до этой 1 еще 1, если есть то эту строку пропускаем
                                        if (generationMatrix[i2, j2] == 1)
                                        {
                                            repeat = true;
                                        }
                                    }
                                    if (repeat)
                                        continue;
                                    AddingLinesMatrixMod2(generationMatrix, i, i2, n);
                                    i2++;
                                    break;
                                }
                            }
                        }
                    }
                }
                return generationMatrix;
            }


            //Преобразование канонической матрицы в проверочную
            static int[,] CreateCheckMatrix(int[,] checkMatrix, int[,] generationMatrix, int k, int n)
            {
                int r = n - k;

                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < r; j++)
                    {
                        checkMatrix[i, j] = generationMatrix[i, k + j];
                    }
                }

                for (int i = k; i < n; i++)
                {
                    for (int j = 0; j < r; j++)
                    {
                        if (j == i - k)
                        {
                            checkMatrix[i, j] = 1;
                        }
                        else
                        {
                            checkMatrix[i, j] = 0;
                        }
                    }
                }
                return checkMatrix;
            }


            //Сложение строк матрицы
             static int[,] AddingLinesMatrixMod2(int[,] matrix, int str1, int str2, int lengthString)
            {
                Console.WriteLine(str1 + " и " + str2);
                for (int i = 0; i < lengthString; i++)
                {
                    matrix[str1, i] = (matrix[str1, i] + matrix[str2, i]) % 2;
                }
                return matrix;
            }


            //вывод матрицы
             static void OutMatrix(int[,] matrix, int k, int n)
            {
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Console.Write(matrix[i, j]);
                    }
                    Console.WriteLine();
                }
            }


             static void OutMatrixProv(int[,] matrix, int k, int n)//////////////////////////////////
            {
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Console.Write(matrix[j, i]);
                    }
                    Console.WriteLine();
                }
            }


            //вывод одномерного массива
             static void OutMass(int[] mas)
            {
                for (int i = 0; i < mas.Length; i++)
                {
                    Console.Write(mas[i]);
                }
                Console.WriteLine("");
            }
        }
    }
}