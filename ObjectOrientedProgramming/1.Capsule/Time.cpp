#include "Time.h"
#include <iostream>

Time::Time(int hour, int minute, int second)
	: hour(hour), minute(minute), second(second)
{
}

Time::~Time()
{
}

void Time::ShowTime()
{
	std::cout << "[" << hour << "시 " << minute << "분 " << second << "초]\n";
}

void Time::ShowTimeInSeconds()
{
	int totalSecond = 60 * 60 * hour + 60 * minute + second;
	std::cout << totalSecond << "초\n";
}
