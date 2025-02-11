#pragma once

#include "FirefighterBase.h"

class Firechief : public FirefighterBase
{
public:
	Firechief(const std::string& name, FirefighterBase* numberOne = nullptr)
		: FirefighterBase(name), numberOne(numberOne)
	{

	}

	// ������.
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
	// �Ҳ��� ���� �Լ�.
	void TellFirefighterToExtinguishFire(FirefighterBase* colleague)
	{
		colleague->ExtinguishFire();
	}

private:
	FirefighterBase* numberOne = nullptr;

};