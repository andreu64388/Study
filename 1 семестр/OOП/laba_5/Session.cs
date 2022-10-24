using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;

class Session :Testing


{
 
    
    #region Fields
    
 

    private const int MAX_COUNT_OF_EXAM = 10;
    private int currentCount = 0;
    private Testing[] _Exams = new Testing[MAX_COUNT_OF_EXAM];

    #endregion


    #region Properties

    public Testing[] Exams
    {
        get { return _Exams; }
        set { _Exams = value; }
    }
    
    

   

    #endregion



    #region Methods 
    public override void Failed()
    {
        Console.WriteLine("Fail");
    }


    public void Print()
    {


        for (int i = 0; i < currentCount; i++)
        {
            Console.WriteLine(_Exams[i].Name);
        }
       



    }
    public void Add(Testing exam)
    {
        if (currentCount < MAX_COUNT_OF_EXAM)
        {
            _Exams[currentCount] = exam;
            currentCount++;
        }
        else
        {
            Console.WriteLine("Error");
        }





    }
    /* Найти все экзамены по заданному предмету, подсчитать
 общее количество испытаний в сессии и количество тестов
 с заданным числом вопросов.
 */
    public void FindExam(string name)
    {
        int count = 0;
        for (int i = 0; i < currentCount; i++)
        {
            if (_Exams[i].Name == name)
            {
                count++;
            }
        }
        Console.WriteLine("Count of exams: " + count);
    }

    public void AddSome(params Testing[] exams )
    {

        foreach (var exam in exams)
        {
            Add(exam);
        }

    }

  
    /* Найти все экзамены по заданному предмету, подсчитать
общее количество испытаний в сессии и количество тестов
с заданным числом вопросов.*/


    #endregion

}

/*Определить управляющий класс-Контроллер, который управляет
объектом- Контейнером и реализовать в нем запросы по варианту.При
необходимости используйте стандартные интерфейсы (IComparable,
ICloneable,….)*/


interface ISession
{


    void Add(Testing exam);
    void Print();
    void FindExam(string name);
    void AddSome(params Testing[] exams);

    
}

