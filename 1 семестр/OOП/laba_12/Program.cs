namespace laba_12;

class Program
{
    public static void Main()
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

        KAVFileManager.GetFilesAndFoulders("C:\\");

        KAVFileManager.CreateCopyOfFile("C:\\Users\\User\\Desktop\\laba_12\\laba_12\\bin\\Debug\\net6.0\\laba_12.dll");

        KAVFileManager.CreateZip("C:\\Users\\User\\Desktop\\laba_12\\laba_12\\bin\\Debug\\net6.0\\laba_12.dll");

        KAVileInfo.GetFileInfo("C:\\Users\\User\\Desktop\\laba_12\\laba_12\\bin\\Debug\\net6.0\\laba_12.dll");
        
        





    }
}