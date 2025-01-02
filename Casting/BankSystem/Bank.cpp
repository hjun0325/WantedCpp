#include"Bank.h"
#include"Account.h"

Bank::Bank()
{
}

Bank::~Bank()
{
	for (int i = 0; i < 100; i++)
	{
		if (accountList[i] != nullptr)
		{
			delete accountList[i];
			accountList[i] == nullptr;
		}
	}
}

void Bank::CreateAccount(int id, const char* name)
{
	if (accountList[id] == nullptr)
	{
		accountList[id] = new Account(id, name, 0);
	}
	else
	{
		std::cout << "이미 해당 계좌번호로 등록된 고객이 있습니다.\n";
	}
}

void Bank::Deposit(int id, int money)
{
	if (accountList[id] != nullptr)
	{
		accountList[id]->balanceSetter(money, 0);
		std::cout << "계좌 " << accountList[id]->idGetter()
			<< " " << accountList[id]->nameGetter() << "님의 계좌에 " << money << "원 입급완료\n";
		std::cout << "현재 잔액: " << accountList[id]->balanceGetter() << "원\n";
	}
	else
	{
		std::cout << "해당 계좌번호는 없는 계좌입니다.\n";
	}
}

void Bank::Withdraw(int id, int money)
{
	if (accountList[id] != nullptr)
	{
		if (accountList[id]->balanceGetter() >= money)
		{
			accountList[id]->balanceSetter(money, 1);
			std::cout << "계좌 " << accountList[id]->idGetter()
				<< " " << accountList[id]->nameGetter() << "님의 계좌에서 " << money << "원 출금완료\n";
			std::cout << "현재 잔액: " << accountList[id]->balanceGetter() << "원\n";
		}
		else
		{
			std::cout << "출금할 금액이 부족합니다.\n";
		}
	}
	else
	{
		std::cout << "해당 계좌번호는 없는 계좌입니다.\n";
	}
}

void Bank::Inquire()
{
	for (int i = 0; i < 100; i++) {
		if (accountList[i] != nullptr)
		{
			std::cout << "계좌번호: " << accountList[i]->idGetter()
				<< " 고객 이름: " << accountList[i]->nameGetter()
				<< " 고객의 잔액: " << accountList[i]->balanceGetter() << "\n";
		}
	}
}