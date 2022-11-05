using System;
using System.Collections.Generic;
using System.Linq;
using System.IO.Compression;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace laba_12;

static class KAVFileManager
{
    /*. Создать класс XXXFileManager. Набор методов определите
самостоятельно. С его помощью выполнить следующие действия:
a. Прочитать список файлов и папок заданного диска. Создать
директорий XXXInspect, создать текстовый файл
xxxdirinfo.txt и сохранить туда информацию. Создать
копию файла и переименовать его. Удалить
первоначальный файл.
b. Создать еще один директорий XXXFiles. Скопировать в
него все файлы с заданным расширением из заданного
пользователем директория. Переместить XXXFiles в
XXXInspect.
c. Сделайте архив из файлов директория XXXFiles.
Разархивируйте его в другой директорий.*/

    #region Methods
    public static void GetFilesAndFoulders(string path)
    {

        /*. Прочитать список файлов и папок заданного диска. Создать
директорий XXXInspect, создать текстовый файл
xxxdirinfo.txt и сохранить туда информацию. Создать
копию файла и переименовать его. Удалить
первоначальный файл.*/
        DirectoryInfo dir = new(path);

        var files = dir.GetFiles();
        var foulders = dir.GetDirectories();

        dir.CreateSubdirectory("KAVInspect");

        dir = new(path + "\\KAVInspect");

        string path_dirInfo = "KAVdirinfo.txt";

        using StreamWriter sw = new(dir.FullName + "\\" + path_dirInfo);

        foreach (var f in files)
        {
            sw.WriteLine(f.Name);
        }

        sw.WriteLine("\n");

        foreach (var f in foulders)
        {
            sw.WriteLine(f.Name);
        }

        sw.WriteLine("\n");



    }

    /*b. Создать еще один директорий XXXFiles. Скопировать в
него все файлы с заданным расширением из заданного
пользователем директория. Переместить XXXFiles в
XXXInspect.*/
    public static void CreateCopyOfFile(string path)
        
    {
        FileInfo file = new(path);

        DirectoryInfo dir = file.Directory ??
                            throw new ArgumentNullException("Directory is not found");

        string fullNameOfCopy = $"{dir.FullName}\\copy_{file.Name}";
        Remove(fullNameOfCopy);

        file.CopyTo(fullNameOfCopy);


    }
    public static void Remove(string path)
    {
        if (path is null)
        {
            throw new ArgumentNullException(nameof(path));
        }

        FileInfo file = new(path);
        file.Delete();

        KAVLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
    }
    /*Сделайте архив из файлов директория XXXFiles.
Разархивируйте его в другой директорий.*/
    public static void CreateZip(string path)
    {
        DirectoryInfo dir = new(path);

        string zipPath = $"{dir.FullName}\\{dir.Name}.zip";

        ZipFile.CreateFromDirectory(dir.FullName, zipPath);

        KAVLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
    }

    #endregion
}

