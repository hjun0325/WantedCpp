#pragma once
#include "Entity.h"

//�̵���� (�ü�� ������ �����ϴ� ���α׷�))
//�ٿ�ĳ������ ��������. 
class Player : public Entity
{
public:
	Player(const char* name);
	~Player();
private:
	char* name;
};

