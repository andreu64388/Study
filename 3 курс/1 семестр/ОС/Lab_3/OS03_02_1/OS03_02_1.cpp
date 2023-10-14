#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "------OS03_02_1-------\n";

	for (short i = 1; i <= 50; ++i)
	{	
		cout << i << ". PID = " << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}
	system("pause");
	return 0;
}