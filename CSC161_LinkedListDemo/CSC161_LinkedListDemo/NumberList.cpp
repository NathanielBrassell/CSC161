#include "NumberList.h"

//AppendNode appends a node containing the value passed into num, to the end of list
void NumberList::appendNode(double num)
{
	ListNode* newNode; //To point to a new node
	ListNode* nodePtr; //To move through the list

	//Allocates a new node and store num there
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	//If there are no nodes in the list make newNode the first node
	if (!head)
	{
		head = newNode;
	}
	else
	{
		//Initialize nodePtr to head of list
		nodePtr = head;

		//Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		//Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

//DisplayList shows the value stored in each node of the linked list pointed to by the head
void NumberList::displayList() const
{
	ListNode* nodePtr; //To move through the list

	//Position nodePtr at the head of the list
	nodePtr = head;

	//While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		//Display the value in this node
		cout << nodePtr->value << endl;

		//Move to the next node
		nodePtr = nodePtr->next;
	}

}

//InsertNode inserts a node with num copied to its value memeber
void NumberList::insertNode(double num)
{
	ListNode* newNode;					//To point to a new node
	ListNode* nodePtr;					//To move through the list
	ListNode* previousNode = nullptr;   //The previous node

	//Allocates a new node and store num there
	newNode = new ListNode;
	newNode->value = num;

	//If there are no nodes in the list make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		//Position nodePtr at the head of the list
		nodePtr = head;

		//Intitialize previous node to nullptr
		previousNode = nullptr;

		//Skip all nodes whose value is less than num
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If the new node is to be the first in the list, insert it before all other nodes
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//DeleteNode searches for a node with num as its value. The node, if found, is deleted from the list and from memory
void NumberList::deleteNode(double num)
{
	ListNode* nodePtr;		  //To move through the list
	ListNode* previousNode = nullptr;   //The previous node

	//If there are no nodes in the list, do nothing
	if (!head)
		return;

	//Determine if the first node is the one to delete
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		//Initialize nodePtr to the head of list
		nodePtr = head;

		//Skip all nodes whose value memeber is not equal to num
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If nodePtr is not at the end of list, link previous node to the node after nodePtr, then delete nodePtr
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//Destructor function to delete every node in the list
NumberList::~NumberList()
{
	ListNode* nodePtr;	   //To move through the list
	ListNode* nextNode;   //To point to the next node

	//Postition nodePtr at the head
	nodePtr = head;

	//While nodePtr is not at the end of the list
	while (nodePtr != nullptr)
	{
		//Save a pointer to the next node
		nextNode = nodePtr->next;

		//Delete the current node
		delete nodePtr;

		//Position nodePtr to next node
		nodePtr = nextNode;
	}
}