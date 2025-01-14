#pragma once

#include <Actor/DrawableActor.h>

class Enemy : public DrawableActor
{
	// �� ĳ���Ͱ� �̵��� ����
	enum class Direction
	{
		/*None = -1,
		Left,
		Right*/
		None = 0,
		Left = -1,
		Right = 1
	};

	RTTI_DECLARATIONS(Enemy, DrawableActor)

public:
	// �׸� �� ����� ���ڿ� ���� ���� y��ġ�� ���� ����.
	Enemy(const char* image, int yPosition);

	virtual void Update(float deltaTime) override;

private:
	// �̵� ����.
	Direction direction = Direction::None;

	// �¿� �̵��� �ʿ��� ����.
	float xPosition = 0.0f;
	float speed = 5.0f;
};