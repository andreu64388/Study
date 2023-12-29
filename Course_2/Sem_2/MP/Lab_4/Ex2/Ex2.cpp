#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"

void main() {
    setlocale(LC_ALL, "rus");

    clock_t t1 = 0, t2 = 0, t3, t4;

    char x[] = "abcdefghklmnoxm", y[] = "xyabcdefghomnkm";
    int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;

    std::cout << std::endl;
    std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
    std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---"
        << std::endl;

    for (int i = 8; i < std::min(lx, ly); i++) {
        t1 = clock(); 
            levenshtein_r(i, x, i - 2, y); 
        t2 = clock();

        t3 = clock(); 
            levenshtein(i, x, i - 2, y); 
        t4 = clock();

        std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
            << "        " << std::left << std::setw(10) << (t2 - t1)
            << "   " << std::setw(10) << (t4 - t3) << std::endl;
    }

    system("pause");
}
