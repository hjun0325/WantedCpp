#include<iostream>
#include"Player.h"
#include"Entity.h"

int main()
{
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	//Player* player = new Player("RonnieJ");
	IEntity* player = new Player("RonnieJ"); //��ĳ����
	//std::cout << player->GetName() << "\n";

	//delete entity;
	delete player;

	std::cin.get();
}