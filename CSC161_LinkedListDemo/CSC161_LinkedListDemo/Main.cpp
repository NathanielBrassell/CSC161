#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	//Define a NumbetrList data structure
	NumberList list;

	//Append some values to the list
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(14.5);
	list.appendNode(24.3);

	//Display list
	list.displayList();
	cout << endl;

	//Insert new value
	list.insertNode(12.3);

	//Display list
	list.displayList();
	cout << endl;

	//Delete a value from list
	list.deleteNode(14.5);

	//Display list
	list.displayList();
	cout << endl;

	system("pause");
	return 0;
}