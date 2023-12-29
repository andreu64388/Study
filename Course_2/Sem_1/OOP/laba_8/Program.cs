namespace laba_8;

class Program
{
    static void Main(string[] args)
    {
        #region Class Boss
        Boss boss = new Boss("Boss", 100);
        Boss boss1 = new Boss("Boss1", 100);
        Boss boss2 = new Boss("Boss2", 100);
        boss.UpgradeAndTurnOn += MessageIncrease;
        boss.IncreaseTheVoltage(200);
        boss2.UpgradeAndTurnOn += MessageDecrease;
        boss2.UpgradeAndTurnOn += Message;
        boss2.IncreaseTheVoltage(200);
        Console.WriteLine(boss2);
        #endregion

        #region Delegate
        Action<string> action = (str) => Console.WriteLine(str);
        Func<string, string> func = (str) => str.ToLower();
        Predicate<string> predicate = (str) => str.Length > 5;
        func += ChangeString.Lower;
        func += ChangeString.Upper;
        func += ChangeString.Remove;
        func += ChangeString.Add;
        func?.Invoke("Test");
        #endregion

    }

    #region Methods for delegates
    public static void MessageIncrease(string message)
    {
        Console.ForegroundColor = ConsoleColor.Green;
        Console.WriteLine(message);
        Console.ResetColor();
    }
    public static void MessageDecrease(string message)
    {
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine(message);
        Console.ResetColor();
    }
    public static void Message(string message) => Console.WriteLine(message);
    #endregion



}

//Что такое делегат? Как определить делегат?
//Делегат - это ссылка на метод. Делегаты позволяют передавать методы в качестве параметров.
//Назначение делегатов.
//Делегаты используются для передачи методов в качестве параметров.

//Какие есть способы присваивания делегату адреса метода? 
//Делегату можно присвоить адрес метода, используя оператор присваивания (=) или оператор вызова метода (=>).

//. Поясните назначение метода Invoke.
//Метод Invoke вызывает делегат.

//Что такое групповая адресация делегата
//Групповая адресация делегата - это возможность присвоить делегату несколько методов.

//. Как создать событие 
//Событие создается с помощью ключевого слова event.

// Как события связаны с делегатами? Опишите и поясните схему взаимодействия.

//События связаны с делегатами. Событие - это специальный тип делегата, который позволяет объекту класса оповещать другие объекты о происходящих в нем событиях.

//Что такое лямбда-выражения? Приведите пример лямбда-выраженияс несколькими параметрам
//Лямбда-выражение - это анонимный метод, который может быть присвоен переменной делегата. Лямбда-выражение может содержать параметры, тело и возвращаемое значение.

//Что такое ковариантность и контравариантность делегатов? Что это 
//Ковариантность и контравариантность делегатов - это возможность присвоить делегату методы, которые имеют разные сигнатуры.

