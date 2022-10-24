using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;

namespace Lab_9;


public class Program

{
    public static void Main(string[] args)
    {

        SortedList<string, int> sorted = new(5);
        sorted.Add("one", 1);
        sorted.Add("two", 2);

        Console.WriteLine(sorted["two"]);


        Software software = new("Windows",
                                "10",
                                "Microsoft",
                                "Free",
                                "English");

        Software software1 = new("Windows", "10", "Microsoft", "Free", "English");
        Software software2 = new("Windows", "10", "Microsoft", "Free", "English");

        Console.WriteLine("--------------------------------------------------------------\n\n\n");

        SortedList<Software, int> sortedList = new(3);

        sortedList.Add(software, 200);
        sortedList.Add(software1, 300);
        sortedList.Add(software2, 400);

        Console.WriteLine(sortedList[software1]);



        /*Создайте объект наблюдаемой коллекции ObservableCollection<T>. Создайте
произвольный метод и зарегистрируйте его на событие CollectionChange.
Напишите демонстрацию с добавлением и удалением элементов. В качестве
типа T используйте свой класс из таблицы.*/
        Console.WriteLine("--------------------------------------------------------------\n\n\n");
        ObservableCollection<Software> observableCollection = new();
        observableCollection.CollectionChanged += CollectionChange;
        observableCollection.Add(software);
        observableCollection.Add(software1);
        observableCollection.Add(software2);
        observableCollection.Remove(software1);

        static void CollectionChange(object sender,
                                        NotifyCollectionChangedEventArgs e)
        {
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    Console.WriteLine("Add");
                    break;

            }
        }
     
     }
}



/*. На какие основные виды/типы делятся все коллекции .NET? Охарактеризуйте
каждый из них.
2. Что такое generic-коллекции? Назовите примеры известных вам genericколлекций.
3. В чем разница между ArrayList и Array?
4. Охарактеризуйте коллекции, которые вы использовали в своем варианте.
5. Чем отличаются коллекции, расположенные в пространстве имен
System.Collections.Concurrent?
6. Какое пространство имен необходимо подключить в проект, чтобы иметь
возможность использовать generic-коллекции?
7. Что такое наблюдаемая коллекция? Как ее можно использовать?
8. Охарактеризуйте интерфейсы IEnumerator, IEnumerator. В чем отличие
назначений интерфейсов IEnumerator и IEnumerable.
9. Поясните принцип работы коллекций: */


// На какие основные виды/типы делятся все коллекции .NET? Охарактеризуйте каждый из них.

// 1. Коллекции, которые хранят данные в виде пар ключ-значение.
// 2. Коллекции, которые хранят данные в виде списка.
// 3. Коллекции, которые хранят данные в виде стека.
// 4. Коллекции, которые хранят данные в виде очереди.
// 5. Коллекции, которые хранят данные в виде хеш-таблицы.


//2. Что такое generic-коллекции? Назовите примеры известных вам genericколлекций

//Generic-коллекции - это коллекции, которые могут хранить данные любого типа.

//3. В чем разница между ArrayList и Array?

//ArrayList - это коллекция, которая может хранить данные любого типа.
//Array - это массив, который может хранить данные только одного типа.

//4. Охарактеризуйте коллекции, которые вы использовали в своем варианте.

//Я использовал коллекцию Dictionary, которая хранит данные в виде пар ключ-значение.

//5. Чем отличаются коллекции, расположенные в пространстве имен System.Collections.Concurrent?

//Коллекции, расположенные в пространстве имен System.Collections.Concurrent, являются потокобезопасными.
// это означает, что несколько потоков могут одновременно работать с этими коллекциями.

/*6. Какое пространство имен необходимо подключить в проект, чтобы иметь
возможность использовать generic-коллекции?*/

//Для использования generic-коллекций необходимо подключить пространство имен System.Collections.Generic.

//7. Что такое наблюдаемая коллекция? Как ее можно использовать?

//Наблюдаемая коллекция - это коллекция, которая уведомляет об изменениях в ней.


/*8. Охарактеризуйте интерфейсы IEnumerator, IEnumerator. В чем отличие
назначений интерфейсов IEnumerator и IEnumerable.*/

//IEnumerator - это интерфейс, который позволяет перебирать элементы коллекции.

