#include<iostream>
#include "Engine.h"
#include<Windows.h>

Engine::Engine()
	: quit(false)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	////���� Ÿ�� ������ ����
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	//CPU�ð� ���
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//���� �ð� �� ���� �ð��� ���� ����
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = 0;

	//������ ����
	float targetFrameRate = 60.0f;

	//�� ������ �ð� ���
	float targetOneFrameTime = 1.0f / targetFrameRate;

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

		//������ Ȯ��
		if (deltaTime >= targetOneFrameTime)
		{
			//�Է� ó�� (���� Ű�� ���� ���� Ȯ��)
			ProcessInput();

			Update(deltaTime);
			Draw();

			//Ű ���� ����
			SavePreviousKeyStates();

			//���� ������ �ð� ����
			previousTime = currentTime;
		}

		//Sleep(0.1);
		//ProcessInput();
		//Update(deltaTime);
		//Draw();

		////���� ������ �ð� ����
		//previousTime = currentTime;
	}
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

	std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Draw()
{
}

void Engine::SavePreviousKeyStates()
{
	for (int ix = 0;ix < 255;++ix)
	{
		keyState[ix].wasKeyDown = keyState[ix].isKeyDown;
	}
}
