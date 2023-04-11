#include "LinkedElement.h"
template<class T>
LinkedElement<T>::LinkedElement()
{
	next = 0;
}

template<class T>
LinkedElement<T>::LinkedElement(T input)
{
	data = input;
	next = 0;
}

template<class T>
std::shared_ptr<LinkedElement<T>> LinkedElement<T>::getNext()
{
	return next;
}

template<class T>
T LinkedElement<T>::getData()
{
	return data;
}

template<class T>
void LinkedElement<T>::setData(T d)
{
	data = d;
}

template<class T>
void LinkedElement<T>::setNext(std::shared_ptr<LinkedElement> n)
{
	next = n;
}

