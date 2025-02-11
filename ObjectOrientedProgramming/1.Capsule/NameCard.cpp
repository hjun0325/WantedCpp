#include "NameCard.h"
#include <iostream>

NameCard::NameCard(const std::string& name, const std::string& phoneNumber,
	const std::string& address, const std::string& job)
	: name(name), phoneNumber(phoneNumber), address(address), job(job)
{
}

NameCard::~NameCard()
{
}

void NameCard::ShowData()
{
	std::cout << "��    ��: " << name << "\n"
		<< "��ȭ��ȣ: " << phoneNumber << "\n"
		<< "��    ��: " << address << "\n"
		<< "��    ��: " << job << "\n";
}
