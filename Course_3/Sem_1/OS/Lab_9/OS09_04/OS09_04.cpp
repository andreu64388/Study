#define _CRT_NON_CONFORMING_WCSTOK
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <cstdlib>
#include "Windows.h"
#define FILE_PATH L"E:/student/learn/3_course/1_sem/ОС/Lab_9/OS09_01.txt"
#define DIR_PATH L"E:/student/learn/3_course/1_sem/ОС/Lab_9"
int rowC = 0;




BOOL printWatchRowFileTxt(LPWSTR FileName, DWORD mlsec)
{
    PLARGE_INTEGER fileSize = new LARGE_INTEGER();
    LPWSTR path = (LPWSTR)DIR_PATH;
    char* cFileName = new char[wcslen(FileName) * sizeof(char) + 1];
    wcstombs(cFileName, FileName, strlen(cFileName));
    int i = 0;
    int lenName = 0;
    try
    {
        HANDLE notif = FindFirstChangeNotification(path, false, FILE_NOTIFY_CHANGE_LAST_WRITE);
        DWORD err = GetLastError();
        clock_t t1 = clock();
        clock_t t2 = clock();
        DWORD dwWaitStatus;
        cout << "\n==================================================\n";
        printf("\tStarted filewatch (timestamp %d)", t1);
        while (true)
        {
            dwWaitStatus = WaitForSingleObject(notif, mlsec);
            switch (dwWaitStatus)
            {
            case WAIT_OBJECT_0:
            {
                if (FindNextChangeNotification(notif) == FALSE)
                    break;
                else
                {
                    int position = 0;
                    int rowCount = 0;
                    HANDLE of = CreateFile(
                        FileName,
                        GENERIC_READ,
                        FILE_SHARE_READ,
                        NULL,
                        OPEN_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL);
                    if (of == INVALID_HANDLE_VALUE)
                    {
                        CloseHandle(of);
                        throw "[ERROR] Open file failed";
                    }
                    if (GetFileSizeEx(of, fileSize))    
                    {
                        char* buf = new char[(fileSize->QuadPart + 1) * sizeof(char)];
                        ZeroMemory(buf, (fileSize->QuadPart + 1) * sizeof(char));
                        DWORD n = NULL;
                        if (ReadFile(of, buf, fileSize->QuadPart, &n, NULL))
                            while (buf[position++] != '\0')
                                if (buf[position] == '\n')
                                    rowCount++;
                    }
                    if (rowC != rowCount)
                    {
                        printf("\n\t\t      Rows: %d", rowCount);
                        rowC = rowCount;
                    }
                    CloseHandle(of);
                }
            }
            }
            t2 = clock();
            if (t2 - t1 > mlsec)
                break;
        }
        CloseHandle(notif);
        printf("\n\tEnded filewatch (timestamp %d)\n", t2);
    }
    catch (const char* err)
    {
        cout << "[ERROR] " << err << "\n";
        return false;
    }
    return true;
}





int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    LPWSTR fileName = (LPWSTR)FILE_PATH;
    printWatchRowFileTxt(fileName, 30000);
}
