#pragma once
#include<iostream>

class Account
{
public:
	Account(int id, char* name, int balance);
	~Account();

	int idGetter() const;
	char* nameGetter() const;
	int balanceGetter() const;
private:
	int id; //���¹�ȣ
	char* name; //�� �̸�
	int balance; //���� �ܾ�
};