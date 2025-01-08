#include "PreCompiledHeader.h"
#include "Level.h"
//#include "../Actor/Actor.h"
#include "Actor/Actor.h"

Level::Level()
{
}

Level::~Level()
{
	//�޸� ����
	//for (int ix = 0; ix < actors.Size();++ix)
	//{
	//	//���� ����
	//	delete actors[ix];
	//}
	
	// �޸� ����
	for (Actor* actor : actors)
	{
		delete actor;
	}
}

void Level::AddActor(Actor* newActor)
{
	actors.PushBack(newActor);
	////���� ����� ������ ������� Ȯ��
	//if (count == capacity)
	//{
	//	//���� �߰� �Ҵ�
	//	int newCapacity = capacity * 2;

	//	//�ӽ� ����
	//	Actor** temp = new Actor * [newCapacity];

	//	//���� �� ����
	//	//loop. FMemory::copy.
	//	memcpy(temp, actors, sizeof(size_t) * capacity);

	//	//���� �迭 ����
	//	delete[] actors;

	//	//�迭 ��ü
	//	actors = temp;
	//	//temp = nullptr //���� ����

	//	//ũ�� ����
	//	capacity = newCapacity;
	//}

	////���� �߰�
	//actors[count] = newActor;
	//++count;
}

void Level::Update(float deltaTime)
{
	////������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��
	//for (int ix = 0; ix < actor.Size();++ix)
	//{
	//	actors[ix]->Update(deltaTime);
	//}
	
	for (Actor* actor : actors)
	{
		actor->Update(deltaTime);
	}
}

void Level::Draw()
{
	////������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��
	//for (int ix = 0; ix < actor.Size();++ix)
	//{
	//	actors[ix]->Draw();
	//}

	for (Actor* actor : actors)
	{
		actor->Draw();
	}
}
