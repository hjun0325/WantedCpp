#include "TextScrollActor.h"
#include "Engine/Engine.h"
#include "Game/Game.h"

TextScrollActor::TextScrollActor(const char* message)
{
	// 임시 문자열 버퍼.
	temp = new char[printWidth + 1];

	// 문자열 길이 구하기.
	length = (int)strlen(message);

	// 문자열 복사.
	string = new char[length + 1];
	strcpy_s(string, length + 1, message);

	// 커서 감추기.
	Engine::Get().SetCursorType(CursorType::NoCursor);
}

TextScrollActor::~TextScrollActor()
{
	delete[] string;
	delete[] temp;
}

void TextScrollActor::Update(float delatTime)
{
	
	// ESC 종료.
	if (Engine::Get().GetkeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMenu();
	}

	// 좌우 방향키 입력 처리.
	if (Engine::Get().Getkey(VK_LEFT))
	{
		// 방향 설정.
		direction = Direction::Left;
		shouldUpdate = true;
	}

	if (Engine::Get().Getkey(VK_RIGHT))
	{
		// 방향 설정.
		direction = Direction::Right;
		shouldUpdate = true;
	}

	// 방향키가 안 눌렸는지 확인.
	if (!Engine::Get().Getkey(VK_LEFT) && !Engine::Get().Getkey(VK_RIGHT))
	{
		shouldUpdate = false;
	}

	// 딜레이 계산.
	elapsedTime += delatTime;

	// 시간이 모두 경과 했는지 확인.
	if (elapsedTime < delayTime)
	{
		return;
	}

	// 시간이 경과 했으면 다음 계산을 위해 초기화.
	elapsedTime = 0.0f;

	if (shouldUpdate)
	{
		if (direction == Direction::Right)
		{
			// 화면에 그릴 문자열의 시작 인덱스 업데이트.
			index = (index + 1) % length;
		}
		else if (direction == Direction::Left)
		{
			// 화면에 그릴 문자열의 시작 인덱스 업데이트.
			index = (index - 1 + length) % length;
		}
	}
}

void TextScrollActor::Draw()
{
	int tempIndex = index;

	for (int ix = 0;ix < printWidth;++ix)
	{
		temp[ix] = string[tempIndex];
		tempIndex = (tempIndex + 1) % length;
	}

	temp[printWidth] = '\0';
	Log(temp);

	Engine::Get().SetCursorPosition(0, 0);
}