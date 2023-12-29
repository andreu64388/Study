#pragma comment(lib, "WS2_32.lib") 
#pragma warning(disable: 4996)
#include "Winsock2.h"

#include <algorithm>
#include <iostream>



int countServers = 0;
using namespace std;

string SetErrorMsgText(string msgText, int code);
string GetErrorMsgText(int code); 
bool PutAnswerToClient(char*, short, struct sockaddr*, int*);
bool GetRequestFromClient(char* name, short port, struct sockaddr* from, int* flen);
void GetServer(char* call, short port, struct sockaddr* from, int* flen);

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[20] = "Hello";

	SOCKET cS;
	WSADATA wsaData;

	SOCKADDR_IN client;
	int lobuf;
	int lc = sizeof(client);
	char ibuf[50];
	int lb = 0;
	int lclient = sizeof(client);

	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
			throw SetErrorMsgText("Startup:", WSAGetLastError());

		//GetServer(name, 2000, (sockaddr*)&client, &lclient);

		//............................................................
		if ((cS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
			throw SetErrorMsgText("socket:", WSAGetLastError());
		//.............................................................	

		char hostname[25];

		if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR)
			throw SetErrorMsgText("Получение host name: ", WSAGetLastError());
		cout << "Host name сервера: " << hostname << endl;

		
		SOCKADDR_IN serv;
		serv.sin_family = AF_INET;
		serv.sin_port = htons(2000);
		/*serv.sin_addr.s_addr = inet_addr("127.0.0.1");*/
		serv.sin_addr.s_addr = INADDR_ANY;

		if (bind(cS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
			throw SetErrorMsgText("bind:", WSAGetLastError());
		

		while (true) {


		
			
			if (GetRequestFromClient(name, cS, (sockaddr*)&client, &lclient))
			{
				countServers++;
				auto clntInfo = gethostbyaddr((const char*)&client.sin_addr, 4, AF_INET);
				cout << "Client socket:" << endl;
				cout << "Hostname: " << clntInfo->h_name << endl;
				cout << "IP: " << inet_ntoa(client.sin_addr) << endl;
				cout << "Port: " << htons(client.sin_port) << endl;
				cout << "Count: " << countServers << endl;
				cout << endl;

				if (!PutAnswerToClient((char*)name /*32"*/, cS, (sockaddr*)&client, &lclient))
				{
					cout << "Ошибка" << endl;
				}

				countServers--;
			}

			else {
				cout << "Dont connected by name";
			}
			}
		
			

		if (closesocket(cS) == SOCKET_ERROR)
			throw SetErrorMsgText("closesocket:", WSAGetLastError());

		if (WSACleanup() == SOCKET_ERROR)
			throw SetErrorMsgText("Cleanup:", WSAGetLastError());
	}
	catch (string errorMsgText)
	{
		cout << endl << "WSAGetLastError: " << errorMsgText;
	}


}	


bool PutAnswerToClient(char* name, short port, struct sockaddr* to, int* lto)
{
	int lbuf;
	if (lbuf = sendto(port, name, strlen(name) + 1, NULL, to, *lto) == SOCKET_ERROR)
		throw SetErrorMsgText("sendto: ", WSAGetLastError());
	return true;
}

bool GetRequestFromClient(char* name, short port, struct sockaddr* from, int* flen)
{
	int lbuf;
	char ibuf[50] = "";
	cout << "Wait message..." << endl;
	while (true)
	{
		if (lbuf = recvfrom(port, ibuf, sizeof(ibuf), NULL, from, flen) == SOCKET_ERROR)
		{
			if (WSAGetLastError() == WSAETIMEDOUT)
				return false;
			else
				throw SetErrorMsgText("recvfrom: ", WSAGetLastError());
		}
		if (strcmp(ibuf, name) == 0)
			return true;
		else
			return false;
	}
}




string  SetErrorMsgText(string msgText, int code)
{
	return  msgText + GetErrorMsgText(code);
}

void GetServer(char* call, short port, struct sockaddr* from, int* flen) {
	SOCKET cC;
	SOCKADDR_IN all;

	int timeout = 5000;


	int optval = 1;
	char buf[50];

	try {
		if ((cC = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
			throw  SetErrorMsgText("socket:", WSAGetLastError());

		if (setsockopt(cC, SOL_SOCKET, SO_BROADCAST, (char*)&optval, sizeof(int)) == SOCKET_ERROR)
			throw  SetErrorMsgText("setsocketopt:", WSAGetLastError());
	

		all.sin_family = AF_INET;
		all.sin_port = htons(port);
		all.sin_addr.s_addr = INADDR_BROADCAST; // широковещательный адрес
		
	
		// отправка широковещательного запроса с позывным
		if (sendto(cC, call, strlen(call) + 1, NULL, (sockaddr*)&all, sizeof(all)) == SOCKET_ERROR)
			throw SetErrorMsgText("sendto:", WSAGetLastError());

		if (recvfrom(cC, buf, sizeof(buf), NULL, from, flen) == SOCKET_ERROR)
			throw  SetErrorMsgText("recvfrom:", WSAGetLastError());

		
		if (strcmp(call, buf) == 0) {
			countServers++;
			cout << "Server N" << countServers;
			hostent* shostname = gethostbyaddr((char*)&((SOCKADDR_IN*)from)->sin_addr, sizeof(SOCKADDR_IN), AF_INET);
			cout << "\tIP: " << inet_ntoa(((SOCKADDR_IN*)from)->sin_addr) << endl;
			cout << "\t\tPort: " << ntohs(((struct sockaddr_in*)from)->sin_port) << endl;
			cout << "\t\tHostname: " << shostname->h_name << endl;
		}
	}
	catch (string errorMsgText)
	{
		if (WSAGetLastError() == WSAETIMEDOUT) {
			cout << "Total number of servers with that callsign: " << countServers << endl;
			if (closesocket(cC) == SOCKET_ERROR) throw SetErrorMsgText("closesocket: ", WSAGetLastError());
		}
		else throw SetErrorMsgText("GetServer:", WSAGetLastError());
	}
}
string  GetErrorMsgText(int code)    // cформировать текст ошибки 
{

	string msgText;
	switch (code)
	{
	case WSAEINTR:         msgText = "Работа функции прервана\n";              break;
	case WSAEACCES:         msgText = "Разрешение отвергнуто\n";              break;
	case WSAEFAULT:         msgText = "Ошибочный адрес\n";                  break;
	case WSAEINVAL:         msgText = "Ошибка в аргументе\n";                break;
	case WSAEMFILE:         msgText = "Слишком много файлов открыто\n";          break;
	case WSAEWOULDBLOCK:     msgText = "Ресурс временно недоступен\n";            break;
	case WSAEINPROGRESS:     msgText = "Операция в процессе развития\n";          break;
	case WSAEALREADY:        msgText = "Операция уже выполняется\n";            break;
	case WSAENOTSOCK:        msgText = "Сокет задан неправильно\n";              break;
	case WSAEDESTADDRREQ:     msgText = "Требуется адрес расположения\n";          break;
	case WSAEMSGSIZE:         msgText = "Сообщение слишком длинное\n";              break;
	case WSAEPROTOTYPE:       msgText = "Неправильный тип протокола для сокета\n";      break;
	case WSAENOPROTOOPT:     msgText = "Ошибка в опции протокола\n";            break;
	case WSAEPROTONOSUPPORT:   msgText = "Протокол не поддерживается\n";            break;
	case WSAESOCKTNOSUPPORT:   msgText = "Тип сокета не поддерживается\n";          break;
	case WSAEOPNOTSUPP:       msgText = "Операция не поддерживается\n";            break;
	case WSAEPFNOSUPPORT:     msgText = "Тип протоколов не поддерживается\n";        break;
	case WSAEAFNOSUPPORT:     msgText = "Тип адресов не поддерживается протоколом\n";    break;
	case WSAEADDRINUSE:       msgText = "Адрес уже используется\n";              break;
	case WSAEADDRNOTAVAIL:     msgText = "Запрошенный адрес не может быть использован\n";    break;
	case WSAENETDOWN:       msgText = "Сеть отключена\n";                  break;
	case WSAENETUNREACH:     msgText = "Сеть не достижима\n";                break;
	case WSAENETRESET:       msgText = "Сеть разорвала соединение\n";            break;
	case WSAECONNABORTED:     msgText = "Программный отказ связи\n";              break;
	case WSAECONNRESET:       msgText = "Связь восстановлена\n";                break;
	case WSAENOBUFS:       msgText = "Не хватает памяти для буферов\n";          break;
	case WSAEISCONN:       msgText = "Сокет уже подключен\n";                break;
	case WSAENOTCONN:       msgText = "Сокет не подключен\n";                break;
	case WSAESHUTDOWN:       msgText = "Нельзя выполнить send: сокет завершил работу\n";  break;
	case WSAETIMEDOUT:       msgText = "Закончился отведенный интервал  времени\n";      break;
	case WSAECONNREFUSED:     msgText = "Соединение отклонено\n";              break;
	case WSAEHOSTDOWN:       msgText = "Хост в неработоспособном состоянии\n";        break;
	case WSAEHOSTUNREACH:     msgText = "Нет маршрута для хоста\n";              break;
	case WSAEPROCLIM:       msgText = "Слишком много процессов\n";              break;
	case WSASYSNOTREADY:     msgText = "Сеть не доступна\n";                break;
	case WSAVERNOTSUPPORTED:   msgText = "Данная версия недоступна\n";            break;
	case WSANOTINITIALISED:     msgText = "Не выполнена инициализация WS2_32.DLL\n";      break;
	case WSAEDISCON:       msgText = "Выполняется отключение\n";              break;
	case WSATYPE_NOT_FOUND:     msgText = "Класс не найден\n";                  break;
	case WSAHOST_NOT_FOUND:     msgText = "Хост не найден\n";                  break;
	case WSAEINVALIDPROCTABLE:   msgText = "Ошибочный сервис\n";                break;
	case WSAEINVALIDPROVIDER:   msgText = "Ошибка в версии сервиса\n";              break;
	case WSAEPROVIDERFAILEDINIT: msgText = "Невозможно инициализировать сервис\n";        break;
	case WSASYSCALLFAILURE:     msgText = "Аварийное завершение системного вызова\n";      break;
	case WSATRY_AGAIN:       msgText = "Неавторизированный хост не найден\n";        break;
	case WSANO_RECOVERY:     msgText = "Неопределенная ошибка\n";              break;
	case WSANO_DATA:       msgText = "Нет записи запрошенного типа\n";          break;
	default:           msgText = "Ошибка не определена\n";              break;
	}
	return msgText;
}