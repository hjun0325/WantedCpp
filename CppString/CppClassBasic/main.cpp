#include<iostream>

#define _CRTDBG_MAP_ALLOC //메모리 누수 있는 곳 확인
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG //어디서 오류가 났는지 확인 가능, 부가적인 것
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) //매크로 함수
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

//클래스 선언
class Player //타입정의
{
public:

	//생성자
	Player() 
		: x(0),y(0),speed(1)
	{
		std::cout << "생성자 호출\n";
	}
	
	//소멸자
	~Player()
	{
		std::cout << "소멸자 호출\n";
	}

	//이동할 만큼의 양을 입력 받아서 좌표를 이동시키는 함수
	void Move(int x, int y) //이건 벡터데이터
	{
		this->x += x; //이건 위치데이터
		this->y += y;
	}

private:

	int x;
	int y;
	int speed;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리릭이 있는지 확인 구문
	//_CrtSetBreakAlloc(157); //메모리릭이 있는 부분에서 멈추는 구문

	//객체/개체/오브젝트/인스턴스
	//Player player;
	//Player player1();
	//Player player2 = Player();
	//player.Move(10, 20);

	//동적할당
	Player* player3 = new Player();
	delete player3;
	//player3 = nullptr; //좋은 습관

	std::cin.get();
}