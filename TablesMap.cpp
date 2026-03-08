#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include "TablesMapClass.h"
#include "FrameClass.h"


TablesMap::TablesMap(std::string TablesFile) {
	std::ifstream GetTables;
	GetTables.open(TablesFile);

	if (!GetTables)
	{
		std::cerr << "Blad! nie otwarto pliku ze stolikami";
		exit(1);
	}

	std::string line;
	std::vector<std::string> AllTables;
	std::string TableID;
	int TableCount = 0;
	int MaxTablesInRow = 0;
	

	while (std::getline(GetTables, line))
	{
		int MaxTablesInRowNOW = 0;
		std::istringstream iss1(line);
		while (iss1 >> TableID)
		{
			AllTables.push_back(TableID);
			MaxTablesInRowNOW++;


		}
		TablesInRow.push_back(AllTables);
		AllTables.clear();

		if (MaxTablesInRow < MaxTablesInRowNOW)
		{
			MaxTablesInRow = MaxTablesInRowNOW;
		}
		
	}
	GetTables.close(); 
	// Szerokosc:
	int TIDSize = TablesInRow.back().back().size();
	int TIDWithoutSpace = (TIDSize * MaxTablesInRow);
	this->SpaceBetween = (TIDSize * 2);
	int AllSpaces = SpaceBetween * (MaxTablesInRow + 1);

	// Dlugosc: 
	int ColumnSpace = 2;
	int ColumnSpacesNumber = ColumnSpace * (TablesInRow.size() + 1);


	size_t x = TIDWithoutSpace + AllSpaces + 2;
	size_t y = ColumnSpacesNumber + TablesInRow.size()  + 2;

	ChangeSize(x, y);

}

void TablesMap::PrintTablesMap() { // funkcja printujaca tekst w ramce z przerwami miedzy tekstami (do stolikow)
	system("cls");
	SetFrame();

	
	int WriteNowLine = 0;

	std::cout << GetTop() << std::endl;
	
	for (auto i : TablesInRow)
	{
		for (size_t n = 0; n < 2; n++)
		{
			std::cout << GetInside() << std::endl;
		}

		std::string FramedTable;
		FramedTable.resize(GetFwidth(), ' ');
		
		int PutTable = SpaceBetween + 1;
		FramedTable[0] = GetOutlineSymbol();
		for (auto j : i)
		{
			FramedTable.insert(PutTable, j);
			PutTable += SpaceBetween + TablesInRow.back().back().size();
		}
		FramedTable[GetFwidth() - 1] = GetOutlineSymbol();
		std::cout << FramedTable << std::endl;
	}
	for (size_t n = 0; n < 2; n++)
	{
		std::cout << GetInside() << std::endl;
	} 

	std::cout << GetTop() << std::endl;
	
}
