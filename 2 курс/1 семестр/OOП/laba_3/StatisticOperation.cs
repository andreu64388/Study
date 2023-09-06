using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_3;

 static class StatisticOperation
{/*
    Создайте статический класс StatisticOperation, содержащий 3 метода для
работы с вашим классом(по варианту п.1): сумма, разница между
максимальным и минимальным, подсчет количества элементов.*/
    public static int Sum(Stack<int> stack)
    {
        return stack.AllElements.Sum(); 
    }
    public static int Difference(Stack<int> stack)
    {
        return stack.AllElements.Max() - stack.AllElements.Min();
    }
    public static int Count(Stack<int> stack)
    {
        return stack.AllElements.Length;
    }

}