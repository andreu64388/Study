using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.Json;

namespace laba_4;



/*Дополнительное задание
1. Добавьте в класс-контроллер метод, считывающий построчно
текстовый файл, в котором хранятся данные вашего класса и инициализирует
таким образом коллекцию.
2. Реализуйте еще один метод, который будет считывать данные из json
файла и инициализировать коллекцию(https://www.newtonsoft.com/json).*/
class AddFileJSON
{

    public const string PATH = "data.json";

    public static void JsonSerialize()
    {
        using StreamWriter sw = new(PATH);
        
            var str = JsonSerializer.Serialize(new Point(1, 2));
        sw.WriteLine(str);
         


        

    }
    public static void JsonDeserealize()
    {
        using StreamReader sr = new(PATH);
        var str = sr.ReadToEnd();
        var obj = JsonSerializer.Deserialize<Point>(str);
    }
}
