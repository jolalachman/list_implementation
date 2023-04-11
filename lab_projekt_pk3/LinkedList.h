#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include "LinkedElement.cpp"

template <class T>
class LinkedList
{
private:
	std::shared_ptr<LinkedElement<T>> head;
	int size;

public:
	//konstruktor bezargumentowy
	LinkedList();
	//konstruktor kopiuj�cy
	LinkedList(const LinkedList& klista);
	//konstruktor przenosz�cy
	LinkedList(LinkedList&& plista);
	//destruktor
	~LinkedList();
	//dodanie elementu na koniec
	void add(T adata);
	//dodanie elementu w wybrane miejsce
	void insert(T idata, int index);
	//wy�wietlenie listy
	void print();
	//usuniecie wybranego elementu na podstawie indeksu
	void remove(int index);	
	//usuniecie wybranego elementu na podstawie zawarto�ci
	void remove_T(T rdata);
	//pop back
	void remove_last();
	//pop front
	void remove_first();
	//push front
	void add_front(T adata);
	//wyszukanie i sprawdzenie czy element znajduje si� na li�cie
	bool check(T sdata);
	//wyszukanie najmniejszego/najwi�kszego elementu
	T search_min();
	T search_max();
	//sortowanie rosn�co/malej�co
	void sort(int choice);
	//zapis do pliku
	bool zapis(std::string nazwa);
	//odczyt z pliku
	bool odczyt(std::string nazwa);
	//operator przypisania
	LinkedList& operator=(const LinkedList& lista);
	//operator przeniesienia
	LinkedList& operator=(LinkedList&& lista);
};

