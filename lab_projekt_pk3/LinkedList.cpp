#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
	head = 0;
	size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& klista)
{
	*this = klista;
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T>&& plista)
{
	*this = plista;
	plista.head = 0;
	plista.size = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	for (int i = 0; i < size; i++)
	{
		remove_last();
	}
}

template<class T>
void LinkedList<T>::add(T adata)
{
	std::shared_ptr<LinkedElement<T>> newElement(new LinkedElement<T>(adata));
	if (head == 0)
	{
		head = newElement;
		size++;
	}
	else
	{
		std::shared_ptr<LinkedElement<T>> temp = head;
		while (temp->getNext())
		{
			temp = temp->getNext();
		}
		temp->setNext(newElement);
		size++;
	}
}

template<class T>
void LinkedList<T>::insert(T idata, int index)
{
	if (index == 0)
	{
		std::shared_ptr<LinkedElement<T>> newElement(new LinkedElement<T>(idata));
		newElement->setNext(head);
		head = newElement;
		size++;
	}
	else if (index >= 1 and size >= index)
	{
		int i = 0;
		std::shared_ptr<LinkedElement<T>> temp = head;
		while (temp)
		{
			if (i + 1 == index)
				break;
			temp = temp->getNext();
			i++;
		}

		std::shared_ptr<LinkedElement<T>> newElement(new LinkedElement<T>(idata));
		newElement->setNext(temp->getNext());
		temp->setNext(newElement);
		size++;
	}
}

template<class T>
void LinkedList<T>::print()
{
	std::shared_ptr<LinkedElement<T>> temp = head;
	while (temp)
	{
		std::cout << temp->getData() << "\n";
		temp = temp->getNext();
	}
}

template<class T>
void LinkedList<T>::remove(int index)
{
	if (size > index)
	{
		if (index == 0)
		{
			std::shared_ptr<LinkedElement<T>> temp = head;
			head = temp->getNext();
			size--;
		}
		else if (index >= 1)
		{
			int i = 0;
			std::shared_ptr<LinkedElement<T>> temp = head;
			while (temp)
			{
				if (i + 1 == index)
					break;
				temp = temp->getNext();
				i++;
			}
			if (temp->getNext()->getNext() == 0)
			{
				temp->setNext(0);
				size--;
			}
			else
			{
				std::shared_ptr<LinkedElement<T>> removed = temp->getNext();
				temp->setNext(temp->getNext()->getNext());
				size--;
			}
		}
	}
}

template <class T>
void LinkedList<T>::remove_T(T rdata)
{
	if (size > 0)
	{
		int i = 0;
		std::shared_ptr<LinkedElement<T>> temp = head;
		while (temp)
		{
			if (temp->getData() == rdata)
			{
				remove(i);
				break;
			}
			i++;
			temp = temp->getNext();
		}
	}
}

template <class T>
void LinkedList<T>::remove_last()
{
	remove(size - 1);
}

template <class T>
void LinkedList<T>::remove_first()
{
	remove(0);
}

template <class T>
void LinkedList<T>::add_front(T adata)
{
	insert(adata, 0);
}

template <class T>
bool LinkedList<T>::check(T sdata)
{
	if (head == 0)
	{
		return false;
	}
	else
	{
		std::shared_ptr<LinkedElement<T>> temp = head;
		while (temp)
		{
			if (temp->getData() == sdata)
				return true;
			temp = temp->getNext();
		}
		return false;
	}
}

template <class T>
T LinkedList<T>::search_min()
{
	std::shared_ptr<LinkedElement<T>> min = head;
	std::shared_ptr<LinkedElement<T>> temp = head;
	while (temp)
	{
		if (min->getData() > temp->getData())
		{
			min = temp;
		}
		temp = temp->getNext();
	}
	return min->getData();

}

template <class T>
T LinkedList<T>::search_max()
{
	std::shared_ptr<LinkedElement<T>> max = head;
	std::shared_ptr<LinkedElement<T>> temp = head;
	while (temp)
	{
		if (max->getData() < temp->getData())
		{
			max = temp;
		}
		temp = temp->getNext();
	}
	return max->getData();

}

template<class T>
void LinkedList<T>::sort(int choice)
{
	LinkedList<T> temp;
	int s = size;
	for (int i = 0; i < s; i++)
	{
		if (choice == 1)
		{
			temp.add(search_min());
			remove_T(search_min());
		}
		else if (choice == 2)
		{
			temp.add_front(search_min());
			remove_T(search_min());
		}
		else
		{
			temp = *this;
			break;
		}
	}
	*this = temp;
}

template<class T>
bool LinkedList<T>::zapis(std::string nazwa)
{
	std::fstream file;
	file.open(nazwa, std::ios::out);
	if (file.good() == true)
	{
		std::shared_ptr<LinkedElement<T>> temp = head;
		while (temp)
		{
			file << temp->getData() << "\n";
			temp = temp->getNext();
		}
		file.close();
		return true;
	}
	else
		return false;
}



template<class T>
bool LinkedList<T>::odczyt(std::string nazwa)
{
	T data;
	std::fstream file;
	file.open(nazwa, std::ios::in);
	if (file.good() == true)
	{
		head = 0;
		size = 0;

		std::string str;
		while (file)
		{
			file >> data;
			add(data);
		}
		remove_last();
		file.close();
		return true;
	}
	else
		return false;
}




template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& lista)
{
	for (int i = 0; i < size; i++)
		{
			remove_last();
		}
	std::shared_ptr<LinkedElement<T>> temp = lista.head;
	while (temp)
	{
		add(temp->getData());
		temp = temp->getNext();
	}
	return *this;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& lista)
{
	head = 0;
	size = 0;
	std::shared_ptr<LinkedElement<T>> temp = lista.head;
	while (temp)
	{
		add(temp->getData());
		temp = temp->getNext();
	}
	lista.head = 0;
	lista.size = 0;
	return *this;
}