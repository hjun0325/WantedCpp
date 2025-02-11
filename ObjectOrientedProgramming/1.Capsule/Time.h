#pragma once

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0);
	~Time();

	void ShowTime();
	void ShowTimeInSeconds();
	
private:
	int hour;
	int minute;
	int second;
};