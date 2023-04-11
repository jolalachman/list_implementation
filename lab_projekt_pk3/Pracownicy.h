#pragma once
#include <iostream>
#include<fstream>
#include<string>

class Pracownicy
{
private:
	std::string imie;
	std::string nazwisko;
	int wiek;
	std::string dzial;
	long int id;
	bool rodo;
public:
	friend std::ostream& operator <<(std::ostream& s, const Pracownicy& p);
	friend std::istream& operator >>(std::istream& s, Pracownicy& p);
	friend bool operator<(const Pracownicy& l, const Pracownicy& r);
	friend bool operator>(const Pracownicy& l, const Pracownicy& r);
	friend bool operator==(const Pracownicy& l, const Pracownicy& r);
};

