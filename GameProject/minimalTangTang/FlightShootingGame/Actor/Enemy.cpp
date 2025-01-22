#include "Enemy.h"
#include "Engine/Engine.h"
#include "Actor/EnemyBullet.h"

Enemy::Enemy(const char* image)
    : DrawableActor(image)
{
    // �������� �̵��� ���� ����.
    int random = Random(1, 10);
    int randomLeftRight = Random(1, 10);
    int randomUpDown = Random(1, 10);
    // �¿쿡�� �������� ���Ͽ��� �������� ���� 
    if (random % 2 == 0)
    {
        // �� �� �� �� ����
        // Left�� ��
        if (randomLeftRight % 2 == 0)
        {
            //¦���� ��쿡�� �������� �̵��ϵ��� ����.
            direction = Direction::Left;
            // x��ǥ�� ȭ�� ������ ����.
            xPosition = (float)(Engine::Get().ScreenSize().x - width);
            yPosition = Random(0, 30);
        }// Right�� ��
        else
        {
            // Ȧ���� ��쿡�� ���������� �̵��ϵ��� ����.
            direction = Direction::Right;

            // x��ǥ�� ȭ�� ������ ����.
            xPosition = 0.0f;
            yPosition = Random(0, 30);
        }
    }
    else
    {
        if (randomLeftRight % 2 == 0)
        {
            //¦���� ��쿡�� �������� �̵��ϵ��� ����.
            direction = Direction::Up;

            // y��ǥ�� ȭ�� �ǾƷ��� ����.
            yPosition = (float)(Engine::Get().ScreenSize().y - maxY);

            xPosition = Random(0, 120);
        }// Right�� ��
        else
        {
            // Ȧ���� ��쿡�� �Ʒ������� �̵��ϵ��� ����.
            direction = Direction::Down;

            // x��ǥ�� ȭ�� ������ ����.
            yPosition = 0.0f;
            xPosition = Random(0, 120);
        }
    }
    // ���� ��ġ ����.
    this->position = Vector2((int)xPosition, yPosition);
}

void Enemy::Update(float deltaTime)
{
    Super::Update(deltaTime);

    float factor = 0.0f;
    // �¿� �̵�.
    if (direction ==Direction::Left)
    {

        factor = -1.0f;
        xPosition += speed * factor * deltaTime;
        position.x = (int)xPosition;
    }
    if (direction == Direction::Right)
    {

        factor = 1.0f;
        xPosition += speed * factor * deltaTime;
        position.x = (int)xPosition;
    }
    if (direction == Direction::Up)
    {

        factor = -1.0f;
        yPosition += speed * factor * deltaTime;
        position.y = (int)yPosition;
    }
    if(direction == Direction::Down)
    {

        factor = 1.0f;
        yPosition += speed * factor * deltaTime;
        position.y = (int)yPosition;
    }


    // ȭ���� ����� ���� ����.
    if (xPosition<0.0f|| position.x > Engine::Get().ScreenSize().x - width)
    {
        Destroy();
    }

    if (yPosition <0.0f || position.y > Engine::Get().ScreenSize().y - maxY)
    {
        Destroy();
    }
    //// ź�� �߻�.
    //static float elapsedTime = 0.0f;
    //static float fireInterval = RandomPercent(1.0f, 2.0f);
    //
    //// Ÿ�̸� ������Ʈ.
    //elapsedTime += deltaTime;

    //// Ÿ�̸� ó��.
    //if (elapsedTime < fireInterval)
    //{
    //    return;
    //}

    //// Ÿ�̸� �ʱ�ȭ.
    //elapsedTime = 0.0f;
    //fireInterval = RandomPercent(1.0f, 2.0f);

    // ź�� ����.
    /*Engine::Get().AddActor(
        new EnemyBullet(Vector2(position.x + width / 2, position.y))
    );*/
}
