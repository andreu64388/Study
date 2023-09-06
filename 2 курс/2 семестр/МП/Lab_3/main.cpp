// --- main 
#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5
int main()
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = {{ INF,12, 27, INF, 6 },
    { 6, INF, 21, 62 ,78 },
    { 8, 18, INF, 86, 55 },
    { 23, 52, 24, INF, 18 },
    { 87, 72, 52, 19, INF }};   //  4  
    int r[N];                     
    int s = salesman(
        N,        
        (int*)d,          
        r           

    );
    std::cout << std::endl << "-- Задача комивояжера -- ";
    std::cout << std::endl << "-- Количество городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}