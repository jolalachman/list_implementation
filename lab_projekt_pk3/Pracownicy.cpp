#include "Pracownicy.h"


std::ostream& operator <<(std::ostream& s, const Pracownicy& p)
{
	s << p.imie << " " << p.nazwisko << " " << p.wiek << " " << p.dzial << " " << p.id << " " << p.rodo;
	return s;
}

std::istream& operator >>(std::istream& s, Pracownicy& p)
{
	s >> p.imie >> p.nazwisko >> p.wiek >> p.dzial >> p.id >> p.rodo;
	return s;
}


bool operator<(const Pracownicy& l, const Pracownicy& r)
{
	if (l.imie < r.imie)
		return true;
	else
		return false;
}
bool operator>(const Pracownicy& l, const Pracownicy& r)
{
	if (l.imie > r.imie)
		return true;
	else
		return false;
}
bool operator==(const Pracownicy& l, const Pracownicy& r)
{
	if (l.imie == r.imie and l.nazwisko == r.nazwisko and l.wiek == r.wiek and l.dzial == r.dzial and l.id == r.id and l.rodo == r.rodo)
		return true;
	else
		return false;
}