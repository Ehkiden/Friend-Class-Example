/*
* File:   BoxList.h
*
*
* Purpose: Delaration of two classes named Box and BoxList
*/

#ifndef BOXLIST_H
#define	BOXLIST_H

#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXMASHMALLOWS = 500;

class Box
{
private:
	int marshmallows;
	Box* nextBox;

public:
	Box(int, Box*);
	int getMarshmallows() const;
	Box* getNextBox() const;

	friend class BoxList;  // gives BoxList access to the private data of Box class
};


class BoxList
{
private:
	Box* head;

public:
	BoxList();

	void insertBox(int);
	void makeBoxList();
	void deleteBox(int);
	void printBoxList();
	~BoxList();
};

#endif	/* BOXLIST_H */

