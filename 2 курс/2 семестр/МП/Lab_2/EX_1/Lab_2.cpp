#include <iostream>
#include "Combi1.h"
#include <tchar.h>

using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");	
	char  AA[][2] = { "A", "B", "C", "D" };
	cout << endl << " - Генератор множества всех подмножеств -";
	cout << endl << "Исходное множество: ";
	cout << "{ ";


	for (int i = 0; i < sizeof(AA) / 2; i++)
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	cout << "}\nГенерация всех подмножеств  ";


	combi1::subset s1(sizeof(AA) / 2);     // создание генератора   
	int  n = s1.getfirst();    // первое (пустое) подмножество    

	while (n >= 0)                         // пока есть подмножества 
	{
		cout << endl << "{ ";
		for (int i = 0; i < n; i++)
			cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		cout << "}";
		n = s1.getnext();                  // cледующее подмножество 
	};

	cout << endl << "всего: " << s1.count() << endl;
	system("pause");
	return 0;

}