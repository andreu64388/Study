#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

#include "Ex2/Levenshtein.h"

using namespace std;

string generateRandomString(int length);

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	string str300 = generateRandomString(300); // Генерируем случайную строку S1 длиной 300 символов
	string str200 = generateRandomString(200); // Генерируем случайную строку S2 длиной 200 символов

	cout << "S1: " << str300 << endl;
	cout << "S2: " << str200 << endl;


	clock_t 
		t1 = 0,
		t2 = 0,
		t3 = 0, 
		t4 = 0;

	int lx = sizeof(str300);
	int ly = sizeof(str200);

	int s1_size[]{ 300 / 25, 300 / 20, 300 / 15, 300 / 10, 300 / 5, 300 / 2, 300 };
	int s2_size[]{ 200 / 25, 200 / 20, 200 / 15, 200 / 10, 200 / 5, 200 / 2, 200 };

	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна --" << std::endl;
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---"
		<< std::endl;

	for (int i = 0; i < min(lx, ly); i++)
	{
		t1 = clock();
			levenshtein_r(s1_size[i], str300.c_str(), s2_size[i], str200.c_str());
		t2 = clock();

		t3 = clock();
			levenshtein(s1_size[i], str300.c_str(), s2_size[i], str200.c_str());
		t4 = clock();

		cout << right << setw(2) << s1_size[i] << "/" << setw(2) << s2_size[i]
			<< "        " << left << setw(10) << (t2 - t1)
			<< "   " << setw(10) << (t4 - t3) << endl;
	}
	system("pause");
}



// Функция для генерации случайных строк
string generateRandomString(int length) {
	string randomString;
	const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int lettersLength = sizeof(letters) - 1;

	srand(time(NULL)); // Инициализируем генератор случайных чисел

	for (int i = 0; i < length; i++) {
		randomString += letters[rand() % lettersLength];
	}

	return randomString;
}

