#include "Account.h"

//Account::Account()
//	:id(0),balance(1)
//{
//	this->name = new char[5];
//	strcpy_s(this->name, 5, "abc");
//}

Account::Account(int id, const char* name, int balance)
	: id(id), balance(balance)
{
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Account::~Account()
{
	if (name != nullptr)
	{
		delete[] name;
	}
}

int Account::idGetter() const
{
	return id;
}

char* Account::nameGetter() const
{
	return name;
}

int Account::balanceGetter() const
{
	return balance;
}

void Account::balanceSetter(int money, int select)
{
	if (select == 0)
	{
		balance += money;
	}
	else if (select == 1)
	{
		balance -= money;
	}
}