#include "PlayerBullet.h"
#include <cmath>

PlayerBullet::PlayerBullet(const Vector2& position)
	: DrawableActor("!")
{
	// ź�� ��ġ ����.
	this->position = position;
	yPosition = (float)position.y;

}

void PlayerBullet::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ��ġ ����.
	// ������ ���� �̵�.
	// --position.y;


	// ������ �ð��� ����� �̵�.
	yPosition -= speed * deltaTime;
	position.y = (int)yPosition;

	// y��ǥ�� ȭ���� ����� ���� ����.
	if (position.y < 0.0f)
	{
		Destroy();
		return;
	}
}
