#pragma once

class Czas {
private:
	int Hour;
	int Minutes;

public:
	class Czas(int Godziny, int Minuty);
	class Czas();
	int GetHours() const;
	int GetMinutes() const;
	void ChangeHours(int NewGodziny);
	void ChangeMinutes(int NewMinutes);
	std::string FullTimeString() const;

};