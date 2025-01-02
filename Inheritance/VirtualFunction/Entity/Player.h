#pragma once
#include "Entity.h"
#include"IMovable.h"
#include <iostream>
//�̵���� (�ü�� ������ �����ϴ� ���α׷�))
//�ٿ�ĳ������ ��������. 
class Player : public IEntity, public IMovable //���� ���. ���� �θ� ����
{
public:
	Player(const char* name);
	virtual ~Player();

	//�����Լ�(virtual Ű���尡 �߰��� �Լ�)
	virtual const char* GetName() override 
	{
		// :: ���� ���� ������
		//std::cout << IEntity::GetName() << "\n";
		return name;
	}

	virtual void Move(int x, int y)
	{

	}

private:
	char* name;
};