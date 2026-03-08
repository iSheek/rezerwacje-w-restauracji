#pragma once
#include <string>
#include <iostream>


class Frame {
	char outlineSymbol = '#';
	size_t Fwidth = 0;
	size_t Flength = 0;
	std::string topandbottom;
	std::string inside;

public:
	class Frame();
	class Frame(size_t Fwidth, size_t Flength);
	void ChangeOutline(char newSymbol);
	void SetFrame();
	std::string GetTop() const;
	std::string GetInside() const;
	char GetOutlineSymbol() const;
	size_t GetFlength() const;
	size_t GetFwidth() const;
	void ChangeSize(size_t NewFwidth, size_t NewFlength);

	virtual void PrintFrame();
	void PrintFramedTextMiddle(std::string Napis, size_t left);

};