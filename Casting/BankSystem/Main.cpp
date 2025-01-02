#include<iostream>
#include"Bank.h"

int main()
{
	Bank bank;
	while (1)
	{
		std::cout << "1��-���� ���� / 2��-�Ա� / 3��-��� / 4��-��ü �� �ܾ� ��ȸ / q - ����\n";
		std::cout << "��ȣ�� �Է��ϼ���:";
		char num = 0;
		std::cin >> num;

		int id;
		char name[20];
		int money;
		if (num == '1')
		{
			std::cout << "����Ͻ� ���� ��ȣ�� �̸��� �Է��ϼ���\n";
			std::cout << "���¹�ȣ: "; std::cin >> id;
			std::cout << "�� �̸�: "; std::cin >> name;
			bank.CreateAccount(id, name);
		}
		else if (num == '2')
		{
			std::cout << "�Ա��Ͻ� ���¹�ȣ�� �ݾ��� �Է����ּ���\n";
			std::cout << "���¹�ȣ: "; std::cin >> id;
			std::cout << "�Ա��� �ݾ�: "; std::cin >> money;
			if (money > 0)
			{
				bank.Deposit(id, money);
			}
			else
			{
				std::cout << "�ٽ� �Է����ּ���\n";
			}
		}
		else if (num == '3')
		{
			std::cout << "����Ͻ� ���¹�ȣ�� �ݾ��� �Է����ּ���\n";
			std::cout << "���¹�ȣ: "; std::cin >> id;
			std::cout << "����� �ݾ�: "; std::cin >> money;
			if (money > 0)
			{
				bank.Withdraw(id, money);
			}
			else
			{
				std::cout << "�ٽ� �Է����ּ���\n";
			}
		}
		else if (num == '4')
		{
			bank.Inquire();
		}
		else if (num == 'q')
		{
			std::cout << "����\n";
			break;
		}
		else {
			std::cout << "�ٽ� �Է����ּ���\n";
		}
	}
}