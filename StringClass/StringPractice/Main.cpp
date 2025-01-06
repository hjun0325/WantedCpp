#include <iostream>
#include "String.h"

int main()
{
    String name = String("Ronnie");
    name += " Jang";

    std::cout << name << "\n";

    if (name == "Ronnie Jang")
    {
        std::cout << "문자열 일치\n";
    }
    else
    {
        std::cout << "문자열 불일치\n";
    }

    String information = "Information ";
    String communication = "Communication ";
    String engineering = "Engineering";
    String major = information + communication + engineering;

    std::cout << major << "\n";

    String inputString;
    //getline(std::cin, inputString);
    //std::cin.getline >> inputString;

    std::cout << "입력된 값: " << inputString << "\n";

}