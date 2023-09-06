using System;




namespace laba_7;

class Program
{

    static void Main()
    {
        //Добавьте обработку исключений c finally. Наложите какое-либо  ограничение на обобщение


        try
        {
            //Создайте массив объектов Person и отсортируйте его по возрасту
            var stack = new Stack<Person>(3);
            stack.Push(new Person("Ivan", "Ivanov", 20));
            stack.Push(new Person("Petr", "Petrov", 30));
            stack.Push(new Person("Sidor", "Sidorov", 40));
            stack.PushToFile();

            Stack<int> stack1 = new(3);
            stack1.Push(5);
            stack1.Push(2);
            stack1.Push(6);

            stack1.Sort();
   

            Console.WriteLine("\n\n----------------------------------\n\n");

            stack.Sort();
          
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }
        finally
        {
            Console.WriteLine("Finally");
        }


    }
}