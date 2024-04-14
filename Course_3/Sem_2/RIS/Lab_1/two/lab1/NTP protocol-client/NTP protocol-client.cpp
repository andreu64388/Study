#include "Winsock2.h"
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "Errors.h"
#pragma warning( disable : 4996)

#pragma comment(lib, "WS2_32.lib")
using namespace std;

struct GETSINCHRO
{
	DWORD64 mTime;
};

struct SETSINCHRO
{
	__int64 corrTime;
};

DWORD64 GetLocalUnixTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int main()
{
	GetLocalUnixTime();

	string IP = "192.168.111.118";

	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		throw SetErrorMsgText("Startup: ", WSAGetLastError());

	while (true) {
		int TC = 1000;
		int maxcorr = 0, mincorr = INT_MAX;
		__int64 mcorr = 0;
		__int64 mCcOs = 0;

		DWORD64 ClientTime = 0;
		SOCKET clientSocket;
		cout << "Enter TC: ";
		cin >> TC;

		try
		{
			if ((clientSocket = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
				throw SetErrorMsgText("Socket: ", WSAGetLastError());

			SOCKADDR_IN serverParameters;
			serverParameters.sin_family = AF_INET;
			serverParameters.sin_port = htons(2000);
			serverParameters.sin_addr.s_addr = inet_addr(IP.c_str());

			GETSINCHRO gs;
			SETSINCHRO ss;
			ss.corrTime = 0;
			gs.mTime = 0;

			sendto(clientSocket, (char*)&gs, sizeof(gs), 0, (sockaddr*)&serverParameters, sizeof(serverParameters));
			int lc = sizeof(serverParameters);
			if ((recvfrom(clientSocket, (char*)&ss, sizeof(ss), NULL, (sockaddr*)&serverParameters, &lc)) == SOCKET_ERROR)
				throw SetErrorMsgText("Get time: ", WSAGetLastError()); 
			ClientTime = ss.corrTime;
			cout << " * Init sync:" << ss.corrTime << endl << endl;

			for (int i = 0; i < 10; i++)
			{
				Sleep(TC);
				//посылаем серверу запрос со своим временем
				ClientTime = gs.mTime = (DWORD64)ClientTime + TC;
				sendto(clientSocket, (char*)&gs, sizeof(gs), 0, (sockaddr*)&serverParameters, sizeof(serverParameters));

				//получаем с сервера корректировку
				int lc = sizeof(serverParameters);
				if ((recvfrom(clientSocket, (char*)&ss, sizeof(ss), NULL, (sockaddr*)&serverParameters, &lc)) == SOCKET_ERROR)
					throw SetErrorMsgText("RecvFrom: ", WSAGetLastError());

				DWORD64 localUnixTime = GetLocalUnixTime();
				ClientTime = (ClientTime + ss.corrTime);
				mcorr = (mcorr + ss.corrTime);
				mCcOs = (mCcOs + (ClientTime - localUnixTime));
				maxcorr = (maxcorr < ss.corrTime) ? ss.corrTime : maxcorr;
				mincorr = (mincorr > ss.corrTime) ? ss.corrTime : mincorr;

				cout << "Client time: " << ClientTime << " Local time: " << localUnixTime << " Correction: " << ss.corrTime << endl;
				if (ClientTime > localUnixTime)
				{
					cout << "The local time is " << ClientTime - localUnixTime << " behind of the global" << endl;
				}
				else
				{
					cout << "The local time is " << localUnixTime - ClientTime << " ms ahead of the the global" << endl;
				}
				cout << endl;
			}
			cout << endl << "delay on the client: " << TC << endl;
			cout << "avg correction: " << mcorr / 10.0 << endl;
			cout << "avg CC - OStime: " << mCcOs / 10.0 << endl;
			cout << "max correction: " << maxcorr << endl;
			cout << "min correction: " << mincorr << endl << endl;

			if (closesocket(clientSocket) == SOCKET_ERROR)
				throw SetErrorMsgText("Closesocket: ", WSAGetLastError());
		}
		catch (string errorMsgText)
		{
			cout << endl << errorMsgText << endl;
		}

		system("pause");
	}
	if (WSACleanup() == SOCKET_ERROR)
		throw SetErrorMsgText("Cleanup: ", WSAGetLastError());
	return 0;
}