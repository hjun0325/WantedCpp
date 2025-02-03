#include <iostream>
#include "GameRoomUser.h"

std::ostream& operator<<(std::ostream& os, UserInfo& userInfo)
{
	return os << "UserName: " << userInfo.userName
		<< ", Level: " << userInfo.level << ", Exp: " << userInfo.exp << std::endl;
}

int main()
{
	// �� ����.
	GameRoomUser gameRoom;

	// ���� �߰�.
	UserInfo user1("RonnieJ", 1, 30);
	gameRoom.AddUser(user1);

	UserInfo user2("Hamtol2", 10, 670);
	gameRoom.AddUser(user2);

	UserInfo user3("TaeJun", 5, 250);
	gameRoom.AddUser(user3);

	UserInfo user4("Oops", 32, 1250);
	gameRoom.AddUser(user4);

	UserInfo user5("Gamer", 40, 250);
	gameRoom.AddUser(user5);

	UserInfo user6("GameDev", 80, 3425);
	gameRoom.AddUser(user6);

	UserInfo user7("STL", 23, 890);
	gameRoom.AddUser(user7);

	// ���� Ȯ��.
	UserInfo roomMaster = gameRoom.GetMasterUser();
	if (roomMaster.userName != "")
	{
		std::cout << "������ " << roomMaster.userName << " �Դϴ�.\n";
	}

	// ���� ��.
	gameRoom.BanUser(1);

	// 3�� ��.
	gameRoom.BanUser(3);

	UserInfo userInfo;
	// GameDev�� ���� Ȯ��.
	std::cout << "[TaeJun�� ����] " << gameRoom.GetUserOfName("TaseJun", userInfo);

	// �������� �濡 ���� ���� ����.
	std::cout << "[���� �������� ���� ���� ����] " << gameRoom.GetUserOfLastOrder();

	// ��� ���� ����.
	gameRoom.Clear();

	// ��� ���� ���� �� ������� Ȯ��.
	std::cout << (gameRoom.IsEmpty() == true ? "���� ������ϴ�.\n" : "���� ������� �ʽ��ϴ�\n");

	std::cin.get();
}