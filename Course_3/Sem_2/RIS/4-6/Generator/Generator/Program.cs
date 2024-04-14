using DatabaseClasses.Pattern;
using Models;
using System;
using System.Threading;
using System.Threading.Tasks;

namespace Generator
{
    class Program
    {
        static void Main(string[] args)
        {
            //Лабораторная 5------------------------------------------
            Console.WriteLine("Начало работы: генератор данных");
            GenerateForFirstClient();
            GenerateForSecondClient();
            //--------------------------------------------------------
            while (true)
            {

            }
        }

        async public static void GenerateForFirstClient()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    Console.WriteLine("Генерация данных для первого клиента...");
                    using (UnitOfWork unitOfWork = new UnitOfWork("FirstDBConnect"))
                    {
                        Console.WriteLine("Отправка сгенерированных данных в бд первого клиента...");
                        DateTime time = DateTime.Now;
                        Data forInsert = new Data { CreatorNumber = 1, Time = time.ToString() };
                        unitOfWork.DataRepository.AddItem(forInsert);
                        unitOfWork.Save();
                    }

                    Thread.Sleep(5000);
                }
            });
        }

        async public static void GenerateForSecondClient()
        {
            await Task.Run(() =>
            {
                while (true)
                {
                    Console.WriteLine("Генерация данных для второго клиента...");
                    using (UnitOfWork unitOfWork = new UnitOfWork("SecondDBConnect"))
                    {
                        Console.WriteLine("Отправка сгенерированных данных в бд второго клиента...");
                        DateTime time = DateTime.Now;
                        Data forInsert = new Data { CreatorNumber = 2, Time = time.ToString() };
                        unitOfWork.DataRepository.AddItem(forInsert);
                        unitOfWork.Save();
                    }

                    Thread.Sleep(5000);
                }


            });
        }
    }
}
