#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable : 4996)
#include "Global.h"


static void WaitClients() {
	bool ListEmpty = false;
	while (!ListEmpty) {
		EnterCriticalSection(&scListContact);
		ListEmpty = Contacts.empty();
		LeaveCriticalSection(&scListContact);
		SleepEx(0, TRUE);
	}
}

//squirt явл максимальным количеством 
//итераций выполнения функции accept(в режиме без блокировки) для
//подключения клиента за один вызов функции AcceptCylcle.
bool AcceptCycle(int squirt, SOCKET* s) {
	bool rc = false;
	Contact c(Contact::ACCEPT, "EchoServer");
	c.hAcceptServer = hAcceptServer;

	// цикл проверки очереди подключений, повторяется squirt раз
	//while(squirt-- > 0 && rc == false)
	//{
	if ((c.s = accept(*s, (sockaddr*)&c.prms, &c.lprms)) == INVALID_SOCKET) {
		if (WSAGetLastError() != WSAEWOULDBLOCK) throw  SetErrorMsgText("Accept:", WSAGetLastError()); //если очередь подключений пуста.
	}
	else {
		rc = true;
		InterlockedIncrement(&Accept);
		InterlockedIncrement(&ClientServiceNumber);
		EnterCriticalSection(&scListContact);
		Contacts.push_front(c);
		LeaveCriticalSection(&scListContact);
		SetEvent(Event);
	}
	//}
	return rc;
};


void CommandsCycle(TalkersCommand& cmd, SOCKET* s)
{
	int squirt = 0; 
	while (cmd != EXIT) // цикл обработки команд консоли и подключений
	{
		switch (cmd) {	//GETCOMMAND Если команда принята функцией на обработку (готова к приему новой команды управления)
		case START:		cmd = GETCOMMAND;	// возобновить подключение клиентов
						squirt = AS_SQUIRT;
						break;

		case STOP:		cmd = GETCOMMAND;	// остановить подключение клиентов
						squirt = 0;
						break;

		case WAIT:		WaitClients();
						cmd = GETCOMMAND;
						squirt = 0;
						cmd = START;
						break;

		case SHUTDOWN:	WaitClients();
						cmd = EXIT;
						break;
		};
		if (cmd != EXIT && squirt > ClientServiceNumber) {
			if (AcceptCycle(squirt, s)) { //цикл запрос/подключение (accept)
				cmd = GETCOMMAND;
			}
			SleepEx(0, TRUE); // выполнить асинхронные процедуры
		}
	}
};

DWORD WINAPI AcceptServer(LPVOID pPrm) {
	cout << "AcceptServer работает\n";
	DWORD rc = 0;
	SOCKET  ServerSocket;
	WSADATA wsaData;

	try {
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) throw  SetErrorMsgText("Startup:", WSAGetLastError());
		if ((ServerSocket = socket(AF_INET, SOCK_STREAM, NULL)) == INVALID_SOCKET) throw  SetErrorMsgText("Socket:", WSAGetLastError());

		SOCKADDR_IN Server_IN;
		Server_IN.sin_family = AF_INET;
		Server_IN.sin_port = htons(port);
		Server_IN.sin_addr.s_addr = ADDR_ANY;
		/*Server_IN.sin_addr.s_addr = inet_addr("127.0.0.1");*/

		if (bind(ServerSocket, (LPSOCKADDR)&Server_IN, sizeof(Server_IN)) == SOCKET_ERROR) throw  SetErrorMsgText("Bind:", WSAGetLastError());
		if (listen(ServerSocket, SOMAXCONN) == SOCKET_ERROR) throw  SetErrorMsgText("Listen:", WSAGetLastError());

		//позволяет избежать приостановки программы
		//выполнение accept, не приостанавливает выполнение потока, 
		//как это было прежде, а возвращает значение нового сокета, если обнаружен
		//запрос на создание канала(функция connect, выполненная клиентом), или
		//значение INVALID_SOCKET, если запроса на создание канала нет в очереди
		//запросов или возникла ошибка.
		u_long nonblk;
		if (ioctlsocket(ServerSocket, FIONBIO, &(nonblk = 1)) == SOCKET_ERROR) throw SetErrorMsgText("Ioctlsocket:", WSAGetLastError());

		TalkersCommand* command = (TalkersCommand*)pPrm;
		CommandsCycle(*((TalkersCommand*)command), &ServerSocket);

		if (closesocket(ServerSocket) == SOCKET_ERROR) throw  SetErrorMsgText("Сlosesocket:", WSAGetLastError());
		if (WSACleanup() == SOCKET_ERROR) throw  SetErrorMsgText("Cleanup:", WSAGetLastError());
	}
	catch (string errorMsgText) {
		std::cout << errorMsgText << endl;
	}
	catch (...) {
		cout << "AcceptServer error" << endl;
	}
	cout << "AcceptServer остановлен\n" << endl;
	ExitThread(rc);
}

