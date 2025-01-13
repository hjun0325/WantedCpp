#include "TextScrollActor.h"
#include "Engine/Engine.h"

TextScrollActor::TextScrollActor(const char* message)
{
	// �ӽ� ���ڿ� ����.
	temp = new char[printWidth + 1];

	// ���ڿ� ���� ���ϱ�/
	length = (int)strlen(message);

	// ���ڿ� ����.
	string = new char[length + 1];
	strcpy_s(string, length + 1, message);

	// Ŀ�� ���߱�.
	Engine::Get().SetCursorType(CursorType::NoCursor);
}

TextScrollActor::~TextScrollActor()
{
	delete[] string;
	delete[] temp;
}

void TextScrollActor::Update(float delatTime)
{
	
	// ESC ����.
	if (Engine::Get().GetkeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	// �¿� ����Ű �Է� ó��.
	if (Engine::Get().Getkey(VK_LEFT))
	{
		// ���� ����.
		direction = Direction::Left;
		shouldUpdate = true;
	}

	if (Engine::Get().Getkey(VK_RIGHT))
	{
		// ���� ����.
		direction = Direction::Right;
		shouldUpdate = true;
	}

	// ����Ű�� �� ���ȴ��� Ȯ��.
	if (!Engine::Get().Getkey(VK_LEFT) && !Engine::Get().Getkey(VK_RIGHT))
	{
		shouldUpdate = false;
	}

	// ������ ���.
	elapsedTime += delatTime;

	// �ð��� ��� ��� �ߴ��� Ȯ��.
	if (elapsedTime < delayTime)
	{
		return;
	}

	// �ð��� ��� ������ ���� ����� ���� �ʱ�ȭ.
	elapsedTime = 0.0f;

	if (shouldUpdate)
	{
		if (direction == Direction::Right)
		{
			// ȭ�鿡 �׸� ���ڿ��� ���� �ε��� ������Ʈ.
			index = (index + 1) % length;
		}
		else if (direction == Direction::Left)
		{
			// ȭ�鿡 �׸� ���ڿ��� ���� �ε��� ������Ʈ.
			index = (index - 1 + length) % length;
		}
	}
}

void TextScrollActor::Draw()
{
	// �ӽ� ���ڿ� ����.
	//char* temp = new char[printWidth + 1];
	int tempIndex = index;

	for (int ix = 0;ix < printWidth;++ix)
	{
		temp[ix] = string[tempIndex];
		tempIndex = (tempIndex + 1) % length;
	}

	temp[printWidth] = '\0';
	Log(temp);

	//delete[] temp;
	Engine::Get().SetCursorPosition(0, 0);
}