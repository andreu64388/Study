#include <string>
#include <iostream>
#include <locale>
using namespace std;
bool CheckMask(unsigned long long mask)                //проверка маски на непрерывность единиц
{
	bool result = true;
	bool one = false;
	short buf;
	int check = mask / 100000000000;
	if (!check)
		return false;
	do
	{
		buf = mask % 1000;
		mask /= 1000;
		for (short unit = 1; unit <= 255; unit <<= 1)
		{
			short ff = unit & buf;
			if (ff)
				one = true;
			if (!ff && one)
			{
				result = false;
				return result;
			}
		}
	} while (mask);
	return result;
}
bool CheckAddress(char* ip_)
{
	int points = 0, // количество точек
		numbers = 0; // значение октета
	char* buff; // буфер для одного октета
	buff = new char[3];
	for (int i = 0; ip_[i] != '\0'; i++)
	{ // для строки IP-адреса
		if (ip_[i] <= '9'&& ip_[i] >= '0') // если цифра
		{
			if (numbers > 3) return false;
			//если больше трех чисел в октете – ошибка
			buff[numbers++] = ip_[i];
			//скопировать в буфер
		}
		else
			if (ip_[i] == '.') // если точка
			{
				if (atoi(buff) > 255)
					// проверить диапазон октета
					return false;
				if (numbers == 0)
					//если числа нет - ошибка
					return false;
				numbers = 0;
				points++;
				delete[]buff;
				buff = new char[3];
			}
			else return false;
	}
	if (points != 3)
		// если количество точек в IP-адресе не 3 - ошибка
		return false;
	if (numbers == 0 || numbers > 3)
		return false;
	return true;
}
unsigned long long CharToLong(char* ip_)
{
	int count = 3;
	char buf[3];         
	unsigned long long number = 0;     
	for (int j = 0, i = 0; ip_[i]; i++, j++)
	{
		if (ip_[i] >= '0' && ip_[i] <= '9')
		{
			count--;
			buf[j] = ip_[i];
		}
		if (ip_[i] == '.' || ip_[i + 1] == '\0')
		{
			for (int l = 2; l > 0; l--)
				buf[l] = buf[l - count];
			while (count > 0)
			{
				count--;
				buf[count] = '0';
			}
			number *= 1000;
			number += (unsigned long long)atoi(buf);
			j = -1;
			count = 3;
		}
	}
	return number;
}
void address(unsigned long long ip, unsigned long long mask, char* ip_, char* mask_)
{
	unsigned long long maskCopy = mask;
	unsigned long long ipCopy = ip;
	unsigned long long maskCopy2 = mask;
	unsigned long long ipCopy2 = ip;
	unsigned char ipRes, maskRes;
	int oktet[4], i = 3;
	cout << "IP: " << ip_ << endl;
	cout << "Маска: " << mask_ << endl;
	do
	{
		ipRes = ip % 1000;
		maskRes = mask % 1000;
		ip /= 1000;
		mask /= 1000;
		oktet[i] = ipRes & maskRes;
		i--;
	} while (mask);
	cout << "Адрес сети: ";
	for (int j = 0; j < 4; j++)
	{
		cout << oktet[j];
		if (j < 3)
			cout << '.';
	}
	cout << endl;
	i = 3;

	do
	{
		ipRes = ipCopy % 1000;
		maskRes = maskCopy % 1000;
		ipCopy /= 1000;
		maskCopy /= 1000;
		oktet[i] = ipRes & ~maskRes;
		i--;
	} while (maskCopy);
	cout << "Адрес хоста: ";
	for (int j = 0; j < 4; j++)
	{
		cout << oktet[j];
		if (j < 3)
			cout << '.';
	}
	cout << endl;
	i = 3;

	do
	{
		ipRes = ipCopy2 % 1000;
		maskRes = ~(maskCopy2 % 1000);
		ipCopy2 /= 1000;
		maskCopy2 /= 1000;
		oktet[i] = ipRes | maskRes;
		i--;
	} while (maskCopy2);
	cout << "Широковещательный адрес: ";
	for (int j = 0; j < 4; j++)
	{
		cout << oktet[j];
		if (j < 3)
			cout << '.';
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");

	unsigned long long ip, mask, host, subnet, broadcast;
	char *ip_, *mask_;
	bool flag = true;
	ip_ = new char[16];
	mask_ = new char[16];
	ip_ = argv[1];
	mask_ = argv[2];

	if (argv[1] == NULL || argv[2] == NULL)
	{
		cout << "Необходимо ввести IP адрес и маску" << endl;
		return 0;
	}

	if (!(flag = CheckAddress(ip_)))
	{
		cout << "Неверно введён адрес!" << endl;
		return 0;
	}
	ip = CharToLong(ip_);
	flag = true;

	if (!(flag = CheckAddress(mask_)))
	{
		cout << "Неверно введена маска";
		return 0;
	}

	mask = CharToLong(mask_);

	if (!(flag = CheckMask(mask)))
	{
		cout << "В маске нарушена непрерывность единиц";
		return 0;
	}

	address(ip, mask, ip_, mask_);
	return 0;
}