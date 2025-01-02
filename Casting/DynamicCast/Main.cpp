#include <iostream>

//Ÿ�� ������ ���� ��ũ��
#define RTTI(name)	\
	public:	\
		virtual const char* ClassName() const { return #name; }

class Actor
{
	RTTI(Actor)
public:
	//�����Լ�
	virtual void PrintValue()
	{
		std::cout << "Value: " << a << "\n";
	}
protected:
	int a;
};

class Player : public Actor
{
	RTTI(Player)
};

int main()
{
	//��ü ����
	Actor* actor = new Actor();
	Player* player = new Player();

	//�� ĳ���� (������ ����ȯ ��)
	//Actor* actorPoint = static_cast<Actor*>(player);
	Actor* actorPoint = (player);

	//Player* playerPointer = dynamic_cast<Player*> (actorPoint);
	Player* playerPointer = static_cast<Player*> (actorPoint);
		
	//not ok
	Player* player2 = dynamic_cast<Player*> (actor);
	//Player* player2 = static_cast<Player*> (actor);
	
	// ���� ó�� �ٿ�ĳ������ �� ������
	if (player2)
	//if (Player* player2 = dynamic_cast<Player*> (actor);)
	{
		//�Լ� ȣ��
		player2->PrintValue();
	}
	else
	{
		std::cout << "����ȯ ����\n";
	}

	//typeid
	const type_info& info = typeid(actorPoint);
	std::cout << "Ÿ�� �̸�: " << info.name() << "\n";

	std::cout << "Actor Ÿ��: " << actor->ClassName() << "\n";
	std::cout << "Player Ÿ��: " << player->ClassName() << "\n";
	std::cout << "ActorPoint Ÿ��: " << actorPoint->ClassName() << "\n";

	//Ÿ�� ��
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "Ÿ�� ����\n";
	}
	else
	{
		std::cout << "Ÿ�� �ٸ�\n";
	}
}