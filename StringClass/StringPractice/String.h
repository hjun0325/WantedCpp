#pragma once
#include<iostream>

class String
{
public:
	String(const char* string = nullptr);
	String(const String& other);
	~String();

	friend std::ostream& operator<<(std::ostream& os, const String& string);
	friend std::istream& operator>>(std::istream& os, String& string);

	String& operator=(const String& other);
	String& operator+(const String& other);
	String& operator+=(const String& other);

	bool operator==(const String& other);
	bool operator!=(const String& other);

	const int Length() const;
	const char* Data() const;
private:
	int length;
	char* data;
};

