/*
* File:   BoxList.cpp
*
* Purpose: provide implementation of member functios of two classes named Box and BoxList respectively.
*/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "BoxList.h"

using namespace std;

//---------------------------------------------------
//Box Members
//---------------------------------------------------
Box::Box(int _datum, Box* _next) :
	marshmallows(_datum), nextBox(_next)
{}


int Box::getMarshmallows() const
{
	return marshmallows;
}


Box* Box::getNextBox() const
{
	return nextBox;
}


//---------------------------------------------------
//BoxList Members
//---------------------------------------------------
BoxList::BoxList() :
	head(NULL)
{}

void BoxList::insertBox(int marshmallows)
{
	Box *currPtr = head;
	Box *prevPtr = NULL;
	Box *newBoxPtr;      //points to a new box

	while (currPtr != NULL && marshmallows > currPtr->marshmallows)
	{
		//prevPtr = currPtr;
		currPtr = currPtr->nextBox;
	}
	
	// request space from the heap to create a new object of Box class
	newBoxPtr = new Box(marshmallows, currPtr);
	// add the new node to the right position to maintain the sorted list
	prevPtr->nextBox = newBoxPtr;
}

// create a box list which contains INITIALBOXES boxes
void BoxList::makeBoxList()
{
	const int INITIALBOXES = 5;
	int marshmallowCount;
	Box *newBoxPtr;

	srand(time(0));

	for (int i = 0; i < INITIALBOXES; i++)
	{
		marshmallowCount = rand() % (MAXMASHMALLOWS + 1);
		insertBox(marshmallowCount);
	}
}

void BoxList::deleteBox(int marshmallows)
{
	Box *delPtr = head;
	Box *prevPtr = NULL;

	// If the list is empty, then do nothing;
	if (delPtr == NULL)
		return;

	//Treat the first box as a special case... head needs to be updated
	if (head->marshmallows == marshmallows)
	{
		head = head->nextBox;
	}
	else
	{
		prevPtr = delPtr;
		//Look for the box in the list to be deleted
		while (delPtr != NULL && delPtr->marshmallows != marshmallows)
		{
			delPtr = delPtr->nextBox;
		}

		prevPtr->nextBox = delPtr->nextBox;
	}

	//Delete the node
	delete delPtr;
}


void BoxList::printBoxList()
{
	Box *currPtr;
	currPtr = head;
	int count = 0;
	if (currPtr == NULL)
	{
		cout << "Empty! Collect more..." << endl;
		return;
	}
	while (currPtr != NULL)
	{
		count++;
		cout << "The Lucky Charm Box " << count << " contains " << currPtr->marshmallows << " mashmallows." << endl;
		currPtr = currPtr->nextBox;
	}
}

BoxList::~BoxList()
{
	Box *currPtr;
	Box *toDelPtr;
	currPtr = head;
	while (currPtr != NULL)
	{
		toDelPtr = currPtr;
		currPtr = currPtr->nextBox;
		delete toDelPtr;
	}
}
