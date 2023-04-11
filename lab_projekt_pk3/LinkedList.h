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
	//konstruktor kopiuj¹cy
	LinkedList(const LinkedList& klista);
	//konstruktor przenosz¹cy
	LinkedList(LinkedList&& plista);
	//destruktor
	~LinkedList();
	//dodanie elementu na koniec
	void add(T adata);
	//dodanie elementu w wybrane miejsce
	void insert(T idata, int index);
	//wyœwietlenie listy
	void print();
	//usuniecie wybranego elementu na podstawie indeksu
	void remove(int index);	
	//usuniecie wybranego elementu na podstawie zawartoœci
	void remove_T(T rdata);
	//pop back
	void remove_last();
	//pop front
	void remove_first();
	//push front
	void add_front(T adata);
	//wyszukanie i sprawdzenie czy element znajduje siê na liœcie
	bool check(T sdata);
	//wyszukanie najmniejszego/najwiêkszego elementu
	T search_min();
	T search_max();
	//sortowanie rosn¹co/malej¹co
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

