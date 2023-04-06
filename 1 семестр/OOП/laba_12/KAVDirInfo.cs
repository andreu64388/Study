using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace laba_12;

static class KAVDirInfo
{
    /*. Создать класс XXXDirInfo c методами для вывода информации о конкретном
директории
a. Количестве файлов
b. Время создания
c. Количестве поддиректориев
d. Список родительских директориев
e. Продемонстрируйте работу класса*/

    #region Methods 
    public static void GetDirInf(string path)
    {
        DirectoryInfo dir = new(path);
       
        Console.WriteLine($"Directory name: {dir.Name}");
        Console.WriteLine($"Directory creation time: {dir.CreationTime}");
        Console.WriteLine($"Directory parent: {dir.Parent}");
        Console.WriteLine($"Directory root: {dir.Root}");
        Console.WriteLine($"Directory subdirectories: {dir.GetDirectories().Length}");
        Console.WriteLine($"Directory files: {dir.GetFiles().Length}\n\n");
        KAVLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
    }
    
    #endregion

}
//директории - это класс, который позволяет получить информацию о директории.
//что такое директория - это папка, в которой хранятся файлы.