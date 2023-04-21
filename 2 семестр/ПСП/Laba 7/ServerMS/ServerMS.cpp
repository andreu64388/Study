#include "iostream"
#include "Winsock2.h"

#pragma comment(lib,"WS2_32.lib")
#pragma warning(disable:4996) 

using namespace std;

string GetErrorMsgText(int code);
string SetMailError(string msgText, int code);

void main()
{
	DWORD rb;
	HANDLE mailslot;

	clock_t start, end;

	setlocale(LC_ALL, "RU");

	try
	{
		if ((mailslot = CreateMailslot(L"\\\\.\\mailslot\\Box", 300, 3 * 60 * 1000, NULL)) == INVALID_HANDLE_VALUE)
		{
			throw SetMailError("Error: ", GetLastError());
		}

		char rbuf[500] = "ad";
		int i = 0;

		end = start = 0;
		do
		{
			i++;
			try
			{
				if (!ReadFile(mailslot, rbuf, sizeof(rbuf), &rb, NULL))
				{
					throw SetMailError("Error: 2", GetLastError());
				}
				else if (start == 0)
				{
					start = clock();
				}
			}
			catch (...)
			{
				cout << "Время ожидание прошло.\n";
			}

			cout << rbuf << endl;
			end = clock();
		} while (strcmp(rbuf, "") != 0);
		cout << "\ntime: " << end - start << "мс\n";
		cout << "end";

		if (!CloseHandle(mailslot))
		{
			throw SetMailError("Error: ", GetLastError());
		}
	}
	catch (string e)
	{
		cout << e << endl;
	}
}

string GetErrorMsgText(int code)
{
	string msgText;
	switch (code)
	{
	case WSAEINTR: msgText = "Работа функции прервана"; break;
	case WSAEACCES:	msgText = "Разрешение отвергнуто"; break;
	case WSAEFAULT: msgText = "Ошибочный адрес"; break;
	case WSAEINVAL:	msgText = "Ошибка в аргументе";	break;
	case WSAEMFILE:	msgText = "Открыто слишком много файлов"; break;
	case WSAEWOULDBLOCK: msgText = "Ресурс временно недоступен"; break;
	case WSAEINPROGRESS: msgText = "Операция в процессе развития"; break;
	case WSAEALREADY: msgText = "Операция уже выполняется";	break;
	case WSAENOTSOCK: msgText = "Сокет задан неправильно"; break;
	case WSAEDESTADDRREQ: msgText = "Требуется адрес расположения"; break;
	case WSAEMSGSIZE: msgText = "Сообщение слишком длинное"; break;
	case WSAEPROTOTYPE: msgText = "Неправильный тип протокола для сокета"; break;
	case WSAENOPROTOOPT: msgText = "Ошибка в опции протокола"; break;
	case WSAEPROTONOSUPPORT: msgText = "Протокол не поддерживается"; break;
	case WSAESOCKTNOSUPPORT: msgText = "Тип сокета не поддерживается"; break;
	case WSAEOPNOTSUPP: msgText = "Операция не поддерживается"; break;
	case WSAEPFNOSUPPORT: msgText = "Тип протоколов не поддерживается"; break;
	case WSAEAFNOSUPPORT: msgText = "Тип адресов не поддерживается протоколом"; break;
	case WSAEADDRINUSE: msgText = "Адрес уже используется"; break;
	case WSAEADDRNOTAVAIL: msgText = "Запрошенный адрес не может быть использован"; break;
	case WSAENETDOWN: msgText = "Сеть отключена"; break;
	case WSAENETUNREACH: msgText = "Сеть не достижима"; break;
	case WSAENETRESET: msgText = "Сеть разорвала соединение"; break;
	case WSAECONNABORTED: msgText = "Программный отказ связи"; break;
	case WSAECONNRESET: msgText = "Связь не восстановлена"; break;
	case WSAENOBUFS: msgText = "Не хватает памяти для буферов"; break;
	case WSAEISCONN: msgText = "Сокет уже подключен"; break;
	case WSAENOTCONN: msgText = "Сокет не подключен"; break;
	case WSAESHUTDOWN: msgText = "Нельзя выполнить send: сокет завершил работу"; break;
	case WSAETIMEDOUT: msgText = "Закончился отведенный интервал времени"; break;
	case WSAECONNREFUSED: msgText = "Соединение отклонено"; break;
	case WSAEHOSTDOWN: msgText = "Хост в неработоспособном состоянии"; break;
	case WSAEHOSTUNREACH: msgText = "Нет маршрута для хоста"; break;
	case WSAEPROCLIM: msgText = "Слишком много процессов"; break;
	case WSASYSNOTREADY: msgText = "Сеть не доступна"; break;
	case WSAVERNOTSUPPORTED: msgText = "Данная версия недоступна"; break;
	case WSANOTINITIALISED: msgText = "Не выполнена инициализация WS2_32.dll"; break;
	case WSAEDISCON: msgText = "Выполняется отключение"; break;
	case WSATYPE_NOT_FOUND: msgText = "Класс не найден"; break;
	case WSAHOST_NOT_FOUND: msgText = "Хост не найден"; break;
	case WSATRY_AGAIN: msgText = "Неавторизованный хост не найден"; break;
	case WSANO_RECOVERY: msgText = "Неопределенная ошибка"; break;
	case WSANO_DATA: msgText = "Нет записи запрошенного типа"; break;
	case WSASYSCALLFAILURE: msgText = "Аварийное завершение системного вызова"; break;
	case 2: msgText = "Неудачное завершение"; break;
	case ERROR_INVALID_PARAMETER: msgText = "Значение параметра pimax превосходит величину  PIPE_UNLMITED_INSTANCES"; break;
	case ERROR_NO_DATA: msgText = "The pipe is being closed"; break;
	case ERROR_PIPE_CONNECTED: msgText = "There is a process on other end of the pipe"; break;
	case ERROR_PIPE_LISTENING: msgText = "Waiting for a process to open the other end of the pipe"; break;
	case ERROR_CALL_NOT_IMPLEMENTED: msgText = "This function is not supported on this system"; break;
	default: msgText = "**ERROR**"; break;
	}

	return msgText;
}
string SetMailError(string msgText, int code)
{
	return msgText + GetErrorMsgText(code) + "\n\n";
}
