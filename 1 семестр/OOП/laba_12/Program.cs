namespace laba_12;

class Program
{
    public static void Main()
    {
       


        try
        {
            KAVDiskInfo.FreeSpace();
            /*6. Найдите и выведите сохраненную информацию в файле xxxlogfile.txt о
    действиях пользователя за определенный день/ диапазон времени/по
    ключевому слову. Посчитайте количество записей в нем. Удалите часть
    информации, оставьте только записи за текущий час.
    */
            DateTime startTime = new(2021, 10, 10, 10, 10, 10);
            DateTime endTime = new(2022, 10, 10, 10, 10, 10);

            KAVDirInfo.GetDirInf("C:\\");

            KAVDirInfo.GetDirInf("C:\\");

            KAVFileManager.GetFilesAndFoulders("..\\net6.0");
            KAVFileManager.CreateCopyOfFile("KAVInspect\\kavdirinfo.txt");

            KAVFileManager.CreateDirectory("..\\net6.0", "KAVFiles");

            KAVFileManager.ReplaceTo("..\\net6.0", "KAVFiles", ".dll", ".exe");

            KAVFileManager.CreateZip("GDVFiles");


        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }



    }
}