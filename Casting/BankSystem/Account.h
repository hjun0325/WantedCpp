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
	void balanceSetter(int money, int select); //select 0 = ÀÔ±İ, select 1 = Ãâ±İ
private:
	int id; //°èÁÂ¹øÈ£
	char* name; //°í°´ ÀÌ¸§
	int balance; //°í°´ÀÇ ÀÜ¾×
};