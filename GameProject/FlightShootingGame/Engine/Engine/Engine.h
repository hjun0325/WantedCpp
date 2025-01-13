#pragma once

#include "Core.h"
#include "Math/Vector2.h"

//�Է� ó���� ���� ����ü
struct KeyState
{
	//���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool isKeyDown = false;

	//���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool wasKeyDown = false;
};

// Ŀ���� ������ ������ �� ����� ������.
enum class CursorType
{
	NoCursor,
	SolidCursor,
	NormalCursor
};

class Level;
class Actor;
// ���� Ŭ����
class ENGINE_API Engine
{
public:
	Engine();
	virtual ~Engine();

	//���� ���� �Լ�
	void Run();

	//���� �߰� �Լ�
	void LoadLevel(Level* newLevel);

	// ���� �߰�/���� �Լ�.
	void AddActor(Actor* newActor);
	void DestroyActor(Actor* targetActor);

	// ȭ�� ��ǥ ���� �Լ�.
	void SetCursorType(CursorType cursorType);
	void SetCursorPosition(const /*class*/ Vector2& position);
	void SetCursorPosition(int x, int y);

	// Ÿ�� ������ �ӵ� ���� �Լ�.
	void SetTargetFrameRate(float targetFrameRate);

	//�Է� ���� �Լ�
	bool Getkey(int key);
	bool GetkeyDown(int key);
	bool GetkeyUp(int key);

	//���� ���� �Լ�
	void QuitGame();

	//�̱��� ��ü ���� �Լ�
	static Engine& Get();

protected:
	void ProcessInput();			//�Է� ó��
	void Update(float deltaTime);	//Tick();

	void Clear();					// ȭ�� �����.
	void Draw();					//Render();

	//���� ���� �����ϴ� �Լ�
	void SavePreviousKeyStates();

protected:

	// Ÿ�� ������ ����(�ʴ� ������).
	float targetFrameRate = 60.0f;

	// �� ������ �ð� ��(����: ��).
	float targetOneFrameTime = 0.0f;

	//������ �� ������ ����
	bool quit;

	//Ű ��븦 �����ϴ� �迭
	KeyState keyState[255];

	//�̱��� ������ ���� ���� ���� ����
	static Engine* instance;

	//���� ���� ����
	Level* mainLevel;

	// �������� ������Ʈ�ؾ� �ϴ��� ���θ� ��Ÿ���� ����.
	bool shouldUpdate = true;
};