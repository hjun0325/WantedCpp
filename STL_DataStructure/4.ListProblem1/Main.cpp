#include <iostream>
#include <list>

struct Point
{
	Point() = default;
	Point(std::string name, int x, int y)
		: name(name), x(x), y(y)
	{

	}
	std::string name;
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	return os << point.name << ": (" << point.x << ", " << point.y << ")\n";
}

int main()
{
	std::list<Point> pointList;

	Point A("A", 50, 200);
	pointList.push_back(A);

	Point B("B", 20, 80);
	pointList.push_back(B);

	Point C("C", 75, 10);
	pointList.push_back(C);

	Point D("D", 130, 80);
	pointList.push_back(D);

	Point E("E", 100, 200);
	pointList.push_back(E);

	//Point F(180, 150);

	for (auto& position : pointList)
	{
		std::cout << position;
	}
}