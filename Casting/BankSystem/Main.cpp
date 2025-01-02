#include<iostream>
#include"Bank.h"

int main()
{
	Bank bank;
	while (1)
	{
		std::cout << "1번-계좌 개설 / 2번-입금 / 3번-출금 / 4번-전체 고객 잔액 조회 / q - 종료\n";
		std::cout << "번호를 입력하세요:";
		char num = 0;
		std::cin >> num;

		int id;
		char name[20];
		int money;
		if (num == '1')
		{
			std::cout << "사용하실 계좌 번호와 이름을 입력하세요\n";
			std::cout << "계좌번호: "; std::cin >> id;
			std::cout << "고객 이름: "; std::cin >> name;
			bank.CreateAccount(id, name);
		}
		else if (num == '2')
		{
			std::cout << "입금하실 계좌번호와 금액을 입력해주세요\n";
			std::cout << "계좌번호: "; std::cin >> id;
			std::cout << "입금할 금액: "; std::cin >> money;
			if (money > 0)
			{
				bank.Deposit(id, money);
			}
			else
			{
				std::cout << "다시 입력해주세요\n";
			}
		}
		else if (num == '3')
		{
			std::cout << "출금하실 계좌번호와 금액을 입력해주세요\n";
			std::cout << "계좌번호: "; std::cin >> id;
			std::cout << "출금할 금액: "; std::cin >> money;
			if (money > 0)
			{
				bank.Withdraw(id, money);
			}
			else
			{
				std::cout << "다시 입력해주세요\n";
			}
		}
		else if (num == '4')
		{
			bank.Inquire();
		}
		else if (num == 'q')
		{
			std::cout << "종료\n";
			break;
		}
		else {
			std::cout << "다시 입력해주세요\n";
		}
	}
}