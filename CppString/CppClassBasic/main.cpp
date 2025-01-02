#include<iostream>

#define _CRTDBG_MAP_ALLOC //�޸� ���� �ִ� �� Ȯ��
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG //��� ������ ������ Ȯ�� ����, �ΰ����� ��
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) //��ũ�� �Լ�
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

//Ŭ���� ����
class Player //Ÿ������
{
public:

	//������
	Player() 
		: x(0),y(0),speed(1)
	{
		std::cout << "������ ȣ��\n";
	}
	
	//�Ҹ���
	~Player()
	{
		std::cout << "�Ҹ��� ȣ��\n";
	}

	//�̵��� ��ŭ�� ���� �Է� �޾Ƽ� ��ǥ�� �̵���Ű�� �Լ�
	void Move(int x, int y) //�̰� ���͵�����
	{
		this->x += x; //�̰� ��ġ������
		this->y += y;
	}

private:

	int x;
	int y;
	int speed;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸𸮸��� �ִ��� Ȯ�� ����
	//_CrtSetBreakAlloc(157); //�޸𸮸��� �ִ� �κп��� ���ߴ� ����

	//��ü/��ü/������Ʈ/�ν��Ͻ�
	//Player player;
	//Player player1();
	//Player player2 = Player();
	//player.Move(10, 20);

	//�����Ҵ�
	Player* player3 = new Player();
	delete player3;
	//player3 = nullptr; //���� ����

	std::cin.get();
}