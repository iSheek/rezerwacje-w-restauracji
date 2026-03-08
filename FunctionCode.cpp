#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include "FunctionDeclaration.h"
#include "TablesMapClass.h"



int ReservationInfo::CurrentID = 0000;

void AdminHaslo(bool& Wybrany) {
	PiszHaslo:
	std::string wpisanehaslo;
	std::cin >> wpisanehaslo;
	std::fstream plikhaslo;
	plikhaslo.open("haslo.txt");
	if (!(plikhaslo))
	{
		std::cerr << "Blad! plik z haslem nie zostal otwarty" << std::endl;
		exit(1);
	}
	std::string ustawionehaslo;
	std::getline(plikhaslo, ustawionehaslo);
	plikhaslo.close();

	if (wpisanehaslo == ustawionehaslo)
	{
		std::cout << "Poprawne haslo" << std::endl;
		Wybrany = true;

	}
	else
	{
		std::cerr << "Zle haslo!" << std::endl;
		goto PiszHaslo;
	}
} 


void PrintList(std::vector <ReservationInfo> RezerwacjeNaDzien) {
	std::cout << RezerwacjeNaDzien.back().FullDateString() << ": " << std::endl;
	std::string AktualnyString;
	AktualnyString.insert(0, "ID:");
	AktualnyString.resize(AktualnyString.size() + 8, ' ');
	AktualnyString.insert(8, "Stolik:");
	AktualnyString.resize(AktualnyString.size() + 18, ' ');
	AktualnyString.insert(18, "Nazwisko:");
	AktualnyString.resize(AktualnyString.size() + 35, ' '); 
	AktualnyString.insert(35, "Godzina:");
	std::cout << AktualnyString << std::endl;
	
	std::sort(RezerwacjeNaDzien.begin(), RezerwacjeNaDzien.end(), [](const ReservationInfo &A, const ReservationInfo &B) {return A.GetReservationID() > B.GetReservationID(); }); // Sortowanie, aby wektor byl wg. ID od tylu

	while (RezerwacjeNaDzien.size() != 0)
	{	AktualnyString.clear();
		AktualnyString.resize(50, ' ');

		AktualnyString.insert(0, RezerwacjeNaDzien.back().GetReservationIDString());
		AktualnyString.insert(8, RezerwacjeNaDzien.back().GetTable());
		AktualnyString.insert(18, RezerwacjeNaDzien.back().GetFullName());
		AktualnyString.insert(35, RezerwacjeNaDzien.back().FullTimeString());
		
		std::cout << AktualnyString << std::endl;

		RezerwacjeNaDzien.pop_back();

	}

	

}


void Wybor(bool &Wybrany) {
	int wyborcyfra;
	std::cin >> wyborcyfra;
	if ((wyborcyfra != 1) && (wyborcyfra != 2))
	{	
		std::cerr << "Zly wybor";
		exit(1);
	}
	else if (wyborcyfra == 2)
	{
		std::cout << "Podaj haslo: ";
		AdminHaslo(Wybrany);
	}

}


void PodajDate(std::map<std::string, std::vector<ReservationInfo>> AllReservations, std::string &PodanyDzien) {
	std::cout << "Podaj dzien" << std::endl;

PisanieDnia:
	std::cin >> PodanyDzien;
	Przerwa;
	
	if (PodanyDzien.find('.') == std::string::npos)
	{
		std::cerr << "Blad! Zle podano date! Podaj inna:" << std::endl;
		Przerwa;
		goto PisanieDnia;

	}
	if (!(AllReservations.find(PodanyDzien) != AllReservations.end()))
	{
		std::cerr << "Nie ma zadnych rezerwacji na te date!" << std::endl;
		Przerwa;
		goto PisanieDnia;

	}
}


void PobieranieRezerwacji(std::string FileName, std::map<std::string, std::vector<ReservationInfo>> &AllReservations) {
	std::ifstream PlikRezerwacji;
	PlikRezerwacji.open(FileName);
	if (!PlikRezerwacji)
	{
		std::cerr << "Blad! nie otwarto pliku z rezerwacjami!" << std::endl;
		exit(1);
	}
	
	std::vector<ReservationInfo> DayReservations;
	std::string line;
	int Dzien;
	int Miesiac;
	int przejscie = 0;
	std::string DataDzien;

	while (std::getline(PlikRezerwacji, line)) {

		if (line.find('.') != std::string::npos)
		{
			if (przejscie > 0)
			{
				AllReservations.emplace(DataDzien, DayReservations);
				DayReservations.clear();
				DataDzien.clear();
			}
			char kropka;
			std::istringstream iss(line);
			iss >> Dzien; iss >> kropka; iss >> Miesiac;

			DataDzien += std::to_string(Dzien);
			DataDzien += kropka;
			DataDzien += std::to_string(Miesiac);


			

			przejscie++;

		}

		else if (line != "")
		{

			std::istringstream iss(line);

			std::string Stolik;
			std::string Nazwisko;
			int Godzina;
			int Minuty;
			char dwukropek;

			iss >> Stolik; iss >> Nazwisko; iss >> Godzina; iss >> dwukropek; iss >> Minuty;
			ReservationInfo RezerwacjaTeraz(Nazwisko, Stolik, Godzina, Minuty, Dzien, Miesiac);
			DayReservations.push_back(RezerwacjaTeraz);
		}
	}
	if (przejscie > 0)
	{
		AllReservations.emplace(DataDzien, DayReservations);
		DayReservations.clear();
		DataDzien.clear();
	}

	PlikRezerwacji.close();
}


void PisaniePoWyborze(bool ZalogowanoAdmin, std::map<std::string, std::vector<ReservationInfo>>& AllReservations, TablesMap Mapa, std::string &PodanyDzien) {
		
	StartWybierania:
	std::cout << "wybor: dodaj, usun(dla admina), b (powrot), q (wyjscie)" << std::endl;
		std::string Decyzja;
		std::cin >> Decyzja;
		std::transform(Decyzja.begin(), Decyzja.end(), Decyzja.begin(), ::tolower);
		if (Decyzja == "dodaj")
		{
		PoczatekDodawania:

			Decyzja.clear();
			std::cout << "wpisz: date, nr stolika, nazwisko,  godzina" << std::endl;
			std::string GivenDate, GivenTable, GivenName, GivenHour;
			std::cin >> GivenDate;
			std::cin.ignore();
			std::getline(std::cin, Decyzja);
			std::istringstream iss(Decyzja);
			iss >> GivenTable; iss >> GivenName; iss >> GivenHour;
			GivenDate.erase(std::remove(GivenDate.begin(), GivenDate.end(), ','), GivenDate.end());
			GivenTable.erase(std::remove(GivenTable.begin(), GivenTable.end(), ','), GivenTable.end());
			GivenName.erase(std::remove(GivenName.begin(), GivenName.end(), ','), GivenName.end());
			GivenHour.erase(std::remove(GivenHour.begin(), GivenHour.end(), ','), GivenHour.end());

			std::vector <ReservationInfo> NowInfo;
			NowInfo = AllReservations[GivenDate];

			std::vector <ReservationInfo> SameHour;
			int SameTable = 0;
			for (auto i : NowInfo)
			{
				if (i.FullTimeString() == GivenHour)
				{
					SameHour.push_back(i);
				}

			}

			std::sort(SameHour.begin(), SameHour.end());

			if (std::find(SameHour.begin(), SameHour.end(), GivenTable) != SameHour.end())
			{ 
				std::cout << "Blad, dany stolik o danej godzinie jest juz zarezerwowany!" << std::endl;
				Przerwa;
				goto PoczatekDodawania;
			}


			std::istringstream issDate(GivenDate);
			char znak;
			int Dzien, Miesiac;
			issDate >> Dzien; issDate >> znak; issDate >> Miesiac;
			std::istringstream issTime(GivenHour);
			int Godziny, Minuty;
			issTime >> Godziny; issTime >> znak; issTime >> Minuty;
			GivenName[0] = std::toupper(GivenName[0]);
			ReservationInfo DodanaRezerwacja(GivenName, GivenTable, Godziny, Minuty, Dzien, Miesiac);
			NowInfo.push_back(DodanaRezerwacja);
			AllReservations[GivenDate] = NowInfo;
			std::cout << "Pomyslnie dodano rezerwacje!" << std::endl;

		}
		else if (Decyzja == "usun" && ZalogowanoAdmin) {
		PisanieIDDoUsuniecia:
			bool Znaleziono = false;
			std::cout << "Podaj ID rezerwacji, ktora chcesz usunac?" << std::endl;
			int IDtoDelete;
			std::cin >> IDtoDelete;
			for (std::map<std::string, std::vector<ReservationInfo>>::iterator iter = AllReservations.begin(); iter != AllReservations.end(); iter++)
			{	
				int VectorPos = 0;
				std::string klucz = iter->first;
				for (auto i : AllReservations[klucz])
				{
					
					if (i.GetReservationID() == IDtoDelete)
					{
						AllReservations[klucz].erase(AllReservations[klucz].begin() + VectorPos);
						goto KoniecKasowania;
						Znaleziono = true;
					}
					VectorPos++;
				}
				
			}
			if (!Znaleziono)
			{
				std::cout << "Nie istnieje rezerwacja o takim ID!" << std::endl;
				Przerwa;
				goto PisanieIDDoUsuniecia;
			}
		
		}
		else if (Decyzja == "b") {
			system("cls");
			Mapa.PrintTablesMap();
			PodajDate(AllReservations, PodanyDzien);
			PrintList(AllReservations[PodanyDzien]);
			Przerwa;
			PisaniePoWyborze(ZalogowanoAdmin, AllReservations, Mapa, PodanyDzien); 

		}
		else if (Decyzja == "q") {
			exit(0);
		}
		KoniecKasowania:
		system("cls");
		Mapa.PrintTablesMap();
		Przerwa;
		PrintList(AllReservations[PodanyDzien]);
		std::cout << std::endl;

		goto StartWybierania;
	
}


void SprawdzStolikiRezerwacje(std::vector <std::string>& AllTables, std::map<std::string, std::vector<ReservationInfo>> AllReservations) {
	std::ifstream plik;
	plik.open("stoliki.txt");
	if (!plik)
	{
		std::cerr << "Blad! nie otwarto pliku ze stolikami!" << std::endl;
	}
	std::string line;
	while (std::getline(plik, line)) {
		std::istringstream iss(line);
		std::string OneTable;
		while (iss >> OneTable) {
			AllTables.push_back(OneTable);
		}
	}
	plik.close();

	for (auto i : AllReservations)
	{
		for (auto j : i.second)
		{
			if (std::find(AllTables.begin(), AllTables.end(), j.GetTable()) == AllTables.end())
			{
				std::cerr << "Blad!, stoliki w liscie rezerwacji nie zgadzaja sie z lista stolikow!" << std::endl;
				exit(1);
			}
		}

	}
}