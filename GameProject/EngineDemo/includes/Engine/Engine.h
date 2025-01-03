#pragma once

#include "PreCompiledHeader.h"

//�Է� ó���� ���� ����ü
struct KeyState
{
	//���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool isKeyDown = false;

	//���� �����ӿ� Ű�� ���ȴ��� Ȯ��
	bool wasKeyDown = false;
};


class Level;
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
	void Draw();					//Render();

	//���� ���� �����ϴ� �Լ�
	void SavePreviousKeyStates();

protected:
	//������ �� ������ ����
	bool quit;

	//Ű ��븦 �����ϴ� �迭
	KeyState keyState[255];

	//�̱��� ������ ���� ���� ���� ����
	static Engine* instance;

	//���� ���� ����
	Level* mainLevel;
};