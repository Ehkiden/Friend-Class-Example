//course: CS216-00x
//Project: Lab Assignment 5
//Date: 02/14/2017
//Purpose: This program demonstrates the collection of cereal boxes for Lucky the Leprechaun(Sir Charms).
//	   put collection of cereal boxes in non-decreasing order by the number of marshmallows in each box.
//	   Allow to add new boxes, or remove boxes from collection. 

/*
A little wierd but this is a good example of using a friend class, aka having multiple classes inside a header
*/

#include<iostream>
#include<string>
#include"BoxList.h"

using namespace std;

int readMarshmallowsInBox(string);

int main()
{

	char choice;
	int marshmallows_in_a_box;
	BoxList BL_for_Lucky;

	cout << "This program demonstrates the collection of boxes for the leprechaun, Lucky. " << endl;
	cout << "Initially, you will be asked to create the box list for Lucky." << endl;
	cout << "You will be later prompted to manipulate the box list." << endl << endl;

	BL_for_Lucky.makeBoxList();
	cout << "The Lucky Charms collection for Lucky the Leprechaun are in order: " << endl;
	BL_for_Lucky.printBoxList();

	do
	{
		cout << "*******************************************************" << endl;
		cout << "i: Insert a new cereal box" << endl;
		cout << "d: Delete (Delete a box with the given number of marshmallows)" << endl;
		cout << "p: Print  (Display the number of marshmallows in each box from the box list)" << endl;
		cout << "q: Quit   (Quit the program)" << endl;
		cout << "*******************************************************" << endl << endl;
		cout << endl << "Please enter your choice here:";
		cin >> choice;
		cin.ignore(256, '\n');

		switch (choice)
		{
		case 'i':
			marshmallows_in_a_box = readMarshmallowsInBox("to insert:");
			BL_for_Lucky.insertBox(marshmallows_in_a_box);
			break;

		case 'd':
			marshmallows_in_a_box = readMarshmallowsInBox("to delete:");
			BL_for_Lucky.deleteBox(marshmallows_in_a_box);
			break;

		case 'p':
			cout << "The Lucky Charms collection for Lucky the Leprechaun are in order: " << endl;
			BL_for_Lucky.printBoxList();
			break;

		case 'q':
			break;

		default:
			cout << "\n Invalid choice. Please try again.\n";
			break;
		}
	} while (choice != 'q');

	cout << "Thank you for using this program" << endl;
	return 0;
}

int readMarshmallowsInBox(string descr)
{
	int marshmallows;
	cout << endl << "Please enter the number of marshmallows in the box " << descr;
	cin >> marshmallows;
	cin.ignore(256, '\n');

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl << "Please enter the number of marshmallows in the box " << descr;
		cin >> marshmallows;
		cin.ignore(256, '\n');
	}

	return marshmallows;
}
