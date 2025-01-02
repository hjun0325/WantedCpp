#include<iostream>
#include"Entity.h"
#include"Entity/Player.h"
//#include<Entity.h>

int main()
{
	//Entity 객체 생성
	Entity* entity = new Entity();

	//Player 객체 생성
	Player* player = new Player("Ronnie");

	//다형성
	Entity* entity2 = player; //업캐스팅
	//name은 형변환해서 쓸 수 있다.
	//형변환 실패 시 nullptr.
	
	// world -> level(scene) -> actor
	//level(scene) = Actor* level[]
	//class TestActor : public Actor { }
	//포인터를 쓰는 이유 : 다형성에 오면 포인터가 아니고서는 다형성을 쓸 수가 없다.
	//AddActor(Actor* actor);
	//TestActor* test = new TestActor(); AddActor(test);

	//다형성은 왜 쓰는지가 중요

	delete entity;
	delete player;
	//entity2는 지우면 안됨

	std::cin.get();
	return 0;
}