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
		std::cout << "�̹� �ش� ���¹�ȣ�� ��ϵ� ���� �ֽ��ϴ�.\n";
	}
}

void Bank::Deposit(int id, int money)
{
	if (accountList[id] != nullptr)
	{
		accountList[id]->balanceSetter(money, 0);
		std::cout << "���� " << accountList[id]->idGetter()
			<< " " << accountList[id]->nameGetter() << "���� ���¿� " << money << "�� �Ա޿Ϸ�\n";
		std::cout << "���� �ܾ�: " << accountList[id]->balanceGetter() << "��\n";
	}
	else
	{
		std::cout << "�ش� ���¹�ȣ�� ���� �����Դϴ�.\n";
	}
}

void Bank::Withdraw(int id, int money)
{
	if (accountList[id] != nullptr)
	{
		if (accountList[id]->balanceGetter() >= money)
		{
			accountList[id]->balanceSetter(money, 1);
			std::cout << "���� " << accountList[id]->idGetter()
				<< " " << accountList[id]->nameGetter() << "���� ���¿��� " << money << "�� ��ݿϷ�\n";
			std::cout << "���� �ܾ�: " << accountList[id]->balanceGetter() << "��\n";
		}
		else
		{
			std::cout << "����� �ݾ��� �����մϴ�.\n";
		}
	}
	else
	{
		std::cout << "�ش� ���¹�ȣ�� ���� �����Դϴ�.\n";
	}
}

void Bank::Inquire()
{
	for (int i = 0; i < 100; i++) {
		if (accountList[i] != nullptr)
		{
			std::cout << "���¹�ȣ: " << accountList[i]->idGetter()
				<< " �� �̸�: " << accountList[i]->nameGetter()
				<< " ���� �ܾ�: " << accountList[i]->balanceGetter() << "\n";
		}
	}
}