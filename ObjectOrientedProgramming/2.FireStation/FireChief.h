#pragma once

#include "FirefighterBase.h"

class Firechief : public FirefighterBase
{
public:
	Firechief(const std::string& name, FirefighterBase* numberOne = nullptr)
		: FirefighterBase(name), numberOne(numberOne)
	{

	}

	// 재정의.
	virtual void ExtinguishFire() override
	{
		if (numberOne == nullptr)
		{
			return;
		}
		
		TellFirefighterToExtinguishFire(numberOne);
	}

	// Getter/Setter.
	const FirefighterBase* GetNumberOne() const { return numberOne; }
	void SetNumberOner(FirefighterBase* numberOne) { this->numberOne = numberOne; }

private:
	// 불끄기 위임 함수.
	void TellFirefighterToExtinguishFire(FirefighterBase* colleague)
	{
		colleague->ExtinguishFire();
	}

private:
	FirefighterBase* numberOne = nullptr;

};