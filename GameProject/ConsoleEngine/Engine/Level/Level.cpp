#include "PreCompiledHeader.h"
#include "Level.h"
//#include "../Actor/Actor.h"
#include "Actor/Actor.h"

Level::Level()
	:actors(nullptr), capacity(4), count(0)
{
	//���� �迭 ����
	actors = new Actor * [capacity];

	//�ʱ�ȭ
	memset(actors, 0, sizeof(size_t) * capacity);
}

Level::~Level()
{
	//�޸� ����
	for (int ix = 0; ix < count;++ix)
	{
		//���� ����
		delete actors[ix];
	}

	//���� �迭 ����
	delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
	//���� ����� ������ ������� Ȯ��
	if (count == capacity)
	{
		//���� �߰� �Ҵ�
		int newCapacity = capacity * 2;

		//�ӽ� ����
		Actor** temp = new Actor * [newCapacity];

		//���� �� ����
		//loop. FMemory::copy.
		memcpy(temp, actors, sizeof(size_t) * capacity);

		//���� �迭 ����
		delete[] actors;

		//�迭 ��ü
		actors = temp;
		//temp = nullptr //���� ����

		//ũ�� ����
		capacity = newCapacity;
	}

	//���� �߰�
	actors[count] = newActor;
	++count;
}

void Level::Update(float deltaTime)
{
	//������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��
	for (int ix = 0; ix < count;++ix)
	{
		actors[ix]->Update(deltaTime);
	}
}

void Level::Draw()
{
	//������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��
	for (int ix = 0; ix < count;++ix)
	{
		actors[ix]->Draw();
	}
}
