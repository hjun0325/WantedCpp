#pragma once
#include "Entity.h"

//미들웨어 (운영체제 위에서 동작하는 프로그램))
//다운캐스팅을 조심하자. 
class Player : public Entity
{
public:
	Player(const char* name);
	~Player();
private:
	char* name;
};

