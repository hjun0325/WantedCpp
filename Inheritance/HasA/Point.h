#pragma once

class Point
{
public:
	Point(int x, int y);
	~Point();

	int xGetter() const;
	int yGetter() const;
private:
	int x, y;
};