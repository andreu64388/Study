#include <windows.h>
#include <iostream>

void sh(HANDLE heap) {
    SetConsoleOutputCP(1251);
    PROCESS_HEAP_ENTRY entry;
    entry.lpData = NULL;
    SIZE_T totalSize = 0, allocatedSize = 0, unallocatedSize = 0;

    while (HeapWalk(heap, &entry) != FALSE) {
        totalSize += entry.cbData;
        if (entry.wFlags & PROCESS_HEAP_ENTRY_BUSY) {
            allocatedSize += entry.cbData;
        }
        else {
            unallocatedSize += entry.cbData;
        }
    }

    std::cout << "Общий размер heap: " << totalSize << "\n";
    std::cout << "Размер распределенной области памяти heap: " << allocatedSize << "\n";
    std::cout << "Размер нераспределенной области памяти heap: " << unallocatedSize << "\n";
}

int main() {    
    HANDLE heap = GetProcessHeap();
    sh(heap);

    const int ARRAYSIZE = 300000;
    int* array = new int[ARRAYSIZE];

    sh(heap);

    delete[] array;
    return 0;
}
