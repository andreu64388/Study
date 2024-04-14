#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <locale>
#include <WinSock2.h>
#include <string>
#include "error_handler.h"
#include "CA.h"
#include "SOCKETS.h"
#pragma comment(lib, "WS2_32.lib")
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	WSADATA wsa_data;

	serv.sin_family = AF_INET;
	serv.sin_port = htons(2000);
	serv.sin_addr.s_addr = INADDR_ANY;

	memset(&clnt, 0, sizeof(clnt));
	int length_clnt = sizeof(clnt);

	bool close = false;
	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0)
			throw set_error_msg_text("Startup: ", WSAGetLastError());

		if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
			throw set_error_msg_text("socket: ", WSAGetLastError());

		if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
			throw set_error_msg_text("bind: ", WSAGetLastError());

		CA ca = InitCA("192.168.51.218", "Z:\\output.txt");

		while (true)
		{
			char input_buffer[1]{};
			char output_buffer[1]{};
			if (recvfrom(sS, input_buffer, sizeof input_buffer, NULL, (sockaddr*)&clnt, &length_clnt) == SOCKET_ERROR)
				throw set_error_msg_text("recvfrom: ", WSAGetLastError());
			if (input_buffer[0] == 'e' && !close)
			{
				if (EnterCA(ca))
				{
					output_buffer[0] = 'o';
					if (sendto(sS, output_buffer, sizeof output_buffer, NULL, (sockaddr*)&clnt, sizeof(clnt)) == SOCKET_ERROR)
						throw set_error_msg_text("sendto: ", WSAGetLastError());
					close = true;
				}
			}
			else if (input_buffer[0] == 'l')
			{
				if (LeaveCA(ca))
				{
					output_buffer[0] = 'l';
					if (sendto(sS, output_buffer, sizeof output_buffer, NULL, (sockaddr*)&clnt, sizeof(clnt)) == SOCKET_ERROR)
						throw set_error_msg_text("sendto: ", WSAGetLastError());
					close = false;
				}
			}
			else if (input_buffer[0] == 'e' && close)
			{
				output_buffer[0] = 'n';
				if (sendto(sS, output_buffer, sizeof output_buffer, NULL, (sockaddr*)&clnt, sizeof(clnt)) == SOCKET_ERROR)
					throw set_error_msg_text("sendto: ", WSAGetLastError());
				cout << "Denied: " << inet_ntoa(clnt.sin_addr) << ":" << clnt.sin_port << endl;
			}

			if (input_buffer[0] == 'c')
				break;
		}

		if (closesocket(sS) == SOCKET_ERROR)
			throw set_error_msg_text("closesocket: ", WSAGetLastError());

		if (WSACleanup() == SOCKET_ERROR)
			throw set_error_msg_text("Cleanup: ", WSAGetLastError());
	}
	catch (string error_msg_text)
	{
		cout << endl << error_msg_text << endl;
	}

	return 0;
}
