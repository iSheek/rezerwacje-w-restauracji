#include <iostream>
#include <string>
#include "FrameClass.h"
#include "StartMenuClass.h"

StartMenu::StartMenu(void) : Frame(40, 10) {};

void StartMenu::PrintFrame() {
	SetFrame();
	std::cout << GetTop() << std::endl;
	PrintFramedTextMiddle("Rezerwacje w restauracji", 0);
	std::cout << GetInside() << std::endl;
	PrintFramedTextMiddle("do wyboru:", 12);
	PrintFramedTextMiddle("- rezerwacja stolikow (1)", 5);
	PrintFramedTextMiddle("- admin (2)", 12);
	for (size_t i = 0; i < GetFlength() - 5; i++)
	{
		std::cout << GetInside() << std::endl;
	}
	std::cout << GetTop() << std::endl;
}
