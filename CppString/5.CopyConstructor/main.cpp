#include<iostream>
#include<string>

class Player
{
public:
	Player()
		:x(0), y(0)
	{
		//���ڿ� ���� ���ϱ�
		size_t length = strlen("Player") + 1;

		//����Ȯ��
		name = new char[length];

		//���ڿ� ����
		strcpy_s(name, length, "Player");

		//memcpy(name, "Player", length - 1); //������ ����, cpu��ɾ��, ������ �߸��ϸ� ������
		//name[length - 1] = '\0';
		//std::cout << "Player() called\n";
	}

	//Player() = delete; //��������� ����, �Լ��� �Ҵ��ϴ� Ư���� ����
	//������ private�� �⺻ �����ڸ� �־ ��������� ����
	Player(const char* name,int x, int y)
		:x(x), y(y) 
	{
		//���ڿ� ���� ���ϱ�
		size_t length = strlen(name) + 1;

		//����Ȯ��
		this->name = new char[length];

		//���ڿ� ����
		strcpy_s(this->name, length, name);
		//std::cout << "Player(int number) called\n";
	}

	//���������
	//c++ value category
	//lvalue/rvalue
	//int a = 10;
	//int number = a;
	//r value reference
	Player(const Player& other)//const�� �ɼ�
	{
		std::cout << "Player(const Player& other) called\n";
		x = other.x;
		y = other.y;

		//���ڿ� ���� ���ϱ�
		size_t length = strlen(other.name) + 1;

		//����Ȯ��
		this->name = new char[length];

		//���ڿ� ����
		strcpy_s(this->name, length, other.name);
		//this->name = other.name;
		//���� �����ڿ��� ���� Ÿ�� �ٸ� ��ü������ ���� ��� ���
	}

	//�Ҹ���
	~Player()
	{
		//�� �޸� ����
		delete[] name;
		//���� ������ ������ �� ������
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