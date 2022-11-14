using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace laba_12;

static class KAVileInfo
{
    /*. Создать класс XXXFileInfo c методами для вывода информации о
конкретном файле
a. Полный путь
b. Размер, расширение, имя
c. Дата создания, изменения
d. Продемонстрируйте работу класса*/
    #region Methods 
    public static void GetFileInfo(string path)
    {
        FileInfo file = new(path);
        Console.WriteLine($"Full path: {file.FullName}");
        Console.WriteLine($"File size: {file.Length}");
        Console.WriteLine($"File extension: {file.Extension}");
        Console.WriteLine($"File name: {file.Name}");
        Console.WriteLine($"File creation time: {file.CreationTime}");
        Console.WriteLine($"File last access time: {file.LastAccessTime}");
        Console.WriteLine($"File last write time: {file.LastWriteTime}\n\n");
        KAVLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
    }
    #endregion
}

//FileInfo - это класс, который позволяет получить информацию о файле.
//Конструктор FileInfo принимает в качестве параметра путь к файлу.
//FileInfo file = new FileInfo("C:\\Users\\User\\D