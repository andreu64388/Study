#pragma once
#pragma once
#include <WinSock2.h>
#include <string>

using namespace std;

string get_error_msg_text(int code)
{
	string msg_text;

	switch (code)
	{
	case WSAEINTR:				 msg_text = "������ ������� ��������\n";						  break;
	case WSAEACCES:				 msg_text = "���������� ����������\n";						  break;
	case WSAEFAULT:				 msg_text = "��������� �����\n";								  break;
	case WSAEINVAL:				 msg_text = "������ � ���������\n";							  break;
	case WSAEMFILE:				 msg_text = "������� ����� ������ �������\n";				  break;
	case WSAEWOULDBLOCK:		 msg_text = "������ �������� ����������\n";					  break;
	case WSAEINPROGRESS:		 msg_text = "�������� � �������� ��������\n";				  break;
	case WSAEALREADY: 			 msg_text = "�������� ��� �����������\n";					  break;
	case WSAENOTSOCK:   		 msg_text = "����� ����� �����������\n";						  break;
	case WSAEDESTADDRREQ:		 msg_text = "��������� ����� ������������\n";				  break;
	case WSAEMSGSIZE:  			 msg_text = "��������� ������� �������\n";				      break;
	case WSAEPROTOTYPE:			 msg_text = "������������ ��� ��������� ��� ������\n";		  break;
	case WSAENOPROTOOPT:		 msg_text = "������ � ����� ���������\n";					  break;
	case WSAEPROTONOSUPPORT:	 msg_text = "�������� �� ��������������\n";					  break;
	case WSAESOCKTNOSUPPORT:	 msg_text = "��� ������ �� ��������������\n";				  break;
	case WSAEOPNOTSUPP:			 msg_text = "�������� �� ��������������\n";					  break;
	case WSAEPFNOSUPPORT:		 msg_text = "��� ���������� �� ��������������\n";			  break;
	case WSAEAFNOSUPPORT:		 msg_text = "��� ������� �� �������������� ����������\n";	  break;
	case WSAEADDRINUSE:			 msg_text = "����� ��� ������������\n";						  break;
	case WSAEADDRNOTAVAIL:		 msg_text = "����������� ����� �� ����� ���� �����������\n";	  break;
	case WSAENETDOWN:			 msg_text = "���� ���������\n";								  break;
	case WSAENETUNREACH:		 msg_text = "���� �� ���������\n";							  break;
	case WSAENETRESET:			 msg_text = "���� ��������� ����������\n";					  break;
	case WSAECONNABORTED:		 msg_text = "����������� ����� �����\n";						  break;
	case WSAECONNRESET:			 msg_text = "����� �������������\n";							  break;
	case WSAENOBUFS:			 msg_text = "�� ������� ������ ��� �������\n";				  break;
	case WSAEISCONN:			 msg_text = "����� ��� ���������\n";							  break;
	case WSAENOTCONN:			 msg_text = "����� �� ���������\n";							  break;
	case WSAESHUTDOWN:			 msg_text = "������ ��������� send: ����� �������� ������\n";  break;
	case WSAETIMEDOUT:			 msg_text = "���������� ���������� ��������  �������\n";		  break;
	case WSAECONNREFUSED:		 msg_text = "���������� ���������\n";						  break;
	case WSAEHOSTDOWN:			 msg_text = "���� � ����������������� ���������\n";			  break;
	case WSAEHOSTUNREACH:		 msg_text = "��� �������� ��� �����\n";						  break;
	case WSAEPROCLIM:			 msg_text = "������� ����� ���������\n";						  break;
	case WSASYSNOTREADY:		 msg_text = "���� �� ��������\n";							  break;
	case WSAVERNOTSUPPORTED:	 msg_text = "������ ������ ����������\n";					  break;
	case WSANOTINITIALISED:		 msg_text = "�� ��������� ������������� WS2_32.DLL\n";		  break;
	case WSAEDISCON:			 msg_text = "����������� ����������\n";						  break;
	case WSATYPE_NOT_FOUND:		 msg_text = "����� �� ������\n";								  break;
	case WSAHOST_NOT_FOUND:		 msg_text = "���� �� ������\n";								  break;
	case WSATRY_AGAIN:			 msg_text = "������������������ ���� �� ������\n";			  break;
	case WSANO_RECOVERY:		 msg_text = "�������������� ������\n";						  break;
	case WSANO_DATA:			 msg_text = "��� ������ ������������ ����\n";				  break;
	case WSA_INVALID_HANDLE:	 msg_text = "��������� ���������� �������  � �������\n";		  break;
	case WSA_INVALID_PARAMETER:	 msg_text = "���� ��� ����� ���������� � �������\n";			  break;
	case WSA_IO_INCOMPLETE:		 msg_text = "������ �����-������ �� � ���������� ���������\n"; break;
	case WSA_IO_PENDING:		 msg_text = "�������� ���������� �����\n";					  break;
	case WSA_NOT_ENOUGH_MEMORY:	 msg_text = "�� ���������� ������\n";						  break;
	case WSA_OPERATION_ABORTED:	 msg_text = "�������� ����������\n";							  break;
	case WSAEINVALIDPROCTABLE:	 msg_text = "��������� ������\n";							  break;
	case WSAEINVALIDPROVIDER:	 msg_text = "������ � ������ �������\n";						  break;
	case WSAEPROVIDERFAILEDINIT: msg_text = "���������� ���������������� ������\n";			  break;
	case WSASYSCALLFAILURE:		 msg_text = "��������� ���������� ���������� ������\n";		  break;
	default:					 msg_text = "Error\n";										  break;
	}

	return msg_text;
}

string set_error_msg_text(const string& msg_text, const int code)
{
	return  msg_text + get_error_msg_text(code);
}

