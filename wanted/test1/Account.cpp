#include "Account.h"

Account::Account(int id, char* name, int balance)
	: id(id), name(name), balance(balance)
{

}

Account::~Account()
{
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