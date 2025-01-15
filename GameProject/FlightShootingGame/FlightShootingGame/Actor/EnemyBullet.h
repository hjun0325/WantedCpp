#pragma once

#include <Actor/DrawableActor.h>

// �� ź�� Ŭ����.
class EnemyBullet : public DrawableActor
{
    RTTI_DECLARATIONS(EnemyBullet, DrawableActor)

public:
    EnemyBullet(const Vector2& position);

    virtual void Update(float deltaTime) override;

private:
    // �̵� ���� ����(�Ӽ�).
    float speed = 15.0f;
    float yPosition = 0.0f;
};