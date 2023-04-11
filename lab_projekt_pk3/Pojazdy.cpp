#include "Pojazdy.h"



std::ostream& operator <<(std::ostream& s, const Pojazdy& p)
{
	s << p.marka << " " << p.model << " " << p.rejestracja << " " << p.przebieg << " " << p.rocznik << " " << p.ac;
	return s;
}

std::istream& operator >>(std::istream& s, Pojazdy& p)
{
	s >> p.marka >> p.model >> p.rejestracja >> p.przebieg >> p.rocznik >> p.ac;
	return s;
}

bool operator<(const Pojazdy& l, const Pojazdy& r)
{
	if (l.marka < r.marka)
		return true;
	else
		return false;
}
bool operator>(const Pojazdy& l, const Pojazdy& r)
{
	if (l.marka > r.marka)
		return true;
	else
		return false;
}
bool operator==(const Pojazdy& l, const Pojazdy& r)
{
	if (l.marka == r.marka and l.model == r.model and l.rejestracja == r.rejestracja and l.przebieg == r.przebieg and l.rocznik == r.rocznik and l.ac == r.ac)
		return true;
	else
		return false;
}