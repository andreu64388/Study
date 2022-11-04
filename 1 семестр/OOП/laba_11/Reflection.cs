

using System.Reflection;

namespace laba_11;
 static class Reflection
{

    //Определение имени сборки, в которой определен класс;

    public static void GetAssemblyName(Type type)
    {
        Console.WriteLine("Имя сборки: " + type.AssemblyQualifiedName);
    }

    //есть ли публичные конструкторы;
  
    public static void GetConstructors(Type type)
    {
        Console.WriteLine("Конструкторы: ");
        foreach (var constructor in type.GetConstructors())
        {
            Console.WriteLine(constructor);
        }
    }

    /*. извлекает все общедоступные публичные методы класса
(возвращает IEnumerable<string>);*/

    public static void GetMethods(Type type)
    {
        Console.WriteLine("Методы: ");
        foreach (var method in type.GetMethods())
        {
            Console.WriteLine(method);
        }
    }

    //выводит все общедоступные свойства класса (возвращает IEnumerable<string>);

    public static void GetProperties(Type type)
    {
        Console.WriteLine("Свойства: ");
        foreach (var property in type.GetProperties())
        {
            Console.WriteLine(property);
        }
    }

    //выводит все общедоступные поля класса (возвращает IEnumerable<string>);

    public static void GetFields(Type type)
    {
        Console.WriteLine("Поля: ");
        foreach (var field in type.GetFields())
        {
            Console.WriteLine(field);
        }
    }

    //выводит все общедоступные интерфейсы, которые реализует класс (возвращает IEnumerable<string>);

    public static void GetInterfaces(Type type)
    {
        Console.WriteLine("Интерфейсы: ");
        foreach (var @interface in type.GetInterfaces())
        {
            Console.WriteLine(@interface);
        }
    }

    //выводит все общедоступные параметры метода (возвращает IEnumerable<string>);

    public static void GetParameters(Type type)
    {
        Console.WriteLine("Параметры: ");
        foreach (var method in type.GetMethods())
        {
            foreach (var parameter in method.GetParameters())
            {
                Console.WriteLine(parameter);
            }
        }
    }

    //выводит все общедоступные атрибуты класса (возвращает IEnumerable<string>);

    public static void GetAttributes(Type type)
    {
        Console.WriteLine("Атрибуты: ");
        foreach (var attribute in type.GetCustomAttributes())
        {
            Console.WriteLine(attribute);
        }
    }

    //выводит все общедоступные атрибуты метода (возвращает IEnumerable<string>);

    public static void GetMethodAttributes(Type type)
    {
        Console.WriteLine("Атрибуты методов: ");
        foreach (var method in type.GetMethods())
        {
            foreach (var attribute in method.GetCustomAttributes())
            {
                Console.WriteLine(attribute);
            }
        }
    }

    /*получает информацию о полях и свойствах класса (возвращает
IEnumerable<string>*/

    public static void GetFieldsAndProperties(Type type)
    {
        Console.WriteLine("Поля и свойства: ");
        foreach (var field in type.GetFields())
        {
            Console.WriteLine(field);
        }
        foreach (var property in type.GetProperties())
        {
            Console.WriteLine(property);
        }
    }

    /*получает все реализованные классом интерфейсы (возвращает
IEnumerable<string>)*/

    public static void GetImplementedInterfaces(Type type)
    {
        Console.WriteLine("Реализованные интерфейсы: ");
        foreach (var @interface in type.GetInterfaces())
        {
            Console.WriteLine(@interface);
        }
    }

    /*выводит по имени класса имена методов, которые содержат
заданный (пользователем) тип параметра (имя класса передается
в качестве аргумента);*/

    public static void GetMethodsByParameter(Type type, string parameter)
    {
        Console.WriteLine("Методы с параметром " + parameter + ": ");
        foreach (var method in type.GetMethods())
        {
            foreach (var param in method.GetParameters())
            {
                if (param.ParameterType.Name == parameter)
                {
                    Console.WriteLine(method);
                }
            }
        }
    }

    /*g. метод Invoke, который вызывает метод класса, при этом значения
для его параметров необходимо 1) прочитать из текстового файла
(имя класса и имя метода передаются в качестве аргументов) 2)
сгенерировать, используя генератор значений для каждого типа.
Параметрами метода Invoke должны быть : объект, имя метода,
массив параметров.
*/

    public static void Invoke(Type type, string methodName)
    {
        var method = type.GetMethod(methodName);
        var parameters = method.GetParameters();
        var values = new object[parameters.Length];
        for (int i = 0; i < parameters.Length; i++)
        {
            values[i] = GetRandomValue(parameters[i].ParameterType);
        }
        method.Invoke(null, values);
    }

    private static object GetRandomValue(Type parameterType)
    {
        throw new NotImplementedException();
    }


    //выводит все общед

}
