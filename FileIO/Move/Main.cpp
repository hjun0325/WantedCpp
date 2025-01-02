#include <iostream>
#include <string>

class NPC
{
public:
	NPC() { std::cout << "기본 생성자\n"; }
	NPC(int npcCode, const std::string& name) { std::cout << "인자 있는 생성자\n"; }
	NPC(const NPC& other) { std::cout << "복사 생성자\n"; }
	NPC& operator=(const NPC& other) { std::cout << "대입 연산자\n"; return *this; }
	NPC(NPC&& other) { std::cout << "Move 생성자\n"; }
	NPC& operator=(NPC&& other) { std::cout << "Move 대입 연산자\n"; return *this; }

	int npcCode;
	std::string name;
};

int main()
{
	std::cout << "1\n";
	NPC npc1(NPC(10, "Orge1"));

	std::cout << "\n2\n";
	NPC npc2(11, "Orge2");
	NPC npc3 = std::move(npc2);

	std::cout << "\n3\n";
	NPC npc4;
	NPC npc5;
	npc5 = npc4;

	std::cout << "\n4\n";
	//NPC npc6 = NPC(12, "Orge3");
	NPC npc6(12, "Orge3");
	NPC npc6 = std::move(NPC(12, "Orge3"));

	std::cout << "\n5\n";
	NPC npc7;
	NPC npc8;
	//npc8 = std::move(npc7);
	npc8 = NPC(12, "Orge3");

	//memset()
	//memcpy()
	//memmove() 진짜 이동 (?)

	std::cin.get();
}

//포인터 변수는 힙 메모리를 가르키는데 일반 객체에 move를 하면 포인터가 아니라 값을 가리킬수가 없는데 얕은 복사를 어떻게 하지?