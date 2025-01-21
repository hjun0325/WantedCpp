#include <iostream>
#include "Game/Game.h"

int main()
{
	// 메모리 누수 확인.
	CheckMemoryLeak();

	Game game;
	game.Run();
}