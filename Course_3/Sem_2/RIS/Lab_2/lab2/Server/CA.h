#pragma once
#include "SOCKETS.h"

struct CA
{
	char ipaddr[15];
	char resource[20];
	enum STATUS
	{
		NOINIT = 0,
		INIT,
		ENTER,
		WAIT,
		LEAVE
	} status;
};

CA InitCA(const char ipaddr[15], const char resource[20])
{
	CA ca{};
	memcpy(ca.ipaddr, ipaddr, sizeof(ipaddr));
	memcpy(ca.resource, resource, sizeof(resource));
	ca.status = CA::INIT;

	cout << "Section initialized\n";
	return ca;
}

bool EnterCA(CA& ca)
{
	cout << "Enter: " << inet_ntoa(clnt.sin_addr) << ":" << clnt.sin_port << "\t";
	if (ca.status == CA::INIT || ca.status == CA::WAIT)
	{
		ca.status = CA::ENTER;
		cout << "OK\n";
		return true;
	}
	cout << "FAIL\n";
	return false;
}

bool LeaveCA(CA& ca)
{
	cout << "Leave: " << inet_ntoa(clnt.sin_addr) << ":" << clnt.sin_port << "\t";
	if (ca.status == CA::ENTER)
	{
		ca.status = CA::WAIT;
		cout << "OK\n";
		return true;
	}

	cout << "Not entered\n";
	return false;
}

bool CloseCA(CA& ca)
{
	memset(&ca, 0, sizeof(ca));
	cout << "Section uninitialized\n";
	return true;
}