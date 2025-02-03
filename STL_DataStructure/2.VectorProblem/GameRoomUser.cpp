#include <iostream>
#include "GameRoomUser.h"

// 방에 입장할 수 있는 최대 유저 수.
static const int maxCount = 6;

UserInfo::UserInfo(const std::string& name, int level, int exp)
    : userName(name), level(level), exp(exp)
{
}

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    // 사용자 목록이 비었으면, 사용자 추가 후 방장 이름 설정.
    if (users.empty())
    {
        users.emplace_back(userInfo);
        masterUserName = userInfo.userName;
        return true;
    }

    // 방에 정원이 안 찼을 때
    else if (users.size() < maxCount)
    {
        users.emplace_back(userInfo);
        return true;
    }
    
    std::cout << "방 인원이 다 찼습니다.\n";
    return false;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
    auto iterator = users.begin();
    for (;iterator != users.end();++iterator)
    {
        if (iterator->userName == userName)
        {
            break;
        }
    }

    // 삭제할 유저 이름이 없는 경우.
    if (iterator == users.end())
    {
        std::cout << "삭제할 유저가 없습니다.\n";
        return false;
    }

    if (iterator == users.begin() && users.size() > 1)
    {
        masterUserName = users[1].userName;
    }

    // 삭제 처리.
    users.erase(iterator);
    // 방장이 삭제될 경우.
    if (iterator == users.begin())
    {
        masterUserName = users[0].userName;
    }

    return true;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() == maxCount;
}

bool GameRoomUser::GetUserOfName(const char* userName, UserInfo& outUserInfo)
{
    // 검색 시도.
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        // 사용자 정보 찾았으면 변수에 값 할당.
        if (iterator->userName == userName)
        {
            outUserInfo = *iterator;
            return true;
        }
    }
    std::cout << userName << " 유저를 찾지 못했습니다.\n";
    return false;
}

UserInfo& GameRoomUser::GetMasterUser()
{
    if (users.empty())
    {
        std::cout << "Error: 방이 비어 있습니다.\n";
    }

    return users.at(0);
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    if (users.empty())
    {
        std::cout << "Error: 방이 비어 있습니다.\n";
    }

    return users.at(users.size() - 1);
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.empty())
    {
        std::cout << "Error: 방이 비어 있어 유저를 내보낼 수 없습니다.\n";
        return false;
    }

    if (users.size() < orderNum)
    {
        std::cout << "인덱스 계산이 잘못되었습니다.\n";
        return false;
    }

    auto iterator = users.begin() + (orderNum - 1);
    users.erase(iterator);
    if (orderNum == 1 && users.size() > 0)
    {
        masterUserName = users[0].userName;
        std::cout << "새로운 방장: " << masterUserName << "\n";
    }

    return true;
}

void GameRoomUser::Clear()
{
    users.clear();
    masterUserName = "";
}