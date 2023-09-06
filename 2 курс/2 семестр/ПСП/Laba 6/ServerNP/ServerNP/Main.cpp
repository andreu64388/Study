#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>


using namespace std;

string SetPipeError(string msgText, int code);
string GetPipeError(int code);

void main() 
{
    //..................................................................
    HANDLE hPipe; // дескриптор канала
    setlocale(LC_ALL, "RU");

    clock_t start, end;
    try
    {
        if ((hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\Tube"),
                                     PIPE_ACCESS_DUPLEX, //дуплексный канал
                                     PIPE_TYPE_MESSAGE | PIPE_WAIT, // сообщени€|синхронный
                                     1, NULL, NULL, // максимум 1 экземпл€р
                                     INFINITE, NULL)) == INVALID_HANDLE_VALUE)
            throw SetPipeError("create:", GetLastError());

        cout << "ќжидани€ клиента...\n";

        size_t count = 0;

        do {
            if (!ConnectNamedPipe(hPipe, NULL)) // ожидать клиента 
                throw SetPipeError("connect:", GetLastError());

            /////////////////////////////////////////////////////////////////////
   cout <<" лиент подключилс€!\n\n";

            const int BUFFSIZE = 512;
            WCHAR msg[BUFFSIZE];
            DWORD byteSize = (DWORD)(BUFFSIZE * 2);
            wstring swstr = L"Hello from server";
            wstring wstr;

            int i = 0;

            start = clock();
            wstring prev = L"";
            size_t countPrev = 0;
            do {
                ReadFile(hPipe, msg, BUFFSIZE, &byteSize, NULL);

                if (prev == wstring(msg)) 
                {
                    countPrev++;

                    if (countPrev > 0) 
                    {
                        break;
                    }
                }
                else 
                {
                    prev = wstring(msg);
                    countPrev = 0;
                }

                _tprintf_s(TEXT("%s\n"), msg);

                DWORD bs = BUFFSIZE * 2;

                wstr = swstr + L" "s + to_wstring(i++);

                WriteFile(hPipe, wstr.c_str(), BUFFSIZE, &bs, NULL);
            } while (wstring(msg) != L"");
            end = clock();

            cout << "\n¬рем€ затраченно на 1000 сообщений: " << end - start << "мс\n";

            /////////////////////////////////////////////////////////////////////

            DisconnectNamedPipe(hPipe);
            cout << " лиент отключилс€\n";

            count += i;
        } while (count < 10000);
    }
    catch (string ErrorPipeText)
    {
        cout << endl << ErrorPipeText;
    }

}

string SetPipeError(string msgText, int code)
{
    return msgText + GetPipeError(code);
}

string GetPipeError(int code)
{
    string msgText;
    switch (code)
    {
    case WSAEINTR:
        msgText = "Function interrupted";
        break;
    case WSAEACCES:
        msgText = "Permission denied";
        break;
    case WSAEFAULT:
        msgText = "Wrong address";
        break;
    case WSAEINVAL:
        msgText = "Wrong args";
        break;
    case WSAEMFILE:
        msgText = "Too many files have opened";
        break;
    case WSAEWOULDBLOCK:
        msgText = "Resource temporarily unavailable";
        break;
    case WSAEINPROGRESS:
        msgText = "Operation in progress";
        break;
    case WSAEALREADY:
        msgText = "Operation already in progress";
        break;
    case WSAENOTSOCK:
        msgText = "Wrong socket";
        break;
    case WSAEDESTADDRREQ:
        msgText = "Required adress location";
        break;
    case WSAEMSGSIZE:
        msgText = "Message is too long ";
        break;
    case WSAEPROTOTYPE:
        msgText = "Wrong protocol type to socket";
        break;
    case WSAENOPROTOOPT:
        msgText = "Error in protocol option";
        break;
    case WSAEPROTONOSUPPORT:
        msgText = "Protocol is not supported";
        break;
    case WSAESOCKTNOSUPPORT:
        msgText = "Socket type is not supported";
        break;
    case WSAEOPNOTSUPP:
        msgText = "Operation is not supported";
        break;
    case WSAEPFNOSUPPORT:
        msgText = "Protocol type is not supported";
        break;
    case WSAEAFNOSUPPORT:
        msgText = "Addresses type is not supported by protocol";
        break;
    case WSAEADDRINUSE:
        msgText = "Address is already used";
        break;
    case WSAEADDRNOTAVAIL:
        msgText = "Requested address cannot be used";
        break;
    case WSAENETDOWN:
        msgText = "Network disconnected";
        break;
    case WSAENETUNREACH:
        msgText = "Network is unttainable";
        break;
    case WSAENETRESET:
        msgText = "Network dropped the connection";
        break;
    case WSAECONNABORTED:
        msgText = "Connection aborted";
        break;
    case WSAECONNRESET:
        msgText = "Connection restored";
        break;
    case WSAENOBUFS:
        msgText = "Not enough memory for buffers";
        break;
    case WSAEISCONN:
        msgText = "Socket has already connected";
        break;
    case WSAENOTCONN:
        msgText = "Socket has not connected";
        break;
    case WSAESHUTDOWN:
        msgText = "Send cannot be performed: socket was shutdowned";
        break;
    case WSAETIMEDOUT:
        msgText = "Alloted time interval has ended";
        break;
    case WSAECONNREFUSED:
        msgText = "Connection was rejected";
        break;
    case WSAEHOSTDOWN:
        msgText = "Host was shotdowned";
        break;
    case WSAEHOSTUNREACH:
        msgText = "Has not way for host";
        break;
    case WSAEPROCLIM:
        msgText = "Too many processes";
        break;
    case WSASYSNOTREADY:
        msgText = "Network is unavailable";
        break;
    case WSAVERNOTSUPPORTED:
        msgText = "Version is not supported";
        break;
    case WSANOTINITIALISED:
        msgText = "WS2_32.dll is not initialised";
        break;
    case WSAEDISCON:
        msgText = "Connection in progress";
        break;
    case WSATYPE_NOT_FOUND:
        msgText = "Type is not found";
        break;
    case WSAHOST_NOT_FOUND:
        msgText = "Host is not found";
        break;
    case WSATRY_AGAIN:
        msgText = "Try again";
        break;
    case WSANO_RECOVERY:
        msgText = "Unknown error";
        break;
    case WSANO_DATA:
        msgText = "Has not data type";
        break;
    case WSAEINVALIDPROCTABLE:
        msgText = "Invalid provider";
        break;
    case WSAEINVALIDPROVIDER:
        msgText = "Error in provider version";
        break;
    case WSAEPROVIDERFAILEDINIT:
        msgText = "Failed provider initialization";
        break;
    case WSASYSCALLFAILURE:
        msgText = "Abnormal termination of a system call";
        break;
    default:
        msgText = "Unknown error";
        break;
    }
    return msgText;
}