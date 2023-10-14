#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;


//3 2 5
//1 3 3
//1 2 5
//255 2 5
DWORD intToProcessPriority(int i) {
	switch (i)
	{
	case 1: return IDLE_PRIORITY_CLASS;
	case 2: return BELOW_NORMAL_PRIORITY_CLASS;
	case 3: return NORMAL_PRIORITY_CLASS;
	case 4: return ABOVE_NORMAL_PRIORITY_CLASS;
	case 5: return HIGH_PRIORITY_CLASS;
	case 6: return REALTIME_PRIORITY_CLASS;
	default: throw "Unknown priority class";
	}
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc == 4)
		{
			HANDLE processHandle = GetCurrentProcess();
			DWORD_PTR pa = NULL, sa = NULL, icpu = -1;
			char buf[32];
			int parm1 = atoi(argv[1]);
			int parm2 = atoi(argv[2]);
			int parm3 = atoi(argv[3]);

			if (!GetProcessAffinityMask(processHandle, &pa, &sa))
				throw "Error in GetProcessAffinityMask";
			cout << "\t\tBefore applying parameters:\n";
			_itoa_s(pa, buf, 2);
			cout << "Process affinity Mask: " << buf << endl;
			_itoa_s(sa, buf, 2);
			cout << "System affinity Mask:  " << buf << endl;

			if (!SetProcessAffinityMask(processHandle, parm1))
				throw "ERROR in SetProcessAffinityMask";
			if (!GetProcessAffinityMask(processHandle, &pa, &sa))
				throw "Error in GetProcessAffinityMask";

			cout << "\t\tAfter applying parameters:\n";
			_itoa_s(pa, buf, 2);
			cout << "Process affinity Mask: " << buf << endl;
			_itoa_s(sa, buf, 2);
			cout << "System affinity Mask:  " << buf << endl;

			_itoa_s(parm1, buf, 2);
			cout << "Child 1 PriorityClass: " << parm2 << endl;
			cout << "Child 2 PriorityClass: " << parm3 << endl;

			LPCWSTR path1 = L"E:\\student\\learn\\3_course\\1_sem\\ОС\\Lab_5\\OS05_01\\x64\\Debug\\OS05_02x.exe";
			LPCWSTR path2 = L"E:\\student\\learn\\3_course\\1_sem\\ОС\\Lab_5\\OS05_01\\x64\\Debug\\OS05_02x.exe";

			STARTUPINFO si1, si2;
			PROCESS_INFORMATION pi1, pi2;

			ZeroMemory(&si1, sizeof(STARTUPINFO));
			ZeroMemory(&si2, sizeof(STARTUPINFO));
			si1.cb = sizeof(STARTUPINFO);
			si2.cb = sizeof(STARTUPINFO);

			if (CreateProcess(path1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | intToProcessPriority(parm2), NULL, NULL, &si1, &pi1))
				cout << "-- Process os05_02 1 was created\n";
			else cout << "-- Process os05_02 1 wasn't created\n";

			if (CreateProcess(path2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | intToProcessPriority(parm3), NULL, NULL, &si2, &pi2))
				cout << "-- Process OS05_02 2 was created\n";
			else cout << "-- Process OS05_02 2 wasn't created\n";

			WaitForSingleObject(pi1.hProcess, INFINITE);
			WaitForSingleObject(pi2.hProcess, INFINITE);

			CloseHandle(pi1.hProcess);
			CloseHandle(pi2.hProcess);
		}
		else
			cout << "No parameters provided" << endl;
	}
	catch (string err)
	{
		cout << err << endl;
	}
	system("pause");
}