#include <iostream>
#include <string>
#include "DzienClass.h"


Dzien::Dzien(int Day, int Month) {
		if (0 <= Day <= 31 && 0 <= Month <= 12)
		{
			this->Day = Day;
			this->Month = Month;
		}
		else {
			std::cerr << "Blad! Wprowadzono zla date!" << std::endl;
			exit(1);
		}
	};

	int Dzien::GetDay() const {
		return Day;
	}

	int Dzien::GetMonth() const {
		return Month;
	}

	void Dzien::ChangeDay(int NewDay) {
		this->Day = NewDay;
	}

	void Dzien::ChangeMonth(int NewMonth) {
		this->Month = NewMonth;
	}

	std::string Dzien::FullDateString() const {
		std::string StringReturn;
		StringReturn += std::to_string(Day);
		StringReturn += '.';
		StringReturn += std::to_string(Month);
		return StringReturn;
	}
