#pragma once

#include <iostream>
#include <string>


class Dzien {
private:
	int Day;
	int Month;
public:
	Dzien(int Day, int Month);
	int GetDay() const;
	int GetMonth() const;
	void ChangeDay(int NewDay);
	void ChangeMonth(int NewMonth);
	std::string FullDateString() const;
};