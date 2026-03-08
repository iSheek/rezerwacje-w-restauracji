#include <iostream>
#include <string>
#include "CzasClass.h"
#include "DzienClass.h"
#include "ReservationInfoClass.h" 


ReservationInfo::ReservationInfo(std::string Nazwisko, std::string Stolik, int Godzina, int Minuty, int Dzien, int Miesiac) : FullName(Nazwisko), Table(Stolik), Czas(Godzina, Minuty), Dzien(Dzien, Miesiac), ReservationID(++CurrentID) {};

bool ReservationInfo::operator==(const ReservationInfo& rhs) const { return FullTimeString() == rhs.FullTimeString(); }
bool ReservationInfo::operator==(const std::string& rhs) const { return GetTable() == rhs; }
bool ReservationInfo::operator < (const ReservationInfo& str) const
{
	return (this->Table < str.GetTable());
}

std::string ReservationInfo::GetFullName() const {
	return FullName;
}
std::string ReservationInfo::GetTable() const {
	return Table;
}
int ReservationInfo::GetReservationID() const {
	return ReservationID;
}

std::string ReservationInfo::GetReservationIDString() const {
	return std::to_string(ReservationID);
}