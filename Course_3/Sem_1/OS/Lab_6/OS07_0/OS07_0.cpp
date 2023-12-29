#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
int check;





HANDLE createThread(LPTHREAD_START_ROUTINE func, char* thread_name)
{
	DWORD thread_id = NULL;
	HANDLE thread = CreateThread(NULL, 0, func, thread_name, 0, &thread_id);
	if (thread == NULL) 
		throw "[ERROR] CreateThread";
	return thread;
}




void EnterCriticalSectionAssem()
{
	_asm
	{
	CriticalSection:
		lock bts check, 0;
		jc CriticalSection
	}
}




void LeaveCriticalSectionAssem()
{
	_asm lock btr check, 0
}




void WINAPI loop(char* displayed_name) 
{
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 1; i <= 90; ++i)
	{
		if (i == 30) 
			EnterCriticalSectionAssem();

		printf("%d.\tPID = %d\tTID = %u\tcheck: %d\tthread: %s\n", i, pid, tid, check, displayed_name);

		if (i == 60) 
			LeaveCriticalSectionAssem();

		Sleep(100);
	}

	cout << "\n==========================  " << displayed_name << " finished" << "  ==========================\n\n";
}






int main()
{
	const int size = 2;
	HANDLE threads[size];

	threads[0] = createThread((LPTHREAD_START_ROUTINE)loop, (char*)"A");
	threads[1] = createThread((LPTHREAD_START_ROUTINE)loop, (char*)"B");

	WaitForMultipleObjects(size, threads, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
		CloseHandle(threads[i]);

	return 0;
}