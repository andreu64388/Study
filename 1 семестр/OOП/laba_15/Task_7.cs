using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_15;


   static class Task_7
    {
        public static BlockingCollection<string> MyBlock;
        public static void AddProduct()
        {
            Random r = new Random();
            int x;
            List<string> products = new List<string>() { "Ёлка", "Гирлянда", "Шоколадка", "Шампанское", "Мандарины" };
            for (int i = 0; i < 5; i++)
            {
                x = r.Next(0, products.Count - 1);
                Console.WriteLine("Добавлен товар: " + products[x]);
                MyBlock.Add(products[x]); 
                products.RemoveAt(x);
           
            
        }
        MyBlock.CompleteAdding(); // сообщаем, что больше не будет добавляться элементов
    }
        public static void PurchasedProduct() 
        {
            string str;
            while (MyBlock.IsAddingCompleted == false)
    
    
        {
            if (MyBlock.TryTake(out str) == true)
                    Console.WriteLine("Был куплен товар: " + str);
                if (MyBlock.TryTake(out str) != true)
                    Console.WriteLine("Покупатель ушел.");
            }
        }
    
}