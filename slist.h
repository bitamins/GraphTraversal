/*******************************************
author: Michael Bridges
compiler: g++
type: implementation file
*******************************************/
#include "llist.h"

class slist:public llist
{
	public:
		slist();//constructor
		slist(const slist& oglist); //copy constructor
		slist& operator=(const slist& otlist); //overloaded assignment operator for the nodes in the list
		int search(el_t Key);//searches for and returns an index of an element
		void replace(el_t Elem, int I);//replaces the value in a specified index
};
