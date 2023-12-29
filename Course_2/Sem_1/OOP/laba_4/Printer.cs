using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;

static class Printer
/*     Создайте дополнительный класс Printer c полиморфным методом
IAmPrinting(SomeAbstractClassorInterface someobj). Формальным
параметром метода должна быть ссылка на абстрактный класс или наиболее
общий интерфейс в вашей иерархии классов.В методе iIAmPrinting
определите тип объекта и вызовите ToString(). В демонстрационной
программе создайте массив, содержащий ссылки на разнотипные объекты
ваших классов по иерархии, а также объект класса Printer и последовательно
вызовите его метод IAmPrinting со всеми ссылками в качестве аргументов*/

{

    public static void IAmPrinting(Testing test)
    {
        if (test is Exam testing)
        {
            Console.WriteLine(testing.ToString());
        }
        else if (test is Final_exam final_exam)
        {
            Console.WriteLine(final_exam.ToString());
        }
        else if (test is Test test1)
        {
            Console.WriteLine(test1.ToString());
        }
        else if (test is Question question)
        {
            Console.WriteLine(question.ToString());
        }
        else
        {
            Console.WriteLine("Error");
        }
    }
}



