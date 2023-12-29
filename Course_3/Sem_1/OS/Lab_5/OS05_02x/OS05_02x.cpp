#include <iostream>
#include <cstdlib>
#include <intrin.h>
#include <iomanip>
#include "Windows.h"
using namespace std;



void PrintProcessPriority(HANDLE processHandle)
{
	DWORD processPriority = GetPriorityClass(processHandle);

	switch (processPriority)
	{
	case IDLE_PRIORITY_CLASS:				cout << "Process priority:  IDLE_PRIORITY_CLASS\n";				break;
	case BELOW_NORMAL_PRIORITY_CLASS:		cout << "Process priority:  BELOW_NORMAL_PRIORITY_CLASS\n";		break;
	case NORMAL_PRIORITY_CLASS:				cout << "Process priority:  NORMAL_PRIORITY_CLASS\n";			break;
	case ABOVE_NORMAL_PRIORITY_CLASS:		cout << "Process priority:  ABOVE_NORMAL_PRIORITY_CLASS\n";		break;
	case HIGH_PRIORITY_CLASS:				cout << "Process priority:  HIGH_PRIORITY_CLASS\n";				break;
	case REALTIME_PRIORITY_CLASS:			cout << "Process priority:  REALTIME_PRIORITY_CLASS\n";			break;
	default:								cout << "[ERROR] Unknown process priority.\n";					break;
	}
}




void PrintThreadPriority(HANDLE threadHandle)
{
	DWORD threadPriority = GetThreadPriority(threadHandle);

	switch (threadPriority)
	{
	case THREAD_PRIORITY_LOWEST:		cout << "Thread proiority:  THREAD_PRIORITY_LOWEST\n";			break;
	case THREAD_PRIORITY_BELOW_NORMAL:	cout << "Thread proiority:  THREAD_PRIORITY_BELOW_NORMAL\n";	break;
	case THREAD_PRIORITY_NORMAL:		cout << "Thread proiority:  THREAD_PRIORITY_NORMAL\n";			break;
	case THREAD_PRIORITY_ABOVE_NORMAL:	cout << "Thread proiority:  THREAD_PRIORITY_ABOVE_NORMAL\n";	break;
	case THREAD_PRIORITY_HIGHEST:		cout << "Thread proiority:  THREAD_PRIORITY_HIGHEST\n";			break;
	case THREAD_PRIORITY_IDLE:			cout << "Thread proiority:  THREAD_PRIORITY_IDLE\n";			break;
	default:							cout << "[ERROR] Unknown thread priority.\n";					break;
	}
}




void PrintAffinityMask(HANDLE hp, HANDLE ht) {
	DWORD_PTR pa = NULL, sa = NULL, icpu = -1;
	char buf[32];

	if (!GetProcessAffinityMask(hp, &pa, &sa))
		throw "[FATAL] GetProcessAffinityMask threw an exception.";

	_itoa_s(pa, buf, 2);
	cout << "Process affinity mask: " << buf;
	cout << " (" << showbase << hex << pa << ")\n";
	_itoa_s(sa, buf, 2);
	cout << "System affinity mask:  " << buf;
	cout << " (" << showbase << hex << sa << ")\n";


	SYSTEM_INFO sys_info;
	GetSystemInfo(&sys_info);
	icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);
	cout << "Thread IdealProcessor: " << dec << icpu << "\n";
}




int main()
{
	HANDLE processHandle = GetCurrentProcess();
	HANDLE threadHandle = GetCurrentThread();
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();


	for (int i = 0; i < 1000000; i++)
	{
		if (i % 1000 == 0)
		{
			cout << "\n--------------------------------------------\n\n";
			cout << "Iteration:         " << i << "\n\n";
			cout << "Current PID:       " << pid << "\n";
			cout << "Current TID:       " << tid << "\n";
			PrintProcessPriority(processHandle);
			PrintThreadPriority(threadHandle);
			cout << "\n";
			PrintAffinityMask(processHandle, threadHandle);
			cout << "\n--------------------------------------------\n\n\n";
			Sleep(200);
		}
	}

	system("pause");
}