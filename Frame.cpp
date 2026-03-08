#include <iostream>
#include <string>
#include "FrameClass.h"


Frame::Frame() {}
Frame::Frame(size_t Fwidth, size_t Flength) {		// konstruktor, w ktorym podajemy rozmiary ramki
	this->Fwidth = Fwidth;
	this->Flength = Flength;
};

void Frame::ChangeOutline(char newSymbol) {
	this->outlineSymbol = newSymbol;
}


void Frame::SetFrame() {			// funkcja, ktora ustawia nam krance ramki oraz jej srodek, zgodnie z tym co podalismy
	this->topandbottom.resize(Fwidth, outlineSymbol);
	this->inside.resize(Fwidth, ' ');
	this->inside[0] = outlineSymbol;
	this->inside[Fwidth - 1] = outlineSymbol;
}

std::string Frame::GetTop() const{
	return this->topandbottom;
}

std::string Frame::GetInside() const {
	return this->inside;
}

char Frame::GetOutlineSymbol() const {
	return this->outlineSymbol;
}

size_t Frame::GetFlength() const {
	return this->Flength;
}

size_t Frame::GetFwidth() const {
	return this->Fwidth;
}

void Frame::ChangeSize(size_t NewFwidth, size_t NewFlength) {
	this->Fwidth = NewFwidth;
	this->Flength = NewFlength;
}

void Frame::PrintFrame() {					// funkcja rysujaca ramke (tutaj sama ramka)
	SetFrame();
	std::cout << this->topandbottom << std::endl;
	for (size_t i = 0; i < Flength - 2; i++)
	{
		std::cout << this->inside << std::endl;
	}
	std::cout << this->topandbottom << std::endl;

}
void Frame::PrintFramedTextMiddle(std::string Napis, size_t left) {	// funkcja printujaca tekst w ramce (z przesunieciem w lewo)
	size_t napislength = Napis.size();
	size_t poczateknapisu = (std::ceil((GetInside().size() - Napis.size()) / 2));		// wprowadzone zaokraglenie gdyby wystepowaly liczby nieparzyste
	Napis.insert(0, poczateknapisu - left, ' ');			// wypelnianie napisu z lewej strony pustym aby wysrodkowac
	Napis.insert(poczateknapisu + napislength - left, poczateknapisu + left, ' ');	// wypelnianie napisu z prawej strony aby wysrodkowac
	Napis[0] = GetOutlineSymbol();
	Napis[Napis.size() - 1] = GetOutlineSymbol();
	if (Napis.size() != Fwidth) {
		if (Napis[Napis.size() - 2] == NULL)
		{
			Napis.insert(Napis.size() - 2, " ");
		}
		else
		{
			Napis.insert(1, " ");
		}
	}
	std::cout << Napis << std::endl;
}


