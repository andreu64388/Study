#include <iostream>
#include <Windows.h>
using namespace std;
#define KB (1024)
#define MB (1024 * KB)
#define PG (4 * KB)

void saymem()
{
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    cout << "Объём физической памяти:      " << ms.dwTotalPhys / KB << " KB\n";
    cout << "Доступно физической памяти:   " << ms.dwAvailPhys / KB << " KB\n";
    cout << "Объем виртуальной памяти:     " << ms.dwTotalVirtual / KB << " KB\n";
    cout << "Доступно виртуальной памяти:  " << ms.dwAvailVirtual / KB << " KB\n\n";
}

/*
    К - 214(10) - D6(16)
    о - 208(10) - D0(16)
    р - 240(10) - F0(16)
    Страница D6 = 214
    214 * 4096 = 874240(10) = 0xD52C0 - добавить для перехода на страницу
    Смещение D0C = 3084(10) = 0x00000C0C
    Искомое значение: начало массива + 0xD52C0 + 0x00000C0C


*/
int main()
{
    setlocale(LC_ALL, "ru");
    int pages = 256;
    int countItems = pages * PG / sizeof(int);
    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);

    cout << "\t    Изначально в системе\n";
    saymem();

    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);   // выделено 1024 KB виртуальной памяти
    cout << "\tВыделено " << pages * PG / 1024 << " KB вирт. памяти\n";
    saymem();

    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++)
        arr[i] = i;

    int* byte = arr + 214 * 1024 + 3084;
    cout << "------  Значение памяти в байте: " << *byte << "  ------\n";

    VirtualFree(xmemaddr, NULL, MEM_RELEASE) ? cout << "\tВиртуальная память освобождена\n" : cout << "\tВиртуальная память не освобождена\n";
    saymem();
}


