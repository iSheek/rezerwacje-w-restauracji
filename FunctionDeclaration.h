#pragma once

#include "ReservationInfoClass.h"
#include "TablesMapClass.h"

#define Przerwa std::cout << std::endl << std::endl

void AdminHaslo(bool& Wybrany);

void Wybor(bool &Wybrany);


void PrintList(std::vector <ReservationInfo> RezerwacjeNaDzien);

void PobieranieRezerwacji(std::string FileName, std::map<std::string, std::vector<ReservationInfo>>& AllReservations);

void PodajDate(std::map<std::string, std::vector<ReservationInfo>> AllReservations, std::string& PodanyDzien); 

void PisaniePoWyborze(bool ZalogowanoAdmin, std::map<std::string, std::vector<ReservationInfo>>& AllReservations, TablesMap Mapa, std::string &PodanyDzien);

void SprawdzStolikiRezerwacje(std::vector <std::string>& AllTables, std::map<std::string, std::vector<ReservationInfo>> AllReservations);