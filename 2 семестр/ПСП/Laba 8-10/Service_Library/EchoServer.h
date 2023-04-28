#pragma once
#include "Global.h"

//ServerT
//потоковая функция, обеспечивающая прием данных от подключившегося клиента, и пересылку  этих же  данных обратно без изменения. 
DWORD WINAPI EchoServer(LPVOID lParam) {
	DWORD rc = 0; // Код возврата
	Contact* client = (Contact*)lParam;
	char ibuf[50], obuf[50] = "Close: finish;";

	try 
	{
		QueueUserAPC(ASStartMessage, client->hAcceptServer, (DWORD)client);	// Ставим в очередь асинхронную процедуру сообщение о старте обслуживания
	
		client->sthread = Contact::WORK;
		while (client->TimerOff == false) {	// Принимаем данные из сокета
			if (recv(client->s, ibuf, sizeof(ibuf), NULL) == SOCKET_ERROR) {// Принимаем данные
				if (WSAGetLastError() == WSAEWOULDBLOCK) Sleep(100);
				else throw  SetErrorMsgText("Recv:", WSAGetLastError());
			}
			else {
				if (strcmp(ibuf, "exit") != 0) {
					if (client->TimerOff != false) break;	// Проверяем метку срабатывания таймера
					if ((send(client->s, ibuf, sizeof(ibuf), NULL)) == SOCKET_ERROR) throw  SetErrorMsgText("Send:", WSAGetLastError());// Отправляем обратно
				}
				else break;
			}
		}
		if (client->TimerOff == false) {
			CancelWaitableTimer(client->htimer);	// Отключаем таймер
			if ((send(client->s, obuf, sizeof(obuf) + 1, NULL)) == SOCKET_ERROR) throw  SetErrorMsgText("Send:", WSAGetLastError());
			client->sthread = Contact::FINISH;
			QueueUserAPC(ASFinishMessage, client->hAcceptServer, (DWORD)client);	// Ставим в очередь асинхронную процедуру сообщение о завершении обслуживания
		}
	}
	catch (string errorMsgText) {
		std::cout << errorMsgText << std::endl;
		CancelWaitableTimer(client->htimer);
		client->sthread = Contact::ABORT;
	}
	ExitThread(rc);
}