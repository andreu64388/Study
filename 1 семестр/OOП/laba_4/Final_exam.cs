using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;
//Испытание, Тест, Экзамен, Выпускной экзамен, Вопрос; 
 class Final_exam :Exam
{
    #region Propertis
    public virtual string Subject { get; set; }
    #endregion endregion

    #region Methods
    public override void Successfully()
    {
        base.Successfully();
        Console.WriteLine("Final_exam Successfully");
    }

    // ToString
    public override string ToString()
    {
        return $"Subject: {Subject}, Teacher: {Teacher}, Mark: {Mark}";
    }
    #endregion


}
