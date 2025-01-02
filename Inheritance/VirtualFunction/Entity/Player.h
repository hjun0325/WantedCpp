#pragma once
#include "Entity.h"
#include"IMovable.h"
#include <iostream>
//미들웨어 (운영체제 위에서 동작하는 프로그램))
//다운캐스팅을 조심하자. 
class Player : public IEntity, public IMovable //다중 상속. 여러 부모를 가짐
{
public:
	Player(const char* name);
	virtual ~Player();

	//가상함수(virtual 키워드가 추가된 함수)
	virtual const char* GetName() override 
	{
		// :: 범위 지정 연산자
		//std::cout << IEntity::GetName() << "\n";
		return name;
	}

	virtual void Move(int x, int y)
	{

	}

private:
	char* name;
};