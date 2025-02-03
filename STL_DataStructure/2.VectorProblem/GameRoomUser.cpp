#include <iostream>
#include "GameRoomUser.h"

// �濡 ������ �� �ִ� �ִ� ���� ��.
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
    // ����� ����� �������, ����� �߰� �� ���� �̸� ����.
    if (users.empty())
    {
        users.emplace_back(userInfo);
        masterUserName = userInfo.userName;
        return true;
    }

    // �濡 ������ �� á�� ��
    else if (users.size() < maxCount)
    {
        users.emplace_back(userInfo);
        return true;
    }
    
    std::cout << "�� �ο��� �� á���ϴ�.\n";
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

    // ������ ���� �̸��� ���� ���.
    if (iterator == users.end())
    {
        std::cout << "������ ������ �����ϴ�.\n";
        return false;
    }

    if (iterator == users.begin() && users.size() > 1)
    {
        masterUserName = users[1].userName;
    }

    // ���� ó��.
    users.erase(iterator);
    // ������ ������ ���.
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
    // �˻� �õ�.
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        // ����� ���� ã������ ������ �� �Ҵ�.
        if (iterator->userName == userName)
        {
            outUserInfo = *iterator;
            return true;
        }
    }
    std::cout << userName << " ������ ã�� ���߽��ϴ�.\n";
    return false;
}

UserInfo& GameRoomUser::GetMasterUser()
{
    if (users.empty())
    {
        std::cout << "Error: ���� ��� �ֽ��ϴ�.\n";
    }

    return users.at(0);
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    if (users.empty())
    {
        std::cout << "Error: ���� ��� �ֽ��ϴ�.\n";
    }

    return users.at(users.size() - 1);
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.empty())
    {
        std::cout << "Error: ���� ��� �־� ������ ������ �� �����ϴ�.\n";
        return false;
    }

    if (users.size() < orderNum)
    {
        std::cout << "�ε��� ����� �߸��Ǿ����ϴ�.\n";
        return false;
    }

    auto iterator = users.begin() + (orderNum - 1);
    users.erase(iterator);
    if (orderNum == 1 && users.size() > 0)
    {
        masterUserName = users[0].userName;
        std::cout << "���ο� ����: " << masterUserName << "\n";
    }

    return true;
}

void GameRoomUser::Clear()
{
    users.clear();
    masterUserName = "";
}