#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>
#include "FunctionDeclaration.h"
#include "StartMenuClass.h"
#include "TablesMapClass.h"





int main() {
	
	StartMenu Start;
	Start.PrintFrame();
	bool ZalogowanoAdmin = false;
	Wybor(ZalogowanoAdmin);


	TablesMap Mapa("stoliki.txt");
	Mapa.PrintTablesMap();
	
	Przerwa;
	
	std::map<std::string, std::vector<ReservationInfo>> AllReservations;
	PobieranieRezerwacji("rezerwacje.txt", AllReservations);
	std::string PodanyDzien;

	PodajDate(AllReservations, PodanyDzien);
	std::vector <std::string> AllTables;
	
	SprawdzStolikiRezerwacje(AllTables, AllReservations);
		
	
	
	PrintList(AllReservations[PodanyDzien]);
	
	Przerwa;
	
	PisaniePoWyborze(ZalogowanoAdmin, AllReservations, Mapa, PodanyDzien);
	


	
	return 0;
}