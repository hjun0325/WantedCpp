#include "Game/Game.h"
#include "Engine/Engine.h"
#include <iostream>

int main()
{
	//메모리 누수 확인.
	CheckMemoryLeak();

	Game game;
	game.Run();

}