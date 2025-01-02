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
	int id; //°èÁÂ¹øÈ£
	char* name; //°í°´ ÀÌ¸§
	int balance; //°í°´ÀÇ ÀÜ¾×
};