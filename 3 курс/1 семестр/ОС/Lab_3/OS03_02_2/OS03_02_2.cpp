#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "------ OS03_02_2 ------ \n";

	for (short i = 1; i <= 125; ++i)
	{
		cout << i << ". PID = " << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}
	system("pause");
	return 0;
}