#pragma once
#include "Global.h"

DWORD WINAPI DispathServer(LPVOID pPrm) {
	cout << "DispathServer работает\n";
	DWORD rc = 0;
	try {
		while (*((TalkersCommand*)pPrm) != EXIT) {//Условие выхода из цикла
			try {
				if (WaitForSingleObject(Event, 300) == WAIT_OBJECT_0) {//перешел в сигнальное состояние

					if (&ClientServiceNumber > (volatile LONG*)0) {
						Contact* client = NULL;
						int libuf = 1;
						char CallBuf[50] = "", SendError[50] = "ErrorInquiry";
						EnterCriticalSection(&scListContact);

						//должен последовательно просматривать список ListContact  (в котором хранятся все сведения о подключившихся клиентах)
						//и считывать запрос, подключившегося клиента
						for (ListContact::iterator p = Contacts.begin(); p != Contacts.end(); p++) {
							if (p->type == Contact::ACCEPT)
							{
								client = &(*p);

								//При обнаружении в списке подключившегося, но не обслуженного клиента (это можно определить  по специальным признакам, 
								//записанным в элемент списка) следует прочитать первое сообщение клиента (которое должно быть кодом запроса) с помощью
								//функции recv (раздел 3.11).
								bool flag = false;
								while (flag == false) {
									if ((libuf = recv(client->s, CallBuf, sizeof(CallBuf), NULL)) == SOCKET_ERROR) {
										switch (WSAGetLastError()) {
											case WSAEWOULDBLOCK: Sleep(100); break;
											default: throw  SetErrorMsgText("Recv:", WSAGetLastError());
										}
									}
									else flag = true;
								}

								if (flag == true) {//if Rand, Echo or Time
									string time_error;

									
									client->type = Contact::CONTACT;
									strcpy_s(client->srvname, CallBuf);

									//ожидающий таймер будет создаваться потоком AcceptServer
									//для каждого запущенного потока EchoSever.Сразу же после перехода
									//одного из ожидающих таймеров, в очередь асинхронных процедур потока
									//AcceptServer будет поставлена соответствующая процедура завершения.
									// 
									//переходит в сигнальное состояние через одну  минуту после запуска обслуживающего 
									//сервера (т.е. одна минута – это максимально допустимое время работы обслуживающего сервера).
									client->htimer = CreateWaitableTimer(NULL, false, NULL);
									_int64 time = -600000000;
									SetWaitableTimer(client->htimer, (LARGE_INTEGER*)&time, 0, ASWTimer, client, false);
									cout << CallBuf <<  " сервер вызван" << endl;
									if ((libuf = send(client->s, CallBuf, sizeof(CallBuf), NULL)) == SOCKET_ERROR) throw SetErrorMsgText("Send:", WSAGetLastError());
									client->hthread = sss(CallBuf, client);
								}
								else {
								//обслуживающий сервер, завершает свою работу до истечения  
								//установленного максимального интервала его работы
									if ((libuf = send(client->s, SendError, sizeof(SendError) + 1, NULL)) == SOCKET_ERROR) throw SetErrorMsgText("Send:", WSAGetLastError());
									closesocket(client->s);
									client->sthread = Contact::ABORT;
									CancelWaitableTimer(client->htimer);
									InterlockedIncrement(&Fail);
								}
							}
						}
						LeaveCriticalSection(&scListContact);
					}
					SleepEx(0, true);
				}
				SleepEx(0, true);
			}
			catch (string errorMsgText) {
				std::cout << errorMsgText << endl;
			}
		}
	}
	catch (string errorMsgText) {
		std::cout << errorMsgText << endl;
	}
	catch (...) {
		std::cout << "Error DispathServer" << std::endl;
	}
	cout << "DispathServer остановлен\n" << endl;
	ExitThread(rc);
}