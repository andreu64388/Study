#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <chrono>
#include <ctime>
#include "error_handler.h"
#pragma warning(disable:4996)
#pragma comment(lib, "WS2_32.lib")

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    WSADATA wsa_data;

    SOCKADDR_IN serv{};
    serv.sin_family = AF_INET;
    serv.sin_port = htons(2000);
    serv.sin_addr.s_addr = inet_addr("192.168.82.118");
    int length_serv = sizeof(serv);

    try
    {
        SOCKET cC;
        if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0)
            throw set_error_msg_text("Startup: ", WSAGetLastError());

        if ((cC = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
            throw set_error_msg_text("socket: ", WSAGetLastError());

        cout << "Client started\n ";
        
        
        char ibuf[1024]; 

        while (true)
        {
            char obuf[1]{ 'e' };
            if (sendto(cC, obuf, sizeof obuf, NULL, (sockaddr*)&serv, sizeof(serv)) == SOCKET_ERROR)
                throw set_error_msg_text("sendto: ", WSAGetLastError());
            if (recvfrom(cC, ibuf, sizeof ibuf, NULL, (sockaddr*)&serv, &length_serv) == SOCKET_ERROR)
                throw set_error_msg_text("recvfrom: ", WSAGetLastError());
            if (ibuf[0] == 'o')
            {
                cout << "Client opened\n";

                string file_name = "Z:\\output.txt"; 
                ofstream fout(file_name, ios::app);
                if (!fout.is_open())
                    throw "Error while opening file";

                for (int i = 0; i < 5; i++)
                {
                    cout << "Writing text\n";
                    auto end = chrono::system_clock::now();
                    time_t end_time = std::chrono::system_clock::to_time_t(end);
                    fout << "Client " << std::ctime(&end_time) << endl;
                    Sleep(3000);
                }
                fout << endl;

                obuf[0] = 'l';
                if (sendto(cC, obuf, sizeof obuf, NULL, (sockaddr*)&serv, sizeof(serv)) == SOCKET_ERROR)
                    throw set_error_msg_text("sendto: ", WSAGetLastError());
                if (recvfrom(cC, ibuf, sizeof ibuf, NULL, (sockaddr*)&serv, &length_serv) == SOCKET_ERROR)
                    throw set_error_msg_text("recvfrom: ", WSAGetLastError());
                if (ibuf[0] == 'l')
                    cout << "Leave" << endl;
                break;
            }
            if (ibuf[0] == 'n')
            {
                cout << "Wait for other clients...\n";
                Sleep(2000);
            }
        }

        if (closesocket(cC) == SOCKET_ERROR)
            throw set_error_msg_text("closesocket: ", WSAGetLastError());

        if (WSACleanup() == SOCKET_ERROR)
            throw set_error_msg_text("Cleanup: ", WSAGetLastError());
    }
    catch (string error_msg_text)
    {
        cout << endl << error_msg_text << endl;
    }
    catch (const char* error)
    {
        cout << endl << error << endl;
    }

    return 0;
}
