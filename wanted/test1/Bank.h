#pragma once
#include<iostream>

class Account;

class Bank
{
public:
	Bank();
	~Bank();

	void CreateAccount(int id, char* name, int balance);
	void Deposit();
	void Withdraw();
	void Inquire();
private:
	Account* accountList[100]{};
};