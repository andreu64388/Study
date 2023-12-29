#include <iostream>
#include <Windows.h>



int main()
{
	int pid = GetCurrentProcessId();
	HANDLE mutex = OpenMutex(SYNCHRONIZE, FALSE, L"OS07_03");

	for (int i = 1; i <= 90; ++i)
	{
		if (i == 30)
			WaitForSingleObject(mutex, INFINITE);

		else if (i == 60)
			ReleaseMutex(mutex);

		printf("[OS07_03A]\t%d.  PID = %d\n", i, pid);
		Sleep(100);
	}

	CloseHandle(mutex);
}