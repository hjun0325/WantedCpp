#include "Enemy.h"
#include "Engine/Engine.h"
#include "Actor/EnemyBullet.h"

Enemy::Enemy(const char* image)
    : DrawableActor(image)
{
    // 랜덤으로 이동할 방향 선택.
    int random = Random(1, 10);
    int randomLeftRight = Random(1, 10);
    int randomUpDown = Random(1, 10);
    // 좌우에서 스폰할지 상하에서 스폰할지 선택 
    if (random % 2 == 0)
    {
        // 좌 우 둘 중 선택
        // Left일 때
        if (randomLeftRight % 2 == 0)
        {
            //짝수인 경우에는 왼쪽으로 이동하도록 설정.
            direction = Direction::Left;
            // x좌표를 화면 끝으로 설정.
            xPosition = (float)(Engine::Get().ScreenSize().x - width);
            yPosition = Random(0, 30);
        }// Right일 떄
        else
        {
            // 홀수인 경우에는 오른쪽으로 이동하도록 설정.
            direction = Direction::Right;

            // x좌표를 화면 끝으로 설정.
            xPosition = 0.0f;
            yPosition = Random(0, 30);
        }
    }
    else
    {
        if (randomLeftRight % 2 == 0)
        {
            //짝수인 경우에는 위쪽으로 이동하도록 설정.
            direction = Direction::Up;

            // y좌표를 화면 맨아래로 설정.
            yPosition = (float)(Engine::Get().ScreenSize().y - maxY);

            xPosition = Random(0, 120);
        }// Right일 떄
        else
        {
            // 홀수인 경우에는 아래쪽으로 이동하도록 설정.
            direction = Direction::Down;

            // x좌표를 화면 끝으로 설정.
            yPosition = 0.0f;
            xPosition = Random(0, 120);
        }
    }
    // 시작 위치 설정.
    this->position = Vector2((int)xPosition, yPosition);
}

void Enemy::Update(float deltaTime)
{
    Super::Update(deltaTime);

    float factor = 0.0f;
    // 좌우 이동.
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


    // 화면을 벗어나면 액터 삭제.
    if (xPosition<0.0f|| position.x > Engine::Get().ScreenSize().x - width)
    {
        Destroy();
    }

    if (yPosition <0.0f || position.y > Engine::Get().ScreenSize().y - maxY)
    {
        Destroy();
    }
    //// 탄약 발사.
    //static float elapsedTime = 0.0f;
    //static float fireInterval = RandomPercent(1.0f, 2.0f);
    //
    //// 타이머 업데이트.
    //elapsedTime += deltaTime;

    //// 타이머 처리.
    //if (elapsedTime < fireInterval)
    //{
    //    return;
    //}

    //// 타이머 초기화.
    //elapsedTime = 0.0f;
    //fireInterval = RandomPercent(1.0f, 2.0f);

    // 탄약 생성.
    /*Engine::Get().AddActor(
        new EnemyBullet(Vector2(position.x + width / 2, position.y))
    );*/
}
