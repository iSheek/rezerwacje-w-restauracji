#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>

#include "FrameClass.h"


class TablesMap : public Frame {
private:
	std::vector <std::vector<std::string>> TablesInRow;
	int SpaceBetween = 0;
public:
	class TablesMap(std::string TablesFile);
	void PrintTablesMap();
};