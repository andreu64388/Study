/*  2. Создайте пять методов пользовательской обработки строки (например,
удаление знаков препинания, добавление символов, замена на заглавные, 
удаление лишних пробелов и т.п.). Используя стандартные типы делегатов 
(Action, Func, Predicate) организуйте алгоритм последовательной обработки 
строки написанными вами методами. Далее приведен перечень заданий.
*/
namespace laba_8;
class ChangeString
{
    #region Static methods
    public static string Lower(string str)
    {
        Console.WriteLine("Lower - " + str.ToLower());
        return str.ToLower();
    }

    public static string Upper(string str)
    {
        Console.WriteLine("Upper - " + str.ToUpper());
        return str.ToUpper();
    }

    public static string Remove(string str)
    {
        Console.WriteLine("Remove - " + str.Remove(0, 1));
        return str.Replace(" ", "");
    }

    public static string Add(string str) => str + "!";

    #endregion

}
