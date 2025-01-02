#include <iostream>
#include "String.h"

int main()
{
	String string("RonnieJ");

	std::cout << string << "\n";

	string = "Test String.";

	std::cout << string << "\n";
	std::cout << string.Length() << "\n";

	auto result = string == "Test String." ? "True" : "False";
	std::cout << ((string == "RonnieJ") ? "True" : "False") << "\n";
	std::cout << result << "\n";
	std::cin.get();
}