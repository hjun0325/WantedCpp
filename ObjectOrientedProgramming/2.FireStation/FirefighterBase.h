#pragma once

#include <string>
#include <iostream>
#include "Firetruck.h"
#include "INamedPerson.h"

class FirefighterBase : public INamedPerson
{
public:
	FirefighterBase(const std::string& name)
		:name(name)
	{

	}

	// 불끄기(ExtinguishFire).
	// 순수 가상 함수.
	virtual void ExtinguishFire() = 0;

	// 운전(Drive).
	void Drive(Firetruck* truckToDrive, const class Point& position)
	{
		// 운전자 확인.
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// 이동.
		truckToDrive->Drive(position);
	}

	// Getter/Setter.
	std::string GetName() const override { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

protected:
	std::string name;
};