#include "PreCompiledHeader.h"
#include "Engine.h"
#include "Level/Level.h"
#include "Actor/Actor.h"
#include <time.h>

// 스태틱 변수 초기화.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr), screenSize(40, 25)
{
	// 랜덤 시드 설정.
	srand((unsigned int)time(nullptr));

	// 객체가 만들어질 때 싱글톤 객체 생성.
	// 싱글톤 객체 설정.
	instance = this;

	// 기본 타겟 프레임 속도 설정.
	SetTargetFrameRate(60.0f);

	// 화면 지울 때 사용할 버퍼 초기화.
	// 1. 버퍼 크기 할당.
	emptyStringBuffer = new char[(screenSize.x + 1) * screenSize.y + 1];

	// 버퍼 덮어쓰기.
	memset(emptyStringBuffer, ' ', (screenSize.x + 1) * screenSize.y + 1);

	// 2. 값 할당.
	for (int y = 0;y < screenSize.y;++y)
	{
		/*for (int x = 0; x < screenSize.x;++x)
		{
			emptyStringBuffer[(y * (screenSize.x + 1)) + x] = ' ';
		}*/

		// 각 줄 끝에 개행 문자 추가.
		emptyStringBuffer[(y * (screenSize.x + 1)) + screenSize.x] = '\n';
	}

	// 마지막에 널 문자 추가.
	emptyStringBuffer[(screenSize.x + 1) * screenSize.y] = '\0';

	// 디버깅.
#if _DEBUG
	char buffer[2048];
	strcpy_s(buffer, 2048, emptyStringBuffer);
#endif
}

Engine::~Engine()
{
	// 메인 레벨 메모리 해제.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}

	// 클리어 버퍼 삭제.
	delete[] emptyStringBuffer;
}

void Engine::Run()
{
	// 시작 타임 스탬프 저장.
	// timeGetTime함수는 밀리 세컨드 단위(1/1000초) 단위.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU시계 사용.
	// 시스템 시계 ->고해상도 카운터 (초당 10000000번).
	// 메인보드에 시계가 있음.
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	// 시작 시간 및 이전 시간을 위한 변수.
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	// 프레임 제한.
	//float targetFrameRate = 60.0f;

	// 한 프레임 시간 계산.
	//float targetOneFrameTime = 1.0f / targetFrameRate;

	//Game-Loop
	while (true)
	{
		// 종료 조건.
		if (quit)
		{
			break;
		}
		
		// 현재 프레임 시간 저장.
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// 프레임 시간 계산.
		float deltaTime = static_cast<float>((currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart));

		// 한 프레임 시간 계산.
		//float targetOneFrameTime = 1.0f / targetFrameRate;

		// 프레임 확인.
		if (deltaTime >= targetOneFrameTime)
		{
			// 입력 처리 (현재 키의 눌림 상태 확인).
			ProcessInput();

			// 업데이트 가능한 상태에서만 프레임 업데이트 처리.
			if (shouldUpdate)
			{
				Update(deltaTime);
				Draw();
			}

			// 키 상태 저장.
			SavePreviousKeyStates();

			// 이전 프레임 시간 저장.
			previousTime = currentTime;

			// 액터 정리 (삭제 요청된 액터들 정리).
			if (mainLevel)
			{
				mainLevel->ProcessAddedAndDestroyedActor();
			}

			// 프레임 활성화.
			shouldUpdate = true;
		}
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// 기존 레벨이 있다면 삭제 후 교체.

	// 메인 레벨 설정.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 레벨에 액터 추가.
	shouldUpdate = false;
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 레벨에 액터 추가.
	shouldUpdate = false;
	targetActor->Destroy();
}

void Engine::SetCursorType(CursorType cursorType)
{
	// 1. 커서 속성 구조체 설정.
	CONSOLE_CURSOR_INFO info = { };

	// 타입 별로 구조체 값 설정.
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

	// 2. 설정.
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
	// 종료 플래그 설정.
	quit = true;
}

Engine& Engine::Get()
{
	// 싱글톤 객체 변환.
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
	// ESC키로 게임 종료.
	if (GetkeyDown(VK_ESCAPE))
	{
		QuitGame();
	}

	// 레벨 업데이트.
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}

	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Clear()
{
	// 화면의 (0,0)으로 이동.
	SetCursorPosition(0, 0);

	// 화면 지우기.
	std::cout << emptyStringBuffer;

	/*int height = 25;
	for (int ix = 0;ix < height;++ix)
	{
		std::cout << "                               \n";
	}*/

	// 화면의 (0,0)으로 이동.
	SetCursorPosition(0, 0);
}

void Engine::Draw()
{
	// 화면 지우기.
	Clear();

	// 레벨 그리기.
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
