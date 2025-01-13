#include "PreCompiledHeader.h"
#include "Engine.h"
#include "Level/Level.h"
#include "Actor/Actor.h"

// ����ƽ ���� �ʱ�ȭ.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr)
{
	// ��ü�� ������� �� �̱��� ��ü ����.
	// �̱��� ��ü ����.
	instance = this;

	// �⺻ Ÿ�� ������ �ӵ� ����.
	SetTargetFrameRate(60.0f);
}

Engine::~Engine()
{
	// ���� ���� �޸� ����.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}
}

void Engine::Run()
{
	// ���� Ÿ�� ������ ����.
	// timeGetTime�Լ��� �и� ������ ����(1/1000��) ����.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU�ð� ���.
	// �ý��� �ð� ->���ػ� ī���� (�ʴ� 10000000��).
	// ���κ��忡 �ð谡 ����.
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	//���� �ð� �� ���� �ð��� ���� ����
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = 0;

	//������ ����
	//float targetFrameRate = 60.0f;

	//�� ������ �ð� ���
	//float targetOneFrameTime = 1.0f / targetFrameRate;

	//Game-Loop
	while (true)
	{
		//���� ����
		if (quit)
		{
			break;
		}

		//���� ������ �ð� ����
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		//������ �ð� ���
		float deltaTime = static_cast<float>((currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart));

		// �� ������ �ð� ���.
		//float targetOneFrameTime = 1.0f / targetFrameRate;

		// ������ Ȯ��.
		if (deltaTime >= targetOneFrameTime)
		{
			// �Է� ó�� (���� Ű�� ���� ���� Ȯ��).
			ProcessInput();

			// ������Ʈ ������ ���¿����� ������ ������Ʈ ó��.
			if (shouldUpdate)
			{
				Update(deltaTime);
				Draw();
			}

			// Ű ���� ����.
			SavePreviousKeyStates();

			// ���� ������ �ð� ����.
			previousTime = currentTime;

			// ���� ���� (���� ��û�� ���͵� ����).
			if (mainLevel)
			{
				mainLevel->ProcessAddedAndDestroyedActor();
			}

			// ������ Ȱ��ȭ.
			shouldUpdate = true;
		}
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// ���� ������ �ִٸ� ���� �� ��ü.

	// ���� ���� ����.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// ���� ó��.
	if (mainLevel == nullptr)
	{
		return;
	}

	// ������ ���� �߰�.
	shouldUpdate = false;
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// ���� ó��.
	if (mainLevel == nullptr)
	{
		return;
	}

	// ������ ���� �߰�.
	shouldUpdate = false;
	targetActor->Destroy();
}

void Engine::SetCursorType(CursorType cursorType)
{
	// 1. Ŀ�� �Ӽ� ����ü ����.
	CONSOLE_CURSOR_INFO info = { };

	// Ÿ�� ���� ����ü �� ����.
	switch (cursorType)
	{
	case CursorType::NoCursor:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;

	case CursorType::SolidCursor:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;

	case CursorType::NormalCursor:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}

	// 2. ����.
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPosition(const Vector2& position)
{
	SetCursorPosition(position.x, position.y);
}

void Engine::SetCursorPosition(int x, int y)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { static_cast<short>(x), static_cast<short>(y) };
	SetConsoleCursorPosition(handle, coord);
}

void Engine::SetTargetFrameRate(float targetFrameRate)
{
	this->targetFrameRate = targetFrameRate;
	targetOneFrameTime = 1.0f / targetFrameRate;
}

bool Engine::Getkey(int key)
{
	return keyState[key].isKeyDown;
}

bool Engine::GetkeyDown(int key)
{
	return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetkeyUp(int key)
{
	return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
	//���� �÷��� ����
	quit = true;
}

Engine& Engine::Get()
{
	//�̱��� ��ü ��ȯ
	return *instance;
}

void Engine::ProcessInput()
{
	for (int ix = 0;ix < 255;++ix)
	{
		keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	//ESCŰ�� ���� ����
	if (GetkeyDown(VK_ESCAPE))
	{
		QuitGame();
	}

	//���� ������Ʈ
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}

	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Clear()
{
	// ȭ���� (0,0)���� �̵�.
	SetCursorPosition(0, 0);

	// ȭ�� �����.
	int height = 25;
	for (int ix = 0;ix < height;++ix)
	{
		std::cout << "                               \n";
	}

	// ȭ���� (0,0)���� �̵�.
	SetCursorPosition(0, 0);
}

void Engine::Draw()
{
	// ȭ�� �����.
	Clear();

	//���� �׸���
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();
	}
}

void Engine::SavePreviousKeyStates()
{
	for (int ix = 0;ix < 255;++ix)
	{
		keyState[ix].wasKeyDown = keyState[ix].isKeyDown;
	}
}