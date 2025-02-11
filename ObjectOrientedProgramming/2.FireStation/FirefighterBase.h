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

	// �Ҳ���(ExtinguishFire).
	// ���� ���� �Լ�.
	virtual void ExtinguishFire() = 0;

	// ����(Drive).
	void Drive(Firetruck* truckToDrive, const class Point& position)
	{
		// ������ Ȯ��.
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// �̵�.
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