#pragma once

#include "PreCompiledHeader.h"

//������ �⺻ ��ü
class ENGINE_API Actor
{
public:
	Actor();
	virtual ~Actor();

	//���� ó�� �Լ�
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	//ID(�ؽ� ��)/�̸� ��
	//Ȱ��ȭ ���������� ��Ÿ���� ����
	bool isActive;

	//������ ���� ��û�� �ƴ��� ���θ� ��Ÿ���� ����
	bool isExpired;
};