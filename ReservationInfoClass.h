#pragma once

#include <iostream>
#include <string>
#include "CzasClass.h"
#include "DzienClass.h"


class ReservationInfo : public Czas, public Dzien {
private:
	std::string FullName;
	std::string Table;
	int ReservationID;
	static int CurrentID;

public:
	ReservationInfo(std::string Nazwisko, std::string Stolik, int Godzina, int Minuty, int Dzien, int Miesiac);
	bool operator==(const ReservationInfo& rhs) const;
	bool operator==(const std::string& rhs) const;
	bool operator < (const ReservationInfo& str) const;
	std::string GetFullName() const;
	std::string GetTable() const;
	int GetReservationID() const;	
	std::string GetReservationIDString() const;

};


