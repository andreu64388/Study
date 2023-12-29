#pragma comment(lib, "WS2_32.lib") 
#pragma warning(disable: 4996)
#include "Winsock2.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string SetErrorMsgText(string msgText, int code);
string GetErrorMsgText(int code);
bool  GetServer(
	char* name ,
	short            port,    
	struct sockaddr* from, 
	int* flen  
);

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	SOCKET cS;
	WSADATA wsaData;
	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
			throw SetErrorMsgText("Startup:", WSAGetLastError());
		//............................................................
		if ((cS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
			throw SetErrorMsgText("socket:", WSAGetLastError());
		//.............................................................	

		SOCKADDR_IN serv; // параметры сокета сервера


		
		char name[] = "Hello";
		
		int lc = sizeof(serv);
		int lobuf = 0; //количество отправленных байьs

		if (GetServer(name, cS, (sockaddr*)&serv, &lc))
		{
			cout << "Connected server: " << endl;
			cout << "IP: " << inet_ntoa(serv.sin_addr) << endl;
			cout << "Port: " << htons(serv.sin_port) << endl;
		}
		else {
			cout << "Error connected server";
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
bool  GetServer(
	char* name,
	short            port,
	struct sockaddr* from,
	int* flen)
	{
	((SOCKADDR_IN*)from)->sin_family = AF_INET;
	((SOCKADDR_IN*)from)->sin_port = htons(2000);
	((SOCKADDR_IN*)from)->sin_addr.s_addr = INADDR_BROADCAST; /*inet_addr("192.168.241.146");*/
	int lbuf;
	char ibuf[50];
	int optval = 1;


	if (setsockopt(port, SOL_SOCKET, SO_BROADCAST, (char*)&optval, sizeof(optval)) == SOCKET_ERROR)
		throw SetErrorMsgText("opt: ", WSAGetLastError());

	if (lbuf = sendto(port, name, strlen(name) + 1, NULL, from, *flen) == SOCKET_ERROR)
		throw SetErrorMsgText("sendto: ", WSAGetLastError());

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


string  SetErrorMsgText(string msgText, int code)
{
	return  msgText + GetErrorMsgText(code);
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


/*INADDR_BROADCAST. INADDR_BROADCAST - это широковещательный адрес IPv4, который обозначает все устройства в текущей сети.*/

/*SO_BROADCAST, которая позволяет отправлять сообщения на широковещательный адрес. Функция setsockopt принимает три аргумента: дескриптор сокета, уровень опций (в данном случае SOL_SOCKET, что означает уровень опций сокета), и указатель на значение опции (в данном случае указатель на переменную optval, которая имеет значение 1).*/