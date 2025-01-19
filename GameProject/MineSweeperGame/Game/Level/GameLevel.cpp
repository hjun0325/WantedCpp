#include "GameLevel.h"
#include "Engine/Engine.h"
#include "random"

GameLevel::GameLevel()
{
	// map�� cell ��ġ.
	for (int ix = 0; ix < mapSize;++ix)
	{
		for (int jx = 0; jx < mapSize;++jx)
		{
			cells[ix][jx] = Cell();
		}
	}

	// �������� ���� ��ġ ���� (����: 40��)
	int XrandomIdx = 0;
	int YrandomIdx = 0;
	int mineCount = 0;
	while (mineCount != totalMine)
	{
		XrandomIdx = Random(0, mapSize - 1);
		YrandomIdx = Random(0, mapSize - 1);
		if (cells[XrandomIdx][YrandomIdx].hasMine == false)
		{
			cells[XrandomIdx][YrandomIdx].hasMine = true;
			++mineCount;
		}
	}
}

void GameLevel::Update(float deltaTime)
{
	//Engine::Get().MouseInputCoordinates();
}

void GameLevel::Draw()
{
	for (int ix = 0; ix < mapSize;++ix)
	{
		for (int jx = 0; jx < mapSize;++jx)
		{
			std::cout << "��" << " ";
		}
		std::cout << "\n";
	}

	Vector2 v2 = Engine::Get().MouseInputCoordinates();
	std::cout << v2.x << " " << v2.y << "\n";
}
