#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE createThread(LPTHREAD_START_ROUTINE func);
void close_timer_watcher();
void print_timer_watcher();

HANDLE print_timer = CreateWaitableTimer(NULL, FALSE, L"os08_04v2_print");
HANDLE close_timer = CreateWaitableTimer(NULL, FALSE, L"os08_04v2_close");

bool print = false, iterate = true;




int main()
{
	LPTHREAD_START_ROUTINE funcs[] = { (LPTHREAD_START_ROUTINE)close_timer_watcher, (LPTHREAD_START_ROUTINE)print_timer_watcher };

	const int size = sizeof(funcs) / sizeof(LPTHREAD_START_ROUTINE);
	HANDLE threads[size];

	LARGE_INTEGER close_timeout;
	close_timeout.QuadPart = -150000000LL;

	LARGE_INTEGER print_timeout;
	print_timeout.QuadPart = -30000000LL;

	clock_t current_time, start_time = clock();

	unsigned long int i;

	for (i = 0; i < size; i++)
		threads[i] = createThread(funcs[i]);

	SetWaitableTimer(print_timer, &print_timeout, 3000, NULL, NULL, FALSE);
	SetWaitableTimer(close_timer, &close_timeout, 0, NULL, NULL, 0);

	for (i = 0; iterate; i++)
	{
		current_time = ((clock() - start_time) / CLOCKS_PER_SEC);

		if (print) 
		{
			cout << "Time:  " << current_time << "\tIterations: " << i << '\n';
			print = false;
		}
	}

	cout << "Final: " << i << '\n';


	for (i = 0; i < size; i++)
		CloseHandle(threads[i]);

	system("pause");
	return 0;
}

HANDLE createThread(LPTHREAD_START_ROUTINE func)
{
	DWORD thread_id = NULL;
	HANDLE thread = CreateThread(NULL, 0, func, NULL, 0, &thread_id);

	if (thread == NULL) {
		throw "Error creating child thread";
	}

	return thread;
}

void close_timer_watcher()
{
	WaitForSingleObject(close_timer, INFINITE);

	iterate = false;

	CloseHandle(close_timer);
}

void print_timer_watcher()
{
	for (;;)
	{
		WaitForSingleObject(print_timer, INFINITE);

		print = true;
	}

	CloseHandle(print_timer);
}