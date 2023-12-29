#include <Windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define FILE_PATH L"E:/student/learn/3_course/1_sem/ОС/Lab_9/OS09_01.txt"
#define READ_BYTES 185




WIN32_FIND_DATA fileData;
HANDLE hFile = FindFirstFileW(FILE_PATH, &fileData);

string getFileName(wchar_t* filePath)
{
    wstring ws(filePath);
    string filename(ws.begin(), ws.end());
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (string::npos != last_slash_idx)
        filename.erase(0, last_slash_idx + 1);
    return filename;
}




LPCWSTR getFileType(HANDLE file)
{
    switch (GetFileType(file))
    {
    case FILE_TYPE_UNKNOWN:
        return L"FILE_TYPE_UNKNOWN";
    case FILE_TYPE_DISK:
        return L"FILE_TYPE_DISK";
    case FILE_TYPE_CHAR:
        return L"FILE_TYPE_CHAR";
    case FILE_TYPE_PIPE:
        return L"FILE_TYPE_PIPE";
    case FILE_TYPE_REMOTE:
        return L"FILE_TYPE_REMOTE";
    default:
        return L"[ERROR]: WRITE FILE TYPE";
    }
}




BOOL printFileInfo(LPWSTR path) 
{
    HANDLE file = CreateFile(
        path,
        GENERIC_READ,
        NULL,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    SYSTEMTIME sysTime;
    BY_HANDLE_FILE_INFORMATION fi;
    BOOL fResult = GetFileInformationByHandle(file, &fi);
    if (fResult) 
    {
        cout << "File name:\t" << getFileName((wchar_t*)FILE_PATH);
        std::wcout << "\nFile type:\t " << (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ? L"Directory" : L"File");
        cout << "\nFile size:\t" << fi.nFileSizeLow << " bytes";
        FileTimeToSystemTime(&fi.ftCreationTime, &sysTime);
        std::cout << "\nCreate time:\t" << std::setfill('0') << std::setw(2) << sysTime.wHour + 3 << ':' << std::setw(2) << sysTime.wMinute << ':' << std::setw(2) << sysTime.wSecond;
        std::cout << " " << std::setw(4) << sysTime.wYear << '-' << std::setw(2) << sysTime.wMonth << '-' << std::setw(2) << sysTime.wDay;

        FileTimeToSystemTime(&fi.ftLastWriteTime, &sysTime);
        std::cout << "\nUpdate time:\t" << std::setfill('0') << std::setw(2) << sysTime.wHour + 3 << ':' << std::setw(2) << sysTime.wMinute << ':' << std::setw(2) << sysTime.wSecond;
        std::cout << " " << std::setw(4) << sysTime.wYear << '-' << std::setw(2) << sysTime.wMonth << '-' << std::setw(2) << sysTime.wDay;

    }
    CloseHandle(file);
    return true;
}



BOOL printFileTxt(LPWSTR path) 
{
    HANDLE file = CreateFile(
        path,
        GENERIC_READ,
        NULL,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    char buf[1024];
    DWORD countBytes = NULL;
    ZeroMemory(buf, sizeof(buf));
    BOOL b = ReadFile(
        file, 
        &buf, 
        READ_BYTES, 
        &countBytes, 
        NULL);
    if (!b) throw "[ERROR] Readfile throwed exception.";
    cout << "\n\n\tPrint file (" << countBytes << " bytes)\n" << buf << '\n';
}





int main()
{
    setlocale(LC_ALL, "ru");
    LPWSTR path = (LPWSTR)FILE_PATH;
   
    printFileInfo(path);
 
    printFileTxt(path);
}

