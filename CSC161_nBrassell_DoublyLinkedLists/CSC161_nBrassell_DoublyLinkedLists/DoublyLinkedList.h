#pragma once

//Definition of the node
template <class T>
struct nodeType
{
	T info;
	nodeType<T>* next;
	nodeType<T>* back;
};

template <class T>
class DoublyLinkedList
{
private:
	//Makes copy of other list
	void copyList(const DoublyLinkedList<T>& otherList);

protected:
	int count;
	nodeType<T>* first; //Pointer to first node
	nodeType<T>* last;	//Pointer to last node

public:
	const DoublyLinkedList<T>& operator = (const DoublyLinkedList<T>&);
	void initializeList(); //Initialize list to an empty state
	bool isEmpty() const; //Determines if the list is empty
	void destroy(); //Delete all the nodes from the list
	void print() const; //Output the info contained in each node
	void reversePrint() const; //Output the info in reverse order
	int length() const; //Return the number of nodes in the list
	T front() const; //Return the fist node in the list
	T back() const; //Return the last node in the list
	bool search(const T& searchItem) const; //Determine if item in list
	void insert(const T& insertItem); //Insert item into list
	void deleteNode(const T& deleteItem); //Delete item from list

	//Default constructor
	DoublyLinkedList();

	//Copy constructor
	DoublyLinkedList(const DoublyLinkedList<T>& otherList);

	//Destructor
	~DoublyLinkedList();

};
