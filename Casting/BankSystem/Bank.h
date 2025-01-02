#pragma once
#include<iostream>

class Account;

class Bank
{
public:
	Bank();
	~Bank();

	void CreateAccount(int id, const char* name);
	void Deposit(int id, int money);
	void Withdraw(int id, int money);
	void Inquire();
private:
	Account* accountList[100]{};
};