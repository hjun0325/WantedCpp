#pragma once

#include <Actor/DrawableActor.h>

class Enemy : public DrawableActor
{
	// �� ĳ���Ͱ� �̵��� ����.
	enum class Direction
	{
		/*None = -1,
		Left,
		Right
		*/
		None = -1,
		Left,
		Right,
		Up, 
		Down
	};

	RTTI_DECLARATIONS(Enemy, DrawableActor)



public:
	// �׸� �� ����� ���ڿ� ���� ���� y��ġ�� ���� ����.
	Enemy(const char* image);

	virtual void Update(float deltaTime) override;

private:

	// �̵� ����.
	Direction direction = Direction::None;



	// �¿� �̵��� �ʿ��� ����.
	float xPosition = 0.0f;
	float yPosition = 0.0f;
	float speed = 5.0f;
};