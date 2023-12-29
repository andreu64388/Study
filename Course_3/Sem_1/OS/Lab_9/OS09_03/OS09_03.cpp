#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fileapi.h>
#define FILE_PATH L"E:/student/learn/3_course/1_sem/ОС/Lab_9/OS09_01.txt"
#define READ_BYTES 1000
using namespace std;




BOOL printFileText(LPWSTR fileName) 
{
	try 
	{
		cout << "\n\n\t======  RESULT  ======\n";
		HANDLE hf = CreateFile(fileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hf == INVALID_HANDLE_VALUE) throw "[ERROR] Create or open file failed.";
		DWORD  n = NULL;
		char buf[1024];

		ZeroMemory(buf, sizeof(buf));
		BOOL b = ReadFile(hf, &buf, READ_BYTES, &n, NULL);
		if (!b) throw "[ERROR] Read file failed";
		cout << buf << endl;
		CloseHandle(hf);
		return true;
	}
	catch (const char* em) 
	{
		cout << "[ERROR] " << em << endl;
		return false;
	}
}




BOOL insRowFileTxt(LPWSTR fileName, LPWSTR str, DWORD row) 
{
	char filepath[20];
	wcstombs(filepath, fileName, 20);
	char stringToInsert[50];
	wcstombs(stringToInsert, str, 50);
	cout << "\n======  Insert row: " << row << "\n\n";

	try
	{
		HANDLE hf = CreateFile(fileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hf == INVALID_HANDLE_VALUE) 
		{
			CloseHandle(hf);
			throw "[ERROR] Create or open file failed";
		}

		DWORD n = NULL;
		char buf[1024];
		BOOL b;

		ZeroMemory(buf, sizeof(buf));
		b = ReadFile(hf, &buf, sizeof(buf), &n, NULL);
		if (!b) 
		{
			CloseHandle(hf);
			throw ("[ERROR] Read file unsuccessful");
		}
		if (!b) 
		{
			cout << "Read file unsuccessful.\n";
			CloseHandle(hf);
			return false;
		}
		cout << "\t\tBEFORE:\n";
		cout << buf << endl;
		CloseHandle(hf);

		HANDLE hAppend = CreateFile(fileName, GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		char editedBuf[1024];
		ZeroMemory(editedBuf, sizeof(editedBuf));

		int line = 1;
		int j = 0;
		int k = 0;
		for (int i = 0; i < n; i++) 
		{
			if (line == row) 
			{
				for (int k = 0; k < sizeof(stringToInsert); k++) 
				{
					editedBuf[j] = str[k];
					j++;
					if (str[k + 1] == '\0') 
					{
						editedBuf[j] = '\r';
						j++;
						editedBuf[j] = '\n';
						j++;
						row = 0;
						break;
					}
				}
				i--;
			}
			else 
			{
				editedBuf[j] = buf[i];
				j++;
			}

			if (buf[i] == '\n') 
				line++;

			if (buf[i + 1] == '\0' && row == -1) 
			{
				for (int k = 0; k < sizeof(stringToInsert); k++) 
				{
					editedBuf[j] = str[k];
					j++;
					if (str[k + 1] == '\0') 
					{
						editedBuf[j] = '\r';
						j++;
						editedBuf[j] = '\n';
						j++;
						row = 0;
						break;
					}
				}
			}
		}

		b = WriteFile(hAppend, editedBuf, j, &n, NULL);
		if (!b) 
		{
			CloseHandle(hAppend);
			throw ("[ERROR] Write file unsuccessful\n");
		}

		cout << "\t\tAFTER:\n";
		cout << editedBuf << endl;
		CloseHandle(hAppend);
		cout << "\n==========================================\n";
		return true;
	}
	catch (const char* em) 
	{
		cout << em << " \n";
		cout << "==========================================\n";
		return false;
	}
}




int main()
{
	setlocale(0, "ru");
	LPWSTR  file = (LPWSTR)FILE_PATH;

	char str[] = "4. Insert";	
	wchar_t wStr[50];
	mbstowcs(wStr, str, strlen(str) + 1);
	LPWSTR strToIns = wStr;

	insRowFileTxt(file, strToIns, 1);
	insRowFileTxt(file, strToIns, -1);
	insRowFileTxt(file, strToIns, 5);
	insRowFileTxt(file, strToIns, 7);

	printFileText(file);
}