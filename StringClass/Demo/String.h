#pragma once

#include <iostream>

//직접 구현해보는 문자열 클래스
//MFC - UI
class String
{
public:
	//일반생성자
	String(const char* string = nullptr);
	
	//복사생성자
	String(const String& other);
	
	//소멸자
	~String();

	//연산자 오버로딩
	friend std::ostream& operator<<(std::ostream& os, const String& string);

	//대입 연산자
	String& operator=(const String& other);

	//비교 연산자
	bool operator==(const String& other);
	bool operator!=(const String& other);

	//Getter
	const int Length() const;
	const char* Data() const;

private:
	int length; //문자열 길이
	char* data; //문자열 저장하는 변수(저장소/컨테이너)
};