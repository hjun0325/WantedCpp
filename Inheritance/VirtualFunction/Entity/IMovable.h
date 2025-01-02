#pragma once

//추상 클래스
//인터페이스
class IMovable
{
public:
	virtual void Move(int xAmount, int yAmount) = 0;
};