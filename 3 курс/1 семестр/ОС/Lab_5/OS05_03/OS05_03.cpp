#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;


//255 3 3 3
//255 3 2 5
DWORD intToProcessPriority(int i)
{
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


DWORD intToThreadPriority(int i)
{
	switch (i)
	{
	case 1: return THREAD_PRIORITY_LOWEST;
	case 2: return THREAD_PRIORITY_BELOW_NORMAL;
	case 3: return THREAD_PRIORITY_NORMAL;
	case 4: return THREAD_PRIORITY_ABOVE_NORMAL;
	case 5: return THREAD_PRIORITY_HIGHEST;
	case 6: return THREAD_PRIORITY_IDLE;
	default: throw "No such priority class";
	}
}

void getProcessPriority(HANDLE hp)
{
	DWORD prty = GetPriorityClass(hp);

	switch (prty)
	{
	case IDLE_PRIORITY_CLASS:
		cout << "ProcessPriority: IDLE_PRIORITY_CLASS\n";
		break;
	case BELOW_NORMAL_PRIORITY_CLASS:
		cout << "ProcessPriority: BELOW_NORMAL_PRIORITY_CLASS\n";
		break;
	case NORMAL_PRIORITY_CLASS:
		cout << "ProcessPriority: NORMAL_PRIORITY_CLASS\n";
		break;
	case ABOVE_NORMAL_PRIORITY_CLASS:
		cout << "ProcessPriority: ABOVE_NORMAL_PRIORITY_CLASS\n";
		break;
	case HIGH_PRIORITY_CLASS:
		cout << "ProcessPriority: HIGH_PRIORITY_CLASS\n";
		break;
	case REALTIME_PRIORITY_CLASS:
		cout << "ProcessPriority: REALTIME_PRIORITY_CLASS\n";
		break;
	default: cout << "ERROR: PROCESS PRIORITY NOT RECOGNIZED\n\n"; break;
	}
}


void getThreadPriority(HANDLE ht)
{
	DWORD prty = GetThreadPriority(ht);

	cout << "ThreadPriority: " << GetThreadPriority(ht) << " ";

	switch (prty)
	{
	case THREAD_PRIORITY_LOWEST:
		cout << "THREAD_PRIORITY_LOWEST\n";
		break;
	case THREAD_PRIORITY_BELOW_NORMAL:
		cout << "THREAD_PRIORITY_BELOW_NORMAL\n";
		break;
	case THREAD_PRIORITY_NORMAL:
		cout << "THREAD_PRIORITY_NORMAL\n";
		break;
	case THREAD_PRIORITY_ABOVE_NORMAL:
		cout << "THREAD_PRIORITY_ABOVE_NORMAL\n";
		break;
	case THREAD_PRIORITY_HIGHEST:
		cout << "THREAD_PRIORITY_HIGHEST\n";
		break;
	case THREAD_PRIORITY_IDLE:
		cout << "THREAD_PRIORITY_IDLE\n";
		break;
	default: cout << "ERROR: THREAD PRIORITY NOT RECOGNIZED\n\n"; break;
	}
}


void childThread()
{
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	HANDLE hp = GetCurrentProcess();
	HANDLE ht = GetCurrentThread();
	DWORD icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);

	for (int i = 0; i < 1000000; i++)
	{
		if (i % 1000 == 0)
		{
			cout << "------------------------------------------\n";
			cout << "Iteration: " << i << endl;
			cout << "PID: " << pid << "\nTID: " << tid << endl;
			getProcessPriority(hp);
			getThreadPriority(ht);
			cout << "Thread IdealProcessor: " << dec << icpu << endl << endl;
			Sleep(200);
		}
	}
	return;
}


int main(int argc, char* argv[])
{
	try
	{
		if (argc == 5)
		{
			HANDLE processHandle = GetCurrentProcess();
			DWORD_PTR pa = NULL, sa = NULL, icpu = -1;
			char buf[13];
			int parm1 = atoi(argv[1]);
			int parm2 = atoi(argv[2]);
			int parm3 = atoi(argv[3]);
			int parm4 = atoi(argv[4]);

			if (!GetProcessAffinityMask(processHandle, &pa, &sa)) throw "Error in GetProcessAffinityMask";
			cout << "\t\tBefore applying parameters:\n";
			_itoa_s(pa, buf, 2);
			cout << "Process affinity Mask: " << buf << endl;
			_itoa_s(sa, buf, 2);
			cout << "System affinity Mask: " << buf << endl;

			if (!SetProcessAffinityMask(processHandle, parm1)) throw "ERROR in SetProcessAffinityMask";

			if (!GetProcessAffinityMask(processHandle, &pa, &sa)) throw "Error in GetProcessAffinityMask";
			cout << "\t\tAfter applying parameters:\n";
			_itoa_s(pa, buf, 2);
			cout << "Process affinity Mask: " << buf << endl;
			_itoa_s(sa, buf, 2);
			cout << "System affinity Mask: " << buf << endl;

			SetPriorityClass(processHandle, intToProcessPriority(parm2));
			cout << "Main PriorityClass: " << parm2 << endl;

			DWORD childId_T1, childId_T2 = NULL;
			HANDLE hChild1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)childThread, NULL, CREATE_SUSPENDED, &childId_T1);
			HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)childThread, NULL, CREATE_SUSPENDED, &childId_T2);

			SetThreadPriority(hChild1, intToThreadPriority(parm3));
			SetThreadPriority(hChild2, intToThreadPriority(parm4));

			getThreadPriority(hChild1);
			getThreadPriority(hChild2);

			ResumeThread(hChild1);
			ResumeThread(hChild2);

			WaitForSingleObject(hChild1, INFINITE);
			WaitForSingleObject(hChild2, INFINITE);

			CloseHandle(hChild1);
			CloseHandle(hChild2);
		}
		else cout << "No parameters provided" << endl;
	}
	catch (string err) {
		cout << err << endl;
	}
	system("pause");
}