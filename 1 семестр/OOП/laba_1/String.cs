using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba;

static class String
{
  static public void PrintCompareString()
    {

        //Объявите строковые литералы. Сравните их.
        string str1 = "Hello";
        string str2 = "Hello";
        // сравниваем строки
        string message = (str1 == str2) ? "Строки равны" : "Строки не равны";

        Console.WriteLine(message);
        if (str1 == str2)
        {
            Console.WriteLine("Cтроки равны");
        }
        else
        {
            Console.WriteLine("Строки не равны");
        }

        // Сравниваем строки с методос Compare
       
        // сравниваем строки
        string message1 = (string.Compare(str1,str2) == 0) ? "Строки равны" : "Строки не равны";
       

        Console.WriteLine(message1);
    } 
    static public void PrintWorkToString()
    {
        /*Создайте три строки на основе String. Выполните: сцепление,
     копирование, выделение подстроки, разделение строки на слова,
     вставки подстроки в заданную позицию, удаление заданной
     подстроки*/
        string name = "Andrey";
        string surname = "Korenchuk";
        string university = "BSTU";

        // сцепление
        string fullName = name + " " + surname;
        Console.WriteLine($"Full name: {fullName}");
        fullName = string.Concat(name, " ", surname);

    
        //копирование
        string copyFullName = fullName;    
        Console.WriteLine(copyFullName);
        Console.WriteLine("----------------------------------------------------");
        //выделение подстроки

        string subString = fullName.Substring(0,4);
        subString = "Dima";
        // удалиь последний символ
        subString = subString.Substring(0,subString.Length - 1);
        Console.WriteLine(subString);
        subString = subString.Remove(subString.Length - 1);
        Console.WriteLine(subString);
        subString = "Dima";
        subString = subString.Remove(0, 2);
        Console.WriteLine(subString);
        Console.WriteLine("----------------------------------------------------");

        // разделение строки на слова

        string text = "I want to sleep. Help me";
        string[] words = text.Split(' ');
        foreach (string word in words)
        {
            Console.WriteLine(word);
        }
        Console.WriteLine("----------------------------------------------------");
        // вставка подстроки в заданную позицию
        string text1 = "I want to sleep. Help me";
        text1 = text1.Insert(10, "very ");
        Console.WriteLine(text1);

        Console.WriteLine("----------------------------------------------------");
        // удаление заданной подстроки

        string text2 = "I want to sleep. Help me";
        text2 = text2.Remove(0, 6);
        Console.WriteLine(text2);

        Console.WriteLine("----------------------------------------------------");







    }
    static public void PrintToWorkNull ()
    {
        /*Создайте пустую и null строку. Продемонстрируйте
 использование метода string.IsNullOrEmpty. Продемонстрируйте
 что еще можно выполнить с такими строками
 */
        string str = "";
        string str1 = null;
        Console.WriteLine(string.IsNullOrEmpty(str));
        Console.WriteLine(string.IsNullOrEmpty(str1));
        
        
        


    }
        static public void PrintStringBuilder ()
    {
        /*Создайте строку на основе StringBuilder. Удалите определенные
позиции и добавьте новые символы в начало и конец строки.
*/
        StringBuilder str = new StringBuilder("Hello");
        str.Remove(0, 2);
        str.Insert(0, "Hi");
        str.Append("!");
        Console.WriteLine(str);
    }
}
