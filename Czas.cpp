#include <iostream>
#include <string>
#include "CzasClass.h"


Czas::Czas(int Godziny, int Minuty) {

	if (0 <= Godziny <= 23 && 0 <= Minuty <= 59)
	{
		this->Hour = Godziny;
		this->Minutes = Minuty;
	}
	else {
		std::cerr << "Blad! wprowadzono zla godzine!" << std::endl;
		exit(1);
	}

};
Czas::Czas() : Hour(0), Minutes(0) {};


int Czas::GetHours() const {
	return Hour;
}
int Czas::GetMinutes() const {
	return Minutes;
}

void Czas::ChangeHours(int NewGodziny) {
	this->Hour = NewGodziny;
}
void Czas::ChangeMinutes(int NewMinutes) {
	this->Minutes = NewMinutes;
}

std::string Czas::FullTimeString() const {
	std::string StringReturn;
	StringReturn += std::to_string(Hour);
	StringReturn += ':';
	StringReturn += std::to_string(Minutes);
	if (Minutes == 0)
	{
		StringReturn += std::to_string(0);
	}
	return StringReturn;

}