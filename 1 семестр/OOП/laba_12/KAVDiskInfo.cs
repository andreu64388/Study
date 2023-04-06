using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace laba_12;
static class KAVDiskInfo
{
    /*2. Создать класс XXXDiskInfo c методами для вывода информации о
a. свободном месте на диске
b. Файловой системе
c. Для каждого существующего диска - имя, объем, доступный
объем, метка тома.
d. Продемонстрируйте работу класса*/
    #region Methods 
    public static void FreeSpace()
    {
        DriveInfo[] drives = DriveInfo.GetDrives();
        foreach (DriveInfo drive in drives)
        {
            Console.WriteLine($"Drive name: {drive.Name}");
            Console.WriteLine($"Drive size: {drive.TotalSize}");
            Console.WriteLine($"Drive free space: {drive.TotalFreeSpace}");
            Console.WriteLine($"Drive label: {drive.VolumeLabel}\n\n");
   
        }
        KAVLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);

    }
    #endregion


}
