#include<iostream>
#include<string>

class Player
{
public:
	Player()
		:x(0), y(0)
	{
		//문자열 길이 구하기
		size_t length = strlen("Player") + 1;

		//공간확보
		name = new char[length];

		//문자열 복사
		strcpy_s(name, length, "Player");

		//memcpy(name, "Player", length - 1); //통으로 복사, cpu명령어로, 문제는 잘못하면 오류남
		//name[length - 1] = '\0';
		//std::cout << "Player() called\n";
	}

	//Player() = delete; //명시적으로 지움, 함수에 할당하는 특이한 구문
	//예전엔 private에 기본 생성자를 넣어서 명시적으로 지움
	Player(const char* name,int x, int y)
		:x(x), y(y) 
	{
		//문자열 길이 구하기
		size_t length = strlen(name) + 1;

		//공간확보
		this->name = new char[length];

		//문자열 복사
		strcpy_s(this->name, length, name);
		//std::cout << "Player(int number) called\n";
	}

	//복사생성자
	//c++ value category
	//lvalue/rvalue
	//int a = 10;
	//int number = a;
	//r value reference
	Player(const Player& other)//const는 옵션
	{
		std::cout << "Player(const Player& other) called\n";
		x = other.x;
		y = other.y;

		//문자열 길이 구하기
		size_t length = strlen(other.name) + 1;

		//공간확보
		this->name = new char[length];

		//문자열 복사
		strcpy_s(this->name, length, other.name);
		//this->name = other.name;
		//복사 생성자에선 동일 타입 다른 객체이지만 변수 사용 허용
	}

	//소멸자
	~Player()
	{
		//힙 메모리 해제
		delete[] name;
		//지금 삭제한 공간을 또 삭제함
	}

	void Print()
	{
		std::cout <<"name: "<< name << " x: " << x << ", y: " << y << "\n";
	}

private:
	int x;
	int y;
	char* name;
};

int main()
{
	////Player player1;
	//Player player1 = Player();
	//Player player2 = Player(10);
	//Player player3 = Player(player2);

	//player2.Print();
	//player3.Print();

	Player player1 = Player("Ronnie", 0, 0);
	//Player player2 = Player(player1);
	Player player2 = player1;

	player1.Print();
	player2.Print();

	std::cin.get();
}