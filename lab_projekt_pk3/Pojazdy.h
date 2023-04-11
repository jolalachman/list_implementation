#pragma once
#include <iostream>
#include<fstream>
#include<string>

class Pojazdy
{
private:
	std::string marka;
	std::string model;
	std::string rejestracja;
	long int przebieg;
	int rocznik;
	bool ac;
public:
	friend std::ostream& operator <<(std::ostream& s, const Pojazdy& p);
	friend std::istream& operator >>(std::istream& s, Pojazdy& p);
	friend bool operator<(const Pojazdy& l, const Pojazdy& r);
	friend bool operator>(const Pojazdy& l, const Pojazdy& r);
	friend bool operator==(const Pojazdy& l, const Pojazdy& r);
};

