#include "Player.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"
#include "PreCompiledHeader/PreCompiledHeader.h"
#include "Actor/PlayerBullet.h"

Player::Player(Vector2 position)
    :position(position)
{
}

Player::Player(const char* image)
    : Super(image)
{
    // 플레이어 시작 위치
    //position = Vector2(0, 20);
    // 가로 : 80, 세로 : 25
    position = Vector2(Engine::Get().ScreenSize().x/2 , Engine::Get().ScreenSize().y/2);
}

void Player::Update(float deltaTime)
{
    // 부모 함수 호출
    Super::Update(deltaTime);
    

    //탄약 발사.
    if (Engine::Get().GetKeyDown(VK_SPACE))
    {
        Vector2 bulletPosition(position.x + (maxX/2 ), position.y);
        Engine::Get().AddActor(new PlayerBullet(bulletPosition));
    }




    //// 키 입력 처리
    //if (Engine::Get().GetKey(VK_LEFT))
    //{
    //    // 새 위치 계산
    //    Vector2 newPosition = position;
    //    --newPosition.x;
    //    if (newPosition.x < 0)
    //    {
    //        newPosition.x = 0;
    //    }

    //    SetPosition(newPosition);
    //}

    //// 키 입력 처리
    //if (Engine::Get().GetKey(VK_RIGHT))
    //{
    //    // 새 위치 계산
    //    Vector2 newPosition = position;
    //    ++newPosition.x;
    //    if (newPosition.x >  Engine::Get().ScreenSize().x - width)
    //    {
    //        newPosition.x = Engine::Get().ScreenSize().x - width;
    //    }

    //    SetPosition(newPosition);
    //}
    //// 키 입력 처리
    //if (Engine::Get().GetKey(VK_UP))
    //{
    //    // 새 위치 계산
    //    Vector2 newPosition = position;
    //    --newPosition.y;
    //    if (newPosition.y < 0 )
    //    {
    //        newPosition.y = 0;
    //    }

    //    SetPosition(newPosition);
    //}
    //  // 키 입력 처리
    //if (Engine::Get().GetKey(VK_DOWN))
    //{
    //    // 새 위치 계산
    //    Vector2 newPosition = position;
    //    ++newPosition.y;
    //    if (newPosition.y >  Engine::Get().ScreenSize().y - maxY-1)
    //    {
    //        newPosition.y = Engine::Get().ScreenSize().y - maxY-1;
    //    }

    //    SetPosition(newPosition);
    //}
}
