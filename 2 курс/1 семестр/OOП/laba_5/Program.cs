using System;


namespace laba_4;

class Program
{

    // as приведение типо       в
    // пример приведения типов с помощью as 
    // object obj = "Hello";
    // string str = obj as string; 
    // Console.WriteLine(str);



    static void Main(string[] args)
    {

        PartialClass partialClass = new PartialClass("Ivan", "Ivanov");
        partialClass.Print();
        Point first = new(1,3);

        first.Print();
        
        Test test_first = new ("Test", 1);
        Test test_second = new ("Test", 2);
        Test test_third = new ("Test", 3);

        Exam exam_first = new ("Exam", 1);
        Exam exam_second = new ("Exam", 2);
        Exam exam_third = new("Exam", 3);

        Session session = new Session();
        session.Add(test_third);
        session.AddSome(test_first, test_second, test_third, exam_first, exam_second, exam_third);
           
        session.Print();


        Console.WriteLine("Hello World!");
        /*    Написать демонстрационную программу, в которой создаются объекты
    различных классов. Поработать с объектами через  ссылки на абстрактные
    классы и интерфейсы. В этом случае для идентификации типов объектов
    использовать операторы is или as.*/

        Test tesint1 = new Test();
      /*  #region First
        Testing[] tests = new Testing[3];
        tests[0] = new Exam();
        tests[1] = new Final_exam();
        tests[2] = new Test();

        foreach (var test in tests)
        {
            Console.WriteLine(test);
            test.Successfully();
            test.Failed();
            Console.WriteLine();
        }

        Console.WriteLine("is");
        foreach (var test in tests)
        {
            if (test is Exam)
            {
                Console.WriteLine("Exam");
            }
            else if (test is Final_exam)
            {
                Console.WriteLine("Final_exam");
            }
            else if (test is Test)
            {
                Console.WriteLine("Test");
            }
            else
            {
                Console.WriteLine("Testing");
            }
        }

        Console.WriteLine("as");
        foreach (var test in tests)
        {
            if (test as Exam != null)
            {
                Console.WriteLine("Exam");
            }
            else if (test as Final_exam != null)
            {
                Console.WriteLine("Final_exam");
            }
            else if (test as Test != null)
            {
                Console.WriteLine("Test");
            }
            else
            {
                Console.WriteLine("Testing");
            }
        }

        Console.WriteLine("as");
        foreach (var test in tests)
        {
            if (test as Exam != null)
            {
                Console.WriteLine("Exam");
            }
            else if (test as Final_exam != null)
            {
                Console.WriteLine("Final_exam");
            }
            else if (test as Test != null)
            {
                Console.WriteLine("Test");
            }
            else
            {
                Console.WriteLine("Testing");
            }
        }

        Console.WriteLine("as");
        foreach (var test in tests)
        {
            if (test as Exam != null)
            {
                Console.WriteLine("Exam");
            }
            else if (test as Final_exam != null)
            {
                Console.WriteLine("Final_exam");
            }
            else if (test as Test != null)
            {
                Console.WriteLine("Test");
            }
            else
            {
                Console.WriteLine("Testing");
            }
        }

        Console.WriteLine("as");
        foreach (var test in tests)
        {
            if (test as Exam != null)
            {
                Console.WriteLine("Exam");
            }
            else if (test as Final_exam != null)
            {
                Console.WriteLine("Final_exam");
            }
            else if (test as Test != null)
            {
                Console.WriteLine("Test");
            }
            else
            {
                Console.WriteLine("Testing");
            }
        }
        #endregion*/

        Printer.IAmPrinting(tesint1);
        AddFileJSON.JsonSerialize();
        AddFileJSON.JsonDeserealize();
        var ses = new Session();
        Console.WriteLine(ses.Exams);
    }
    




}
//1. Чем класс отличается от структуры?
//Классы являются ссылочными типами, а структуры — значимыми. 
//Классы могут содержать в себе поля, методы, свойства, события, индексаторы, конструкторы, деструкторы, операторы, вложенные типы и интерфейсы.

//2 Что может и чего не может быть в структуре?

//Что такое перечисление? Приведите пример определения и использования перечисления 
//Перечисление — это тип данных, который представляет собой набор именованных констант.
//. Перечислите и поясните стандартные интерфейсы .Net

//IDisposable - интерфейс, который позволяет освободить ресурсы, занятые объектом.
//IComparable - интерфейс, который позволяет сравнивать объекты.
//IComparer - интерфейс, который позволяет сравнивать объекты.








//. Что такое полиморфизм?

//Полиморфизм — это свойство системы, позволяющее использовать объекты с одинаковой спецификацией без информации о конкретном типе их реализации.
//8. Зачем в классе определяют виртуальные методы?

//Виртуальные методы используются для переопределения в производных классах.q   
// структура это - 