#pragma once

#include "pch.h"
#include "Winsock2.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#pragma comment(lib, "WS2_32.lib")

using namespace std;

string GetErrorMsgText(int code)
{
	string msgText;

	switch (code)
	{
	case WSAEINTR:				 msgText = "Functinon interrupted\n";							break;
	case WSAEACCES:				 msgText = "Access denied\n";									break;
	case WSAEFAULT:				 msgText = "Wrong address\n";									break;
	case WSAEINVAL:				 msgText = "Error in arguments\n";								break;
	case WSAEMFILE:				 msgText = "Too many files opened\n";							break;
	case WSAEWOULDBLOCK:		 msgText = "Resource is temperary not available\n";				break;
	case WSAEINPROGRESS:		 msgText = "Operation is in progress\n";						break;
	case WSAEALREADY: 			 msgText = "Operation is already running\n";					break;
	case WSAENOTSOCK:   		 msgText = "Wron socket\n";										break;
	case WSAEDESTADDRREQ:		 msgText = "Destination address is required\n";					break;
	case WSAEMSGSIZE:  			 msgText = "Too long message\n";								break;
	case WSAEPROTOTYPE:			 msgText = "Wrong type of protocol\n";							break;
	case WSAENOPROTOOPT:		 msgText = "Error in protocol option\n";						break;
	case WSAEPROTONOSUPPORT:	 msgText = "Protocol is not supported\n";						break;
	case WSAESOCKTNOSUPPORT:	 msgText = "Socket type is not supported\n";					break;
	case WSAEOPNOTSUPP:			 msgText = "Operation is not supported\n";						break;
	case WSAEPFNOSUPPORT:		 msgText = "Protocol type is not supported\n";					break;
	case WSAEAFNOSUPPORT:		 msgText = "Address family is not supported\n";					break;
	case WSAEADDRINUSE:			 msgText = "Address is used already\n";							break;
	case WSAEADDRNOTAVAIL:		 msgText = "Address is not available\n";						break;
	case WSAENETDOWN:			 msgText = "Network is down\n";									break;
	case WSAENETUNREACH:		 msgText = "Network cannot be reached\n";						break;
	case WSAENETRESET:			 msgText = "Network reset\n";									break;
	case WSAECONNABORTED:		 msgText = "Connection aborted\n";								break;
	case WSAECONNRESET:			 msgText = "Connection reset\n";								break;
	case WSAENOBUFS:			 msgText = "Not enough menory for buffer\n";					break;
	case WSAEISCONN:			 msgText = "Socket is already connected\n";						break;
	case WSAENOTCONN:			 msgText = "Socket is not connected\n";							break;
	case WSAESHUTDOWN:			 msgText = "Cannot execute send: the socket has shut down\n";   break;
	case WSAETIMEDOUT:			 msgText = "Timeout exceeded\n";								break;
	case WSAECONNREFUSED:		 msgText = "Connection refused\n";								break;
	case WSAEHOSTDOWN:			 msgText = "Host is unhandled\n";								break;
	case WSAEHOSTUNREACH:		 msgText = "There is no route for host\n";						break;
	case WSAEPROCLIM:			 msgText = "Too many processes\n";								break;
	case WSASYSNOTREADY:		 msgText = "Network is not ready\n";							break;
	case WSAVERNOTSUPPORTED:	 msgText = "The current version is not available\n";			break;
	case WSANOTINITIALISED:		 msgText = "WS2_32.DLL was not initialized\n";					break;
	case WSAEDISCON:			 msgText = "Disconect in progress\n";						    break;
	case WSATYPE_NOT_FOUND:		 msgText = "Class not found\n";								    break;
	case WSAHOST_NOT_FOUND:		 msgText = "How not found\n";								    break;
	case WSATRY_AGAIN:			 msgText = "Unauthorized host not found\n";						break;
	case WSANO_RECOVERY:		 msgText = "Undetermined error\n";								break;
	case WSANO_DATA:			 msgText = "There is no requested data\n";						break;
	case WSAEINVALIDPROCTABLE:	 msgText = "Wron service\n";									break;
	case WSAEINVALIDPROVIDER:	 msgText = "Service version error\n";							break;
	case WSAEPROVIDERFAILEDINIT: msgText = "Unable to initiate service\n";						break;
	case WSASYSCALLFAILURE:		 msgText = "System call failure\n";								break;
	default:					 msgText = "Unknown Error\n";									break;
	};

	return msgText;
}

string SetErrorMsgText(string msgText, int code)
{
	return  msgText + GetErrorMsgText(code);
};