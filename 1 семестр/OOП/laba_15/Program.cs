



using System.Collections.Concurrent;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;

namespace laba_15;
class Program
{


    public static void Main()
    {

        #region Task_1

        #region First
       
        Stopwatch watch = new();
        Task_1.task1 = new(() => Task_1.SieveOfEratosthenes());
        Task_1.task1.Start();
        watch.Start();
        Task_1.task1.Wait(); // ожидание завершения задачи 
        Task_1.task1.Dispose(); // Освобождение ресурсов
        watch.Stop();
        Console.WriteLine("Таск выполнен: " + Task_1.task1.IsCompleted.ToString());
        Console.WriteLine("Статус: " + Task_1.task1.Status.ToString());
        Console.WriteLine("Время выполнения для таска: " + watch.Elapsed);
        
        #endregion

        #region Second

        int[,] matrix1 = new int[3, 3] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int[,] matrix2 = new int[3, 3] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        
        Task_1.task1 = new (() => Task_1.MatrixMultiplication(matrix1, matrix2));
        Task_1.task1.Start();
        Task_1.task1.Wait();
        Task_1.task1.Dispose();
        Console.WriteLine("Таск выполнен: " + Task_1.task1.IsCompleted.ToString());
        Console.WriteLine("Статус: " + Task_1.task1.Status.ToString());

        #endregion


        #endregion


        Console.WriteLine("\n\n-------------------2------------------------\n\n");
        #region Task_2

        CancellationTokenSource token = new ();
        (Task_1.task1 = new Task(() => Task_1.SieveOfEratosthenes()
            ,token.Token)).Start();
        token.Cancel();
        Console.WriteLine("Токен отмены сработал!");


        #endregion

        Console.WriteLine("\n\n-------------------3------------------------\n\n");
        #region Task_3


        Task<int> rand1 = new Task<int>(Task_3.RandomFor10), // создание задачи с возвращаемым значением
                  rand2 = new Task<int>(Task_3.RandomFor20),
                  rand3 = new Task<int>(Task_3.RandomFor30);

        rand1.Start();
        Console.WriteLine("First Value: " + rand1.Result);

        rand2.Start();
        Console.WriteLine("Second Value: " + rand2.Result);

        rand3.Start();
        Console.WriteLine("Third Value: " + rand3.Result);

        Task<int> avg = new Task<int>(() => Task_3.AverageValue(rand1.Result, rand2.Result, rand3.Result));
        avg.Start();

        Console.WriteLine("Average: " + avg.Result);


        #endregion

        Console.WriteLine("\n\n-------------------4------------------------\n\n");
        #region Task_4

        
        Console.WriteLine("Таск продолжения: ");
        Task<int> contTask1 = new Task<int>(Task_3.RandomFor10);
        
        Task<int> contTask2 = contTask1.ContinueWith((task) => Task_3.RandomFor20());
        Task<int> contTask3 = contTask2.ContinueWith((task) => Task_3.RandomFor30());
        Task<int> contTask4 = contTask3.ContinueWith((task) => Task_3.AverageValue(contTask1.Result, contTask2.Result, contTask3.Result));
        contTask1.Start();
        //ContinueWith 

        Console.WriteLine($"Первое значение:  {contTask1.Result}\n" +
                          $"Второе значение: {contTask2.Result}\n" +
                          $"Третье значение: {contTask3.Result}\n" +
                          $"Среднее значение: {contTask4.Result}\n");
        
     

        contTask1.Dispose();
        contTask2.Dispose();
        contTask3.Dispose();
        contTask4.Dispose();

        Console.WriteLine("Ожидающий");
        Task<int> wait = Task.Run(() => Enumerable.Range(1, 100000).Count(n => (n % 2 == 0)));
        wait.GetAwaiter().GetResult();
        Console.WriteLine(wait.Result);
        #endregion

        Console.WriteLine("\n\n-------------------5------------------------\n\n");
        #region Task_5


        Stopwatch stW = new();
        int[] arr1 = new int[10000000];
        int[] arr2 = new int[10000000];
        Random random = new Random();
        stW.Start(); // запуск таймера

        for (int i = 0; i < arr1.Length; i++)
        {
            arr1[i] = random.Next(0, 100);
            arr2[i] = random.Next(0, 100);
        }
        stW.Stop();

        Console.WriteLine("For: " + stW.Elapsed);
        stW.Restart();

        Parallel.For(0, arr1.Length, i =>
        {
            arr1[i] = random.Next(0, 100);
            arr2[i] = random.Next(0, 100);
        });
        stW.Stop();

        Console.WriteLine("Параллельный for: " + stW.Elapsed);
        stW.Restart();

        Parallel.ForEach<int>(arr1, i => 
        {
            arr1[i] = random.Next(0, 300);
            arr2[i] = random.Next(0, 300);
        });
        stW.Stop();

        Console.WriteLine("Параллельный foreach: " + stW.Elapsed);

        #endregion

        Console.WriteLine("\n\n-------------------6------------------------\n\n");
        #region Task_6

        Parallel.Invoke(() =>
        {
            for (int i = 0; i < 10; i++)
            {
              Console.WriteLine("Параллельное выполнение блока 1 - " + i);
            }

            Console.WriteLine("1 готов!");
        },
           () =>
           {
               for (int i = 0; i < 10; i++)
               {
                   Console.WriteLine("Параллельное выполнение 2 - " + i);
               }

               Console.WriteLine("2 готов!");
           });

        #endregion

        Console.WriteLine("\n\n-------------------7------------------------\n\n");
        
        #region Task_7

        Task_7.MyBlock = new BlockingCollection<string>(5);
        Task Shop = new Task(Task_7.AddProduct);
        Task Clients = new Task(Task_7.PurchasedProduct);
        Shop.Start();
        Clients.Start();
        Shop.Wait();
        Clients.Wait();

        #endregion

        Console.WriteLine("\n\n-------------------8------------------------\n\n");
        #region Task_8

        Task_8.Async();
        string p = Console.ReadLine();
        Console.WriteLine(p + p + p + "Нажмите, чтобы закончить работу...");
      
        #endregion

    }

}

/*1. Что такое TPL? Как и для чего используется тип Task
2. Почему эффект от распараллеливания наблюдается на большом 
количестве элементов?
3. В чем основные достоинства работы с задачами по сравнению с 
потокми?
4. Приведите три способа создания и/или запуска Task?
5. Как и для чего используют методы Wait(), WaitAll() и WaitAny()?
6. Приведите пример синхронного запуска Task?
7. Как создать задачу с возвратом результата?
8. Как обработать исключение, если оно произошло при выполнении 
Task?
9. Что такое CancellationToken и как с его помощью отменить 
выполнение задач?
10.Как организовать задачу продолжения (continuation task) ?
11.Как и для чего используется объект ожидания при создании задач 
продолжения?
12.Поясните назначение класса System.Threading.Tasks.Parallel?
13.Приведите пример задачи с Parallel.For(int, int, Action<int>)
14.Приведите пример задачи с Parallel.ForEach
15.Приведите пример с Parallel.Invoke()
16.Как с использованием CancellationToken отменить параллельные 
операции?
17.Для чего используют BlockingCollection<T>, в чем ее особенность?
18.Как используя async и await организовать асинхронное выполенение 
метода*/

//1  Что такое TPL? Как и для чего используется тип Task 
//TPL - Task Parallel Library - библиотека для параллельного выполнения задач.
//Task - это класс, который позволяет выполнять задачи параллельно, а также возвращать результаты.

//2  Почему эффект от распараллеливания наблюдается на большом 
//количестве элементов?
//Потому что при малом количестве элементов, время выполнения задачи меньше, чем время создания потока.

//3  В чем основные достоинства работы с задачами по сравнению с
//потокми?
//Потоки создаются дороже, чем задачи. Потоки требуют больше ресурсов, чем задачи. Потоки могут быть созданы только в рамках одного процесса, а задачи могут быть созданы в рамках нескольких процессов.

//4  Приведите три способа создания и/или запуска Task?
//Task.Run(Action);
//Task.Factory.StartNew(Action);
//new Task(Action).Start();

//5   Как и для чего используют методы Wait(), WaitAll() и WaitAny()? 
//Wait() - ожидает завершения задачи.
//WaitAll() - ожидает завершения всех задач.
//WaitAny() - ожидает завершения любой задачи.

//6. Приведите пример синхронного запуска Task?
//Task task = Task.Run(() => { Console.WriteLine("Hello"); });
//task.Wait();


//7. Как создать задачу с возвратом результата? 
//Task<int> task = Task.Run(() => { return 42; });

/*8. Как обработать исключение, если оно произошло при выполнении 
Task?*/
//Task task = Task.Run(() => { throw new Exception(); });
//try
//{
//    task.Wait();
//}
//catch (AggregateException ex)
//{
//    Console.WriteLine(ex.InnerException.Message);

//}

/*9. Что такое CancellationToken и как с его помощью отменить 
выполнение задач?*/
//CancellationToken - это токен, который используется для отмены задачи.
//CancellationTokenSource - это источник токена, который используется для создания токена.
//CancellationTokenSource cts = new CancellationTokenSource();
//Task task = Task.Run(() => { while (true) { } }, cts.Token);
//cts.Cancel();

//10.Как организовать задачу продолжения (continuation task) ?
//Task task = Task.Run(() => { Console.WriteLine("Hello"); });
//Task task2 = task.ContinueWith((prevTask) => { Console.WriteLine("World"); });

/*11.Как и для чего используется объект ожидания при создании задач 
продолжения?*/
//Task task = Task.Run(() => { Console.WriteLine("Hello"); });  
//Task task2 = task.ContinueWith((prevTask) => { Console.WriteLine("World"); }, TaskContinuationOptions.OnlyOnRanToCompletion);
//Используется для того, чтобы задача продолжения выполнялась только в случае, если предыдущая задача завершилась успешно.

//12.Поясните назначение класса System.Threading.Tasks.Parallel?
//Класс System.Threading.Tasks.Parallel предоставляет методы для параллельного выполнения операций.

//13.Приведите пример задачи с Parallel.For(int, int, Action<int>)
//Parallel.For(0, 10, i => { Console.WriteLine(i); });
//Это пример параллельного цикла. 

//14.Приведите пример задачи с Parallel.ForEach
//Parallel.ForEach(new int[] { 1, 2, 3, 4, 5 }, i => { Console.WriteLine(i); });
//Это пример параллельного цикла.


//15.Приведите пример с Parallel.Invoke()
//Parallel.Invoke(() => { Console.WriteLine("Hello"); }, () => { Console.WriteLine("World"); });
//Это пример параллельного выполнения методов.


//16.Как с использованием CancellationToken отменить параллельные
//операции?
//CancellationTokenSource cts = new CancellationTokenSource();
//ParallelOptions po = new ParallelOptions();
//po.CancellationToken = cts.Token;
//Parallel.For(0, 10, po, i => { Console.WriteLine(i); });
//cts.Cancel();

//17.Для чего используют BlockingCollection<T>, в чем ее особенность?
//BlockingCollection<T> - это коллекция, которая блокирует поток, пока не будет добавлен элемент в коллекцию.
//BlockingCollection<int> bc = new BlockingCollection<int>();
//Task.Run(() => { bc.Add(1); });
//Console.WriteLine(bc.Take());


//18.Как используя async и await организовать асинхронное выполенение
//метода
//public async Task<string> GetPageAsync(string url)
//{
//    HttpClient client = new HttpClient();
//    return await client.GetStringAsync(url);
//}
    