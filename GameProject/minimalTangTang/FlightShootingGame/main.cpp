#include "Game/Game.h"
#include "Engine/Engine.h"
#include <iostream>

int main()
{
	//�޸� ���� Ȯ��.
	CheckMemoryLeak();

	Game game;
	game.Run();

}