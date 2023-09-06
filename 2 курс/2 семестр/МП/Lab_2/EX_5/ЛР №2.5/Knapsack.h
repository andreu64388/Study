// Knapsack.h      
#pragma once 
#include "Combi1.h"
int   knapsack_s(
    int V,         // [in]  ����������� ������� 
    short n,       // [in]  ���������� ����� ��������� 
    const int v[], // [in]  ������ �������� ������� ����  
    const int c[], // [in]  ��������� �������� ������� ����     
    short m[]      // [out] ���������� ��������� ������� ����  
);

bool RandomFilling(
    int* arr,       // [out] ������ ������ ��� ����������
    int size,       // [in] ������ �������
    int min,        // [in] ����������� �������� ��� ����������
    int max         // [in] ������������ �������� ��� ����������
);