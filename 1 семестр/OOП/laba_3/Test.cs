using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_3;
/*
Добавьте в свой класс вложенный объект Production, который содержит
Id, название организации.Проинициализируйте его*/

 class Production
{
    public int Id { get; set; }
    public string Name { get; set; }
    /*    Добавьте в свой класс вложенный класс Developer(разработчик – фио,
    id, отдел). Проинициализируйте*/
    public class Developer
    {
        public string FIO { get; set; }
        public int Id { get; set; }
        public string Department { get; set; }
    }
    

}