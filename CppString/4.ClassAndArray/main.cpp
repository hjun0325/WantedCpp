#include <iostream>

class Player
{
public:
	Player()
		: x(0), y(0)
	{
		std::cout << "Player contructor call\n";
	}

	Player(int inX, int inY)
		: x(inX), y(inY)
	{
	}

	void ShowPosition() const
	{
		std::cout << "x: " << x << "  " << "y: " << y << "\n";
	}

	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(const int inX) { x = inX; }
	void SetY(const int inY) { y = inY; }

private:
	int x;
	int y;
};

int main()
{
	Player players[5];

	for (int ix = 0; ix < 5; ++ix)
	{
		players[ix].SetX(ix * 2);
		players[ix].SetY(ix * 3);
	}

	for (const Player& player : players) //편하긴 한데 순서 보장은 안됨
	{
		player.ShowPosition();
	}

	std::cin.get();
}