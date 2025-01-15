#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"
#include "Actor/Player.h"

GameLevel::GameLevel()
{
    // Ŀ�� ���߱�.
    Engine::Get().SetCursorType(CursorType::NoCursor);

    // �� ���� �ҷ��� ���� �ε�.
	// ���� �б�.
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/Maps/Stage1.txt", "rb");

	// ���� ó��.
	if (file == nullptr)
	{
		std::cout << "�� ���� ���� ����\n";
		__debugbreak();
		return;
	}

	// ���� �б�.
	// �� ��ġ�� �̵�.
	fseek(file, 0, SEEK_END);

	// �̵��� ��ġ�� FP ��������.
	size_t readSize = ftell(file);

	// FP ����ġ.
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	// ���� �о ���ۿ� ���.
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		std::cout << "�о�� ũ�Ⱑ �ٸ�\n";
		__debugbreak();
		return;
	}

	buffer[readSize] = '\0';


	// ���� ���� �� ����� �ε���.
	int index = 0;

	// ��ǥ ����� ���� ���� ����.
	int xPosition = 0;
	int yPosition = 0;

	// �ؼ� (�Ľ�-Parcing).
	while (index < (int)bytesRead)
	{
		// �� ���ھ� �б�.
		char mapChar = buffer[index++];

		// ���� ������ ��� ó��.
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// �� ���ڰ� 1�̸� Wall ���� ����.
		if (mapChar == '1')
		{
			//std::cout << 'A';
			//AddActor(new Wall(Vector2(xPosition, yPosition)));
			Wall* wall = new Wall(Vector2(xPosition, yPosition));
			actors.PushBack(wall);
			map.PushBack(wall);
		}

		// �� ���ڰ� .�̸� �׶��� ���� ����.
		else if (mapChar == '.')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);
		}

		// �� ���ڰ� b�̸� �ڽ� ���� ����.
		else if (mapChar == 'b')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			Box* box = new Box(Vector2(xPosition, yPosition));
			actors.PushBack(box);
			boxes.PushBack(box);
		}

		// �� ���ڰ� t�̸� Ÿ�� ���� ����.
		else if (mapChar == 't')
		{
			Target* target = new Target(Vector2(xPosition, yPosition));
			actors.PushBack(target);
			map.PushBack(target);
			targets.PushBack(target);
		}

		// �� ���ڰ� p�̸� �÷��̾� ���� ����.
		else if (mapChar == 'p')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			player = new Player(Vector2(xPosition, yPosition), this);
			actors.PushBack(player);
		}

		++xPosition;
		//std::cout << mapChar;
	}

	// ���� ����.
	delete[] buffer;

	// ���� �ݱ�.
	fclose(file);
}

void GameLevel::Draw()
{
	// �� �׸���.
	for (auto* actor : map)
	{
		// �÷��̾� ��ġ Ȯ��.
		if (actor->Position() == player->Position())
		{
			continue;
		}

		// �ڽ� ��ġ Ȯ��.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (actor->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// �� ���� �׸���.
		if (shouldDraw)
		{
			actor->Draw();
		}
	}

	// Ÿ�� �׸���.
	for (auto* target : targets)
	{
		// �÷��̾� ��ġ Ȯ��.
		if (target->Position() == player->Position())
		{
			continue;
		}

		// �ڽ� ��ġ Ȯ��.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (target->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// Ÿ�� ���� �׸���.
		if (shouldDraw)
		{
			target->Draw();
		}
	}

	// �ڽ� �׸���.
	for (auto* box : boxes)
	{
		box->Draw();
	}

	// �÷��̾� �׸���.
	player->Draw();
}

bool GameLevel::CanPlayerMove(const Vector2& position)
{
	// �̵��Ϸ��� ��ġ�� ���� �ִ��� Ȯ��.
	DrawableActor* searchedActor = nullptr;

	// ���� �̵��Ϸ��� ��ġ�� ���� ã��.
	for (auto* actor : map)
	{
		if (actor->Position() == position)
		{
			searchedActor = actor;
			break;
		}
	}

	// �˻��� ���Ͱ� ������ Ȯ��.
	if (searchedActor->As<Wall>())
	{
		return false;
	}

	// �˻��� ���Ͱ� �̵� ������ ����(��/Ÿ��)���� Ȯ��.
	if (searchedActor->As<Ground>()
		|| searchedActor->As<Target>())
	{
		return true;
	}

	return false;
}