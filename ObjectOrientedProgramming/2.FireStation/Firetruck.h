#pragma once

#include <iostream>
#include "Point.h"
#include "Ladder.h"
#include "Hose.h"

// ���� ���� (Forward Declaration)
// ��? ��� ��ȯ ���� ����.
// ������ �ӵ� ����.
class FirefighterBase;
class Firetruck
{
public:
	Firetruck()
	{
		// ���丮 ����.


		ladder = new Ladder(10.0f);
	}

	~Firetruck()
	{
		delete ladder;
	}

	void Drive(const Point& position)
	{
		if (driver == nullptr)
		{
			return;
		}

		std::cout << position << "��ġ�� �ҹ��� �̵� ��\n";
	}

	const Ladder* GetLadder() const { return ladder; }


	const Hose* GetHose() const { return hose; }
	void SetHose(Hose* hose) { this->hose = hose; }

	FirefighterBase* GetDriver() const { return driver; }
	void SetDriver(FirefighterBase* driver) { this->driver = driver; }

private:
	// �����ʹ� �ּ��� ũ�⸸ �˸� �ǰ� �Ϲ� ��ü�� ��ü ũ�⸦ �˾ƾ���
	FirefighterBase* driver = nullptr;
	Ladder* ladder = nullptr;
	Hose* hose = nullptr;
};