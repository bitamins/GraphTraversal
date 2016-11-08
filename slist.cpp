/*******************************************
author: Michael Bridges
compiler: g++
type: implementation file
*******************************************/

using namespace std;

#include <iostream>
#include "slist.h"

slist::slist()
{}
slist::slist(const slist& oglist) //creates a new list by copying oglist (original list)
{
	//initializing this->'s data members
	//allocates new cells and copies each node from oglist to the new ones created in the new list
	Front=Rear=NULL;
	Count=0;
	Node* p;
	p=oglist.Front;
	while(p!=NULL)
	{
		this->addRear(p->Elem);
		p=p->Next;
	}
    //  Nothing to return.	
}
slist& slist::operator=(const slist& otlist)//assigns one list to equal another list
{
	// First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&otlist != this)  // if not the same
    {
        // this-> object has to be emptied first.
		el_t oldNum;
        while (!this->isEmpty())
		{
			this->deleteRear(oldNum);  
        }
		// this-> object has to be built up by allocating new cells (**)
        Node* P=NULL;  // local pointer for OtherOne
        P = otlist.Front;
        while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;               // Go to the next node in OtherOne   
        } 
	}// end of if              
    return *this;    // return the result unconditionally.
}
int slist::search(el_t Key)
{
	Node* p=Front;
	int i=0; //index of the element
	while(p!=NULL) //traverse the list
	{
		if(p->Elem==Key) //if the element is found, return the index
		{
			return (i+1);
		}
		p=p->Next;
		i++;
	}
	return 0;
}
void slist::replace(el_t Elem, int I)
{
	Node* p=Front;
	if(I>Count) //if the index is out of range throw error
	{
		throw OutOfRange();
	}
	else
	{
		for(int j=0; j<(I-1); j++) //traverse the list until the desired node is reached
		{
			p=p->Next;
		}
		p->Elem=Elem; //change the desired Nodes Elem value
	}
}