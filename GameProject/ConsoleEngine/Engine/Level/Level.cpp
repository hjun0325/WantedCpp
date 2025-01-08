#include "PreCompiledHeader.h"
#include "Level.h"
//#include "../Actor/Actor.h"
#include "Actor/Actor.h"

Level::Level()
{
}

Level::~Level()
{
	//메모리 해제
	//for (int ix = 0; ix < actors.Size();++ix)
	//{
	//	//액터 삭제
	//	delete actors[ix];
	//}
	
	// 메모리 해제
	for (Actor* actor : actors)
	{
		delete actor;
	}
}

void Level::AddActor(Actor* newActor)
{
	actors.PushBack(newActor);
	////현제 힐당된 공간이 충분한지 확인
	//if (count == capacity)
	//{
	//	//공간 추가 할당
	//	int newCapacity = capacity * 2;

	//	//임시 공간
	//	Actor** temp = new Actor * [newCapacity];

	//	//기존 값 복사
	//	//loop. FMemory::copy.
	//	memcpy(temp, actors, sizeof(size_t) * capacity);

	//	//기존 배열 삭제
	//	delete[] actors;

	//	//배열 교체
	//	actors = temp;
	//	//temp = nullptr //좋은 습관

	//	//크기 변경
	//	capacity = newCapacity;
	//}

	////액터 추가
	//actors[count] = newActor;
	//++count;
}

void Level::Update(float deltaTime)
{
	////레벨에 포함된 액터를 순회하면서 Update 함수 호출
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
	////레벨에 포함된 액터를 순회하면서 Draw 함수 호출
	//for (int ix = 0; ix < actor.Size();++ix)
	//{
	//	actors[ix]->Draw();
	//}

	for (Actor* actor : actors)
	{
		actor->Draw();
	}
}
