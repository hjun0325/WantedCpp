#pragma once

//Ŭ���� ����
class IEntity
{
//public:
//	Entity();
//	virtual ~Entity();
//
//	void Move(int xAmount, int yAmount);
	//virtual const char* GetName() { return "Entity"; }

	//���� ���� �Լ�
	//����: �� �Լ��� �ʼ������� �����ϵ��� ������
	virtual const char* GetName() = 0;
	/*virtual void Test()
	{

	}*/
//protected:
//	int x;
//	int y;
};