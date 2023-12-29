
/*1. Задайте массив типа string, содержащий 12 месяцев (June, July, May,
December, January ….). Используя LINQ to Object напишите запрос выбирающий
последовательность месяцев с длиной строки равной n, запрос возвращающий
только летние и зимние месяцы, запрос вывода месяцев в алфавитном порядке,
запрос считающий месяцы содержащие букву «u» и длиной имени не менее 4-х..
         */

namespace laba_10;

class Program
{   static void Main(string[] args)
    {
        #region Ex First
 
        string[] months = { "June", "July", "May", "December", "January", "February", "March", "April", "August", "September", "October", "November" };

        //с заданной длиной строки
        var query = from m in months
                    where m.Length == 4
                    select m;

        // летние и зимние месяцы
        var query2 = from item in months
                    where item == "June" || item == "July" || item == "August" || item == "December" || item == "January" || item == "February"
                    select item;

        //в алфавитном порядке
        var query3 = from item in months
                     orderby item
                     select item;

        //число букв не менее 4-х
        var query4 = from item in months
                     where  item.Length <= 4
                     select item;


        Console.WriteLine("------------1-------------");
        Console.WriteLine("С заданной длиной строки");
        foreach (var item in query)
            Console.WriteLine(item);
        
        Console.WriteLine("\n----------------------\n");

        Console.WriteLine("Летние и зимние месяцы");

        foreach (var item in query2)
            Console.WriteLine(item);
        
        Console.WriteLine("\n----------------------\n");

        Console.WriteLine("В алфавитном порядке");

        foreach (var item in query3)
            Console.WriteLine(item);

    
        Console.WriteLine("\n----------------------\n");


        Console.WriteLine("Число букв не менее 4-х");


        foreach (var item in query4)
            Console.WriteLine(item);


        #endregion

        #region Ex Second
        /*Создайте коллекцию List<T> и параметризируйте ее типом (классом)
из лабораторной №2 (при необходимости реализуйте нужные интерфейсы).
Заполните ее минимум 10 элементами.
Если в задании указано свойство, которым ваш класс не обладает, то его
нужно расширить, чтобы класс соответствовал условию. Один из запросов
реализуйте используя язык LINQ и используя методы расширения LINQ.*/
       
        List<Airplane> airplanes = new List<Airplane>();
        airplanes.Add(new Airplane(1, "Minsk", 123, "Boeing 737", "12:00", "Monday"));
        airplanes.Add(new Airplane(2, "Moscow", 124, "Boeing 737", "12:00", "Monday"));
        airplanes.Add(new Airplane(3, "St.Petersburg", 125, "Boeing 737", "12:00", "Monday"));
        airplanes.Add(new Airplane(4, "Kiev", 126, "Boeing 737", "12:00", "Monday"));
        airplanes.Add(new Airplane(5, "Minsk", 127, "Boeing 737", "14:00", "Monday"));
        airplanes.Add(new Airplane(6, "Minsk", 128, "Boeing 737", "16:00", "Monday"));
        airplanes.Add(new Airplane(7, "Minsk", 129, "Boeing 737", "18:00", "Monday"));
        airplanes.Add(new Airplane(8, "Minsk", 130, "Boeing 737", "20:00", "Monday"));
        airplanes.Add(new Airplane(9, "Minsk", 131, "Boeing 737", "22:00", "Monday"));
        airplanes.Add(new Airplane(10, "Minsk", 132, "Boeing 737", "00:00", "Monday"));



        var query_2 = from item in airplanes
                    where item.Destination == "Minsk"
                    select item;

        var query_3 = from item in airplanes
                      where item.DaysOfWeek == "Monday"
                      select item;
     
        var query_4 = from item in airplanes
                      orderby item.DaysOfWeek, item.DepartureTime
                      select item;

        Console.WriteLine("-----------------2-----------------");

        Console.WriteLine("Пункт назначения: Minsk");

        foreach (var item in query_2)
            Console.WriteLine(item);

        Console.WriteLine("\n----------------------\n");

        Console.WriteLine("Дни недели: Monday");

        foreach (var item in query_3)
            Console.WriteLine(item);

        Console.WriteLine("\n----------------------\n");

        Console.WriteLine("Дни недели: Monday, Время вылета: 12:00");

        foreach (var item in query_4)
            Console.WriteLine(item);










        #endregion

        #region EX Third
        List<Airplane> airplanes2 = new List<Airplane>();
        airplanes2.Add(new Airplane(1, "Minsk", 123, "Boeing 737", "12:00", "Monday"));
        airplanes2.Add(new Airplane(2, "Moscow", 124, "Boeing 737", "12:00", "Monday"));

        /*Придумайте и напишите свой собственный запрос, в котором было
бы не менее 5 операторов из разных категорий: условия, проекций, */
        var query_5 = from item in airplanes
                      where item.Destination == "Minsk" && item.DaysOfWeek == "Monday"
                      select item;
  
        
    var results = airplanes.Where(x => x.Destination == "Minsk" && x.DaysOfWeek == "Monday").ToList();
        


        var query_6 = from item in airplanes
                      where item.Destination == "Minsk" && item.DaysOfWeek == "Monday"
                      orderby item.DaysOfWeek, item.DepartureTime
                      select item;
        


        var query_7 = from item in airplanes
                      group item by item.Destination;

        var result_7 = airplanes.GroupBy(x => x.Destination).ToList();


        var query_8 = from item in airplanes
                      group item by item.Destination into g
                      select new { Destination = g.Key, Count = g.Count() };

        var result_8 = airplanes.GroupBy(x => x.Destination).Select(x => new { Destination = x.Key, Count = x.Count() }).ToList();

        var query_9 = from item in airplanes
                      join item2 in airplanes2 on item.Destination equals item2.Destination
                      select item;


        var result_9 = airplanes.Join(airplanes2, x => x.Destination, x => x.Destination, (x, y) => x).ToList();



        Console.WriteLine("-----------------3-----------------");
        foreach (var item in query_5)
            Console.WriteLine(item);

        Console.WriteLine("\n----------------------\n");

        foreach (var item in query_6)
            Console.WriteLine(item);

        Console.WriteLine("\n----------7-----------\n");

        foreach (var item in query_7)
        {
            Console.WriteLine(item.Key);
            foreach (var item2 in item)
                Console.WriteLine(item2);
        }

        Console.WriteLine("\n----------------------\n");

        foreach (var item in query_8)
            Console.WriteLine(item);

        Console.WriteLine("\n----------------------\n");

        foreach (var item in query_9)
            Console.WriteLine(item);


        Console.WriteLine("-------------------------");
        foreach (var item in results)
            Console.WriteLine(item);

        #endregion
    }
}


/*1. Что такое LINQ?
2. В чем разница между отложенными операциями и не отложенными
операциями LINQ to Object?
3. Что такое лямбда-выражения?
4. Какие есть группы операции в LINQ to Object? Перечислите
5. Как используется операция Where в LINQ to Object?
6. Как используется операция Select ?
7. Как используются операции Take, Skip?
8. Как используется операция Concat ?
9. Как используется операция OrderBy?
10.Как используется операция Join?
11.Как используются операции Distinct, Union, Except и Intersect?
12. Как используются операции First, Last, Any, All и Contains?
13. Как используются операции Count, Sum, Min и Max, Average?*/

//1. Что такое LINQ?
//LINQ - язык запросов, который позволяет выполнять запросы к данным, хранящимся в различных источниках данных, таких как массивы, XML-документы, базы данных и т.д.

//2. В чем разница между отложенными операциями и не отложенными операциями LINQ to Object?
//Отложенные операции выполняются только при обращении к результату запроса. Не отложенные операции выполняются сразу же при вызове метода.

//3. Что такое лямбда-выражения?
//Лямбда-выражения - это анонимные методы, которые позволяют передавать код в качестве параметра.

//4. Какие есть группы операции в LINQ to Object? Перечислите
//Операции фильтрации, операции проекции, операции сортировки, операции группировки, операции соединения, операции объединения, операции разности, операции ограничения, операции агрегирования.

//5. Как используется операция Where в LINQ to Object?
//Операция Where используется для фильтрации элементов коллекции по определенному условию.

//6. Как используется операция Select ?
//Операция Select используется для проекции элементов коллекции в другой вид.

//7. Как используются операции Take, Skip?
//Операция Take используется для выбора определенного количества элементов коллекции. Операция Skip используется для пропуска определенного количества элементов коллекции.

//8. Как используется операция OrderBy?
//Операция OrderBy используется для сортировки элементов коллекции по возрастанию.

//9. Как используется операция OrderByDescending?
//Операция OrderByDescending используется для сортировки элементов коллекции по убыванию.

//10. Как используется операция GroupBy?
//Операция GroupBy используется для группировки элементов коллекции по определенному условию.

//11. Как используется операция Join?
//Операция Join используется для соединения двух коллекций по определенному условию.

//12. Как используется операция Union?
//Операция Union используется для объединения двух коллекций.

//13. Как используется операция Intersect?
//Операция Intersect используется для вычисления пересечения двух коллекций.

//14. Как используется операция Except?
//Операция Except используется для вычисления разности двух коллекций.

//15. Как используется операция Distinct?
//Операция Distinct используется для удаления дубликатов элементов коллекции.

//16. Как используется операция All?
//Операция All используется для проверки, удовлетворяют ли все элементы коллекции определенному условию.