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
	case WSAEINTR:				 msg_text = "Работа функции прервана\n";						  break;
	case WSAEACCES:				 msg_text = "Разрешение отвергнуто\n";						  break;
	case WSAEFAULT:				 msg_text = "Ошибочный адрес\n";								  break;
	case WSAEINVAL:				 msg_text = "Ошибка в аргументе\n";							  break;
	case WSAEMFILE:				 msg_text = "Слишком много файлов открыто\n";				  break;
	case WSAEWOULDBLOCK:		 msg_text = "Ресурс временно недоступен\n";					  break;
	case WSAEINPROGRESS:		 msg_text = "Операция в процессе развития\n";				  break;
	case WSAEALREADY: 			 msg_text = "Операция уже выполняется\n";					  break;
	case WSAENOTSOCK:   		 msg_text = "Сокет задан неправильно\n";						  break;
	case WSAEDESTADDRREQ:		 msg_text = "Требуется адрес расположения\n";				  break;
	case WSAEMSGSIZE:  			 msg_text = "Сообщение слишком длинное\n";				      break;
	case WSAEPROTOTYPE:			 msg_text = "Неправильный тип протокола для сокета\n";		  break;
	case WSAENOPROTOOPT:		 msg_text = "Ошибка в опции протокола\n";					  break;
	case WSAEPROTONOSUPPORT:	 msg_text = "Протокол не поддерживается\n";					  break;
	case WSAESOCKTNOSUPPORT:	 msg_text = "Тип сокета не поддерживается\n";				  break;
	case WSAEOPNOTSUPP:			 msg_text = "Операция не поддерживается\n";					  break;
	case WSAEPFNOSUPPORT:		 msg_text = "Тип протоколов не поддерживается\n";			  break;
	case WSAEAFNOSUPPORT:		 msg_text = "Тип адресов не поддерживается протоколом\n";	  break;
	case WSAEADDRINUSE:			 msg_text = "Адрес уже используется\n";						  break;
	case WSAEADDRNOTAVAIL:		 msg_text = "Запрошенный адрес не может быть использован\n";	  break;
	case WSAENETDOWN:			 msg_text = "Сеть отключена\n";								  break;
	case WSAENETUNREACH:		 msg_text = "Сеть не достижима\n";							  break;
	case WSAENETRESET:			 msg_text = "Сеть разорвала соединение\n";					  break;
	case WSAECONNABORTED:		 msg_text = "Программный отказ связи\n";						  break;
	case WSAECONNRESET:			 msg_text = "Связь восстановлена\n";							  break;
	case WSAENOBUFS:			 msg_text = "Не хватает памяти для буферов\n";				  break;
	case WSAEISCONN:			 msg_text = "Сокет уже подключен\n";							  break;
	case WSAENOTCONN:			 msg_text = "Сокет не подключен\n";							  break;
	case WSAESHUTDOWN:			 msg_text = "Нельзя выполнить send: сокет завершил работу\n";  break;
	case WSAETIMEDOUT:			 msg_text = "Закончился отведенный интервал  времени\n";		  break;
	case WSAECONNREFUSED:		 msg_text = "Соединение отклонено\n";						  break;
	case WSAEHOSTDOWN:			 msg_text = "Хост в неработоспособном состоянии\n";			  break;
	case WSAEHOSTUNREACH:		 msg_text = "Нет маршрута для хоста\n";						  break;
	case WSAEPROCLIM:			 msg_text = "Слишком много процессов\n";						  break;
	case WSASYSNOTREADY:		 msg_text = "Сеть не доступна\n";							  break;
	case WSAVERNOTSUPPORTED:	 msg_text = "Данная версия недоступна\n";					  break;
	case WSANOTINITIALISED:		 msg_text = "Не выполнена инициализация WS2_32.DLL\n";		  break;
	case WSAEDISCON:			 msg_text = "Выполняется отключение\n";						  break;
	case WSATYPE_NOT_FOUND:		 msg_text = "Класс не найден\n";								  break;
	case WSAHOST_NOT_FOUND:		 msg_text = "Хост не найден\n";								  break;
	case WSATRY_AGAIN:			 msg_text = "Неавторизированный хост не найден\n";			  break;
	case WSANO_RECOVERY:		 msg_text = "Неопределенная ошибка\n";						  break;
	case WSANO_DATA:			 msg_text = "Нет записи запрошенного типа\n";				  break;
	case WSA_INVALID_HANDLE:	 msg_text = "Указанный дескриптор события  с ошибкой\n";		  break;
	case WSA_INVALID_PARAMETER:	 msg_text = "Один или более параметров с ошибкой\n";			  break;
	case WSA_IO_INCOMPLETE:		 msg_text = "Объект ввода-вывода не в сигнальном состоянии\n"; break;
	case WSA_IO_PENDING:		 msg_text = "Операция завершится позже\n";					  break;
	case WSA_NOT_ENOUGH_MEMORY:	 msg_text = "Не достаточно памяти\n";						  break;
	case WSA_OPERATION_ABORTED:	 msg_text = "Операция отвергнута\n";							  break;
	case WSAEINVALIDPROCTABLE:	 msg_text = "Ошибочный сервис\n";							  break;
	case WSAEINVALIDPROVIDER:	 msg_text = "Ошибка в версии сервиса\n";						  break;
	case WSAEPROVIDERFAILEDINIT: msg_text = "Невозможно инициализировать сервис\n";			  break;
	case WSASYSCALLFAILURE:		 msg_text = "Аварийное завершение системного вызова\n";		  break;
	default:					 msg_text = "Error\n";										  break;
	}

	return msg_text;
}

string set_error_msg_text(const string& msg_text, const int code)
{
	return  msg_text + get_error_msg_text(code);
}

