#include<iostream>
#include"Entity.h"
#include"Entity/Player.h"
//#include<Entity.h>

int main()
{
	//Entity ��ü ����
	Entity* entity = new Entity();

	//Player ��ü ����
	Player* player = new Player("Ronnie");

	//������
	Entity* entity2 = player; //��ĳ����
	//name�� ����ȯ�ؼ� �� �� �ִ�.
	//����ȯ ���� �� nullptr.
	
	// world -> level(scene) -> actor
	//level(scene) = Actor* level[]
	//class TestActor : public Actor { }
	//�����͸� ���� ���� : �������� ���� �����Ͱ� �ƴϰ��� �������� �� ���� ����.
	//AddActor(Actor* actor);
	//TestActor* test = new TestActor(); AddActor(test);

	//�������� �� �������� �߿�

	delete entity;
	delete player;
	//entity2�� ����� �ȵ�

	std::cin.get();
	return 0;
}