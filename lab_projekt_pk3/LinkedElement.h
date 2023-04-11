#pragma once
#include <iostream>
template <class T>
class LinkedElement
{
private:
	T data;
	std::shared_ptr<LinkedElement> next;
public:
	LinkedElement();
	LinkedElement(T input);
	std::shared_ptr<LinkedElement> getNext();
	T getData();
	void setData(T d);
	void setNext(std::shared_ptr<LinkedElement> n);
	

};

