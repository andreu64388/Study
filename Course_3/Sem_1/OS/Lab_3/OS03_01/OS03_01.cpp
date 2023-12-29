#include <iostream>
#include <Windows.h>	
using namespace std;

int main()
{
	for (short i = 1; i <= 10000; ++i)
	{
		cout << i << ". PID = " << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}
	return 0;
}