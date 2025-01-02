//헤더 추가
#include "Entity.h"
#include <iostream>

//Header <-> Cpp 파일 전환 단축기
//Ctrl + K | Ctrl + O
Entity::Entity()
	:x(0), y(0)
{
	std::cout << "Entity() called\n";
}

Entity::~Entity()
{
	std::cout << "~Entity() called\n";
}

void Entity::Move(int xAmount, int yAmount)
{
	x += xAmount;
	y += yAmount;
}
