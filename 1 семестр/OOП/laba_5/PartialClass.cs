using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;

partial class PartialClass
{

    
    

    #region Constructors
    public PartialClass()
    {
        Name = "Default";
        Surname = "Default";
    }
    public PartialClass(string name, string surname)
    {
        Name = name;
        Surname = surname;

    }
    #endregion

    #region Methods
    
    public void Print()
        
    {
        Console.WriteLine($"{Name} name, {Surname} surname");
    }
    #endregion
}