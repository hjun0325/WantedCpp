#include "String.h"

String::String(const char* string)
{
    //입력 없이 생성했을 경우 크기를 1로
    //입력 문자열이 있을 경우 해당 길이값 반환
    //length = string == nullptr ? 1 : (int)strlen(string);
    length = string == nullptr ? 1 : static_cast<int>(strlen(string)) + 1;

    data = new char[length];
    if (string != nullptr)
    {
        strcpy_s(data, length, string);
    }
}

String::String(const String& other)
{
    length = other.length;
    data = new char[length];
    strcpy_s(data, length, other.data);
}

String::~String()
{
    delete[] data;
    data == nullptr;
}

String& String::operator=(const String& other)
{
    delete[] data;

    length = other.length;
    data = new char[length];
    strcpy_s(data, length, other.data);

    return *this;
}

String& String::operator+(const String& other)
{
    size_t newLength = length + other.length - 1;
    char* newString = new char[newLength];
    strcpy_s(newString, length, data);
    strcat_s(newString, newLength, other.data);

    delete[] data;
    //String temp = String(newString);
    //delete[] newString;
    //return temp;
    length = newLength;
    data = newString;
    return *this;
}

String& String::operator+=(const String& other)
{
    length = length + other.length - 1;
    char* newString = new char[length];
    strcpy_s(newString, strlen(data) + 1, data);
    strcat_s(newString, length, other.data);

    delete[] data;
    data = newString;
    return *this;
    //String temp = String(newString);
    //delete[] newString;
    //return temp;
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
    os << string.data;
    return os;
}

std::istream& operator>>(std::istream& is, String& string)
{
    char input[255];
    is >> input;

    string = String(input);
    return is;
}

bool String::operator==(const String& other)
{
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other)
{
    return strcmp(data, other.data) != 0;
    //return !(*this == other);
}

const int String::Length() const
{
    return length;
}

const char* String::Data() const
{
    return data;
}