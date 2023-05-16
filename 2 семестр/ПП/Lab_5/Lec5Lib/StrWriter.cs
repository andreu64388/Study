using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Lec5Lib
{
    public class StrWriter : IWriter
    {
        public string? Save(string? message)
        {
                return message;
        }
    }
}
