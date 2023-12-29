using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;


sealed class Question:Final_exam
{
    #region Fields
    protected string _question;
    protected string _answer;
    #endregion

    #region Properties
    public string Question1
    {
        get => _question;
        set => _question = value;
    }

    public string Answer
    {
        get => _answer;
        set => _answer = value;
    }
    #endregion

    #region Constructors
    public Question()
    {
        Question1 = "Default";
        Answer = "Default";
    }

    public Question(string question, string answer)
    {
        Question1 = question;
        Answer = answer;
    }
    #endregion

    #region Methods
    public override void Successfully()
    {
        base.Successfully();
        Console.WriteLine("Question Successfully");
    }

    public override string ToString()
    {
        return $"Question: {Question1}, Answer: {Answer}";
    }
    #endregion
}


//sealed  это ключевое слово, которое используется для запрета наследования класса.