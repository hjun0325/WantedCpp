#include "PreCompiledHeader.h"
#include<iostream>
#include "Engine.h"
#include"Level/Level.h"
#include<Windows.h>


//스태틱 변수 초기화
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr)
{
	//객체가 만들어질 때 싱글톤 객체 생성
	//싱글톤 객체 설정
	instance = this;
}

Engine::~Engine()
{
	//메인 레벨 메모리 해제
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}
}

void Engine::Run()
{
	////시작 타임 스탬프 저장
	////timeGetTime함수는 밀리 세컨드 단위(1/1000초) 단위
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	//CPU시계 사용
	//시스템 시계 ->고해상도 카운터 (10000000)
	//메인보드에 시계가 있음
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	//시작 시간 및 이전 시간을 위한 변수
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = 0;

	//프레임 제한
	float targetFrameRate = 60.0f;

	//한 프레임 시간 계산
	float targetOneFrameTime = 1.0f / targetFrameRate;

	//Game-Loop
	while (true)
	{
		//종료 조건
		if (quit)
		{
			break;
		}
		
		//현재 프레임 시간 저장
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		//프레임 시간 계산
		float deltaTime = static_cast<float>((currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart));

		//프레임 확인
		if (deltaTime >= targetOneFrameTime)
		{
			//입력 처리 (현재 키의 눌림 상태 확인)
			ProcessInput();

			Update(deltaTime);
			Draw();

			//키 상태 저장
			SavePreviousKeyStates();

			//이전 프레임 시간 저장
			previousTime = currentTime;
		}

		//Sleep(0.1);
		//ProcessInput();
		//Update(deltaTime);
		//Draw();

		////이전 프레임 시간 저장
		//previousTime = currentTime;
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	//기존 레벨이 있다면 삭제 후 교체

	//메인 레벨 설정
	mainLevel = newLevel;
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
	//종료 플래그 설정
	quit = true;
}

Engine& Engine::Get()
{
	//싱글톤 객체 변환
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
	//ESC키로 게임 종료
	if (GetkeyDown(VK_ESCAPE))
	{
		QuitGame();
	}

	//레벨 업데이트
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}

	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Draw()
{
	//레벨 그리기
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
