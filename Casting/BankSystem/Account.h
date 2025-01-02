#pragma once
#include<iostream>

class Account
{
public:
	//Account();
	Account(int id, const char* name, int balance);
	~Account();

	int idGetter() const;
	char* nameGetter() const;
	int balanceGetter() const;
	void balanceSetter(int money, int select); //select 0 = �Ա�, select 1 = ���
private:
	int id; //���¹�ȣ
	char* name; //�� �̸�
	int balance; //���� �ܾ�
};