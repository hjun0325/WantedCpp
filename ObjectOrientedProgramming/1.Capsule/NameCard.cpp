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
	std::cout << "이    름: " << name << "\n"
		<< "전화번호: " << phoneNumber << "\n"
		<< "주    소: " << address << "\n"
		<< "직    급: " << job << "\n";
}
