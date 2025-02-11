#pragma once

#include <string>

class NameCard
{
public:
	NameCard(const std::string& name, const std::string& phoneNumberm,
		const std::string& address, const std::string& job);
	~NameCard();

	void ShowData();

private:
	std::string name;
	std::string phoneNumber;
	std::string address;
	std::string job;
};