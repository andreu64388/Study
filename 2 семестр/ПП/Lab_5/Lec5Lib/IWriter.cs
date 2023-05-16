using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec5Lib
{
    public interface IWriter
    {
        string? Save(string? message);
    }
}
