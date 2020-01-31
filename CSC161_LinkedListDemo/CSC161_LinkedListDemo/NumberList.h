#pragma once
#include <iostream>

using namespace std;

class NumberList
{
private:
	//Declare a structure for the list
	struct ListNode
	{
		double value;	//The value in this node
		struct ListNode* next;	//To point to the next node
	};

	ListNode* head;		//List head pointer

public:
	//Constructor
	NumberList(){ head = nullptr; }

	//Destructor
	~NumberList();

	//Linked list operations
	void appendNode(double);
	void displayList() const;
	void insertNode(double);
	void deleteNode(double);
};

