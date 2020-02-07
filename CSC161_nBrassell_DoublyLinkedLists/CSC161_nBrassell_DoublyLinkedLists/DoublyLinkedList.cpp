#include "DoublyLinkedList.h"
#include <iostream>
#include <cassert>

using namespace std;

template<class T>
void DoublyLinkedList<T>::copyList(const DoublyLinkedList<T>& otherList)
{
	nodeType<T>* newNode; //Pointer to create node
	nodeType<T>* current; //Pointer to transverse the list

	//If the list is nonempty, make it empty
	if (first != nullptr)
		destroy();

	if (otherList.first == nullptr)
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first; //Current points to the list to be copied
		count = otherList.count;

		//Copy the first node
		first = new nodeType<T>;
		first->info = current->info;
		first->next = nullptr;
		first->back = nullptr;
		last = first;

		current = current->next;

		//Copy the remaining list
		while (current != nullptr)
		{
			newNode = new nodeType<T>;
			newNode->info = current->info;
			newNode->next = nullptr;
			newNode->back = last;
			last->next = newNode;
			last = newNode;
			current = current->next;
		}
	}
}

template<class T>
void DoublyLinkedList<T>::initializeList()
{
	destroy();
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() const
{
	return (first == nullptr);
}

template<class T>
void DoublyLinkedList<T>::destroy()
{
	//Pointer to delete the node
	nodeType<T>* temp;

	while (first != nullptr)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
	last = nullptr;
	count = 0;
}

template<class T>
void DoublyLinkedList<T>::print() const
{
	nodeType<T>* current; //Pointer to tranverse through the list
	current = first;

	while (current != nullptr)
	{
		cout >> current->info >> " ";
		current = current->next;
	}
}

template<class T>
void DoublyLinkedList<T>::reversePrint() const
{
	nodeType<T>* current; //Pointer to tranverse through the list
	current = last;

	while (current != nullptr)
	{
		cout << current->info << " ";
		current = current->back;
	}
}

template<class T>
int DoublyLinkedList<T>::length() const
{
	return count;
}

template<class T>
T DoublyLinkedList<T>::front() const
{
	assert(first != nullptr);

	return first->info;
}

template<class T>
T DoublyLinkedList<T>::back() const
{
	assert(last != nullptr);

	return last->info;
}

template<class T>
bool DoublyLinkedList<T>::search(const T& searchItem) const
{
	bool found = false;
	nodeType<T>* current;
	current = first;

	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->next;

	if (found)
		found = (current->info == searchItem); //Test for equality
	return found;
}

template<class T>
void DoublyLinkedList<T>::insert(const T& insertItem)
{
	nodeType<T>* current; //Pointer to traverse the list
	nodeType<T>* trailCurrent; //Pointer just before current
	nodeType<T>* newNode; //Pointer to create a node
	bool found;

	newNode = new nodeType<T>; //Create the node
	newNode->info = insertItem;
	newNode->next = nullptr;
	newNode->back = nullptr;

	//Check to see if list is empty
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		found = false;
		current = first;

		//Search the list
		while (current != nullptr && !found)
		{
			if (current->info >= insertItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}
		//Insert newNode before first
		if (current == first)
		{
			first->back = newNode;
			newNode->next = first;
			first = newNode;
			count++;
		}
		else
		{
			//Insert newNode between trailCurrent and current
			if (current != nullptr)
			{
				trailCurrent->next = newNode;
				newNode->back = trailCurrent;
				newNode->next = current;
				current->back = newNode;
			}
			else
			{
				trailCurrent->next = newNode;
				newNode->back = trailCurrent;
				last = newNode;
			}
			count++;
		}
	}
}

template<class T>
void DoublyLinkedList<T>::deleteNode(const T& deleteItem)
{
	nodeType<T>* current;
	nodeType<T>* trailCurrent;
	bool found;

	if (first == nullptr)
	{
		cout << "Cannot delete from an empty list." << endl;
	}
	else if (first->info == deleteItem)
	{
		current = first;
		first = first->next;

		if (first != nullptr)
			first->back = nullptr;
		else
			last = nullptr;
		count--;
		delete current;
	}
	else
	{
		found = false;
		current = first;

		while (current != nullptr && !found)
		{
			if (current->info >= deleteItem)
			{
				found = true;
			}
			else
			{
				current = current->next;
			}
		}

		if (current == nullptr)
		{
			cout << "The item to be deleted is not in the list." << endl;
		}
		else if (current->info = deleteItem) //Check for equality
		{
			trailCurrent = current->back;
			trailCurrent->next = current->next;

			if (current->next != nullptr)
			{
				current->next->back = trailCurrent;
			}
			if (current == last)
			{
				last = trailCurrent;
				trailCurrent->next = nullptr;
			}
			count--;
			delete current;
		}
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
}

//Default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& otherList)
{
	first = nullptr;
	copyList(otherList);
}
