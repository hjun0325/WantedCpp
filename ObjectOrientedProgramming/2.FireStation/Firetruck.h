#pragma once

#include <iostream>
#include "Point.h"
#include "Ladder.h"
#include "Hose.h"

// 전방 선언 (Forward Declaration)
// 왜? 헤더 순환 참조 방지.
// 컴파일 속도 개선.
class FirefighterBase;
class Firetruck
{
public:
	Firetruck()
	{
		// 팩토리 패턴.


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

		std::cout << position << "위치로 소방차 이동 중\n";
	}

	const Ladder* GetLadder() const { return ladder; }


	const Hose* GetHose() const { return hose; }
	void SetHose(Hose* hose) { this->hose = hose; }

	FirefighterBase* GetDriver() const { return driver; }
	void SetDriver(FirefighterBase* driver) { this->driver = driver; }

private:
	// 포인터는 주소의 크기만 알면 되고 일반 객체는 전체 크기를 알아야함
	FirefighterBase* driver = nullptr;
	Ladder* ladder = nullptr;
	Hose* hose = nullptr;
};