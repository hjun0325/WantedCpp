#pragma once

#include <vector>
#include <string>

// ���� ����
struct UserInfo
{
	UserInfo() = default;
	UserInfo(const std::string& userName, int level, int exp);

	std::string userName;	// �̸�.
	int level;			// ����.
	int exp;			// ����ġ.
};

// ���� ���� ������ �����ϴ� Ŭ����
// �濡�� �ִ� 6����� ��� �� �� �ִ�.
// �濡 ��� ���� ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

	// �濡 ���� �߰�
	bool AddUser(UserInfo& userInfo);

	// �濡�� ���� ����.
	// ���� ������ ������ userName�� ���ο� ������ �̸��� ���� �ؾ� �ȴ�.
	bool DeleteUser(const char* userName);

	// �濡 ������ ������ Ȯ��. ������ true ��ȯ
	bool IsEmpty();

	// �濡 ������ �� á���� Ȯ��. �� á�ٸ� true ��ȯ
	bool IsFull();

	// Ư�� ������ ����
	bool GetUserOfName(const char* userName, UserInfo& outUserInfo);

	// ������ ���� ����
	UserInfo& GetMasterUser();

	// ���� �������� �濡 ��� �� ������ ����
	UserInfo& GetUserOfLastOrder();

	// Ư�� ������ ��� �� ������ �i�Ƴ���.
	bool BanUser(int orderNum);

	// ��� ������ �����Ѵ�.
	void Clear();

private:
	std::vector<UserInfo> users;
	std::string masterUserName; // ������ �̸�
};