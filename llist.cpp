// ====================================================
//HW#: HW3P1 llist
//Your name: Michael Bridges
//Complier:  G++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

llist::llist()
{
	Front=Rear=NULL;//initialize front and rear to null
	Count=0;//initialize count to 0
}
  
llist::~llist()
{
	el_t num;
	while(Count!=0) //empties the list by deleting from the front
	{
		deleteFront(num);
	}
}
  
bool llist::isEmpty()
{
	if(Count==0)	//checks to see if there are any elements in the list
	{
		return true;
	}
	else
	{
		return false;
	}
}

void llist::displayAll()
{
	Node* p=Front;
	if(isEmpty()) //checks if empty
	{
		cout<<"[empty]"<<endl;
	}
	else //if not empty walk through the list and print the elements to the screen
	{
		cout<<"List: ";
		while(p!=NULL)
		{
			cout<<p->Elem<<" ";
			p=p->Next;
		}
		cout<<endl;
	}
}

void llist::addRear(el_t NewNum)
{
	if(Count==0) // if there are no elements create one and set it to Front and Rear
	{
		Node* p=new Node;
		p->Elem=NewNum;
		p->Next=NULL;
		Front=p;
		Rear=Front;
		Count++;
	}
	else//create a new node from the rear node
	{
		Rear->Next=new Node;
		Rear=Rear->Next;
		Rear->Elem=NewNum;
		Rear->Next=NULL;
		Count++;
	}
} 

void llist::addFront(el_t NewNum)
{
	if(Count==0)// if there are no elements create one and set it to Front and Rear
	{
		Node* p=new Node;
		p->Elem=NewNum;
		p->Next=NULL;
		Front=p;
		Rear=Front;
		Count++;
	}
	else//create a new node and point it to Front, then set the new node to front
	{
		Node* p=new Node;
		p->Elem=NewNum;
		p->Next=Front;
		Front=p;
		Count++;
	}
}

void llist::deleteFront(el_t& OldNum)
{
	if(Count==0)//if there are no elements return throw underflow
	{throw Underflow();}
	else if(Count==1) //if there is only 1 element delete it and set Front and rear to NULL
	{
		OldNum=Front->Elem;
		delete Front;
		Rear=Front=NULL;
		Count--;
	}
	else //set the second element as the new front element, then delete the origional front
	{
		OldNum=Front->Elem;
		Node* Second=Front->Next;
		Node* q=Front;
		Front=Second;
		delete q;
		Count--;
	}
}

void llist::deleteRear(el_t& OldNum)
{
	if(Count==0)//if there are no elements return throw underflow
	{throw Underflow();}
	else if(Count==1)//if there is only 1 element delete it and set Front and rear to NULL
	{
		OldNum=Rear->Elem;
		delete Rear;
		Rear=NULL;
		Front=Rear;
		Count--;
	}
	else//find the element before rear and set it to Rear, then delete the origional rear
	{
		OldNum=Rear->Elem;
		Node* Previous=Front;
		while(Previous->Next!=Rear)
		{Previous=Previous->Next;}
		Node* q=Rear;
		Rear=Previous;
		Rear->Next=NULL;
		delete q;
		Count--;
	}
}

void llist::deleteIth(int I, el_t& OldNum)
{
	if(I>Count||I<1)
	{
		throw OutOfRange();
	}
	else if(I==1)
	{
		deleteFront(OldNum);
	}
	else if(I==Count)
	{
		deleteRear(OldNum);
	}
	else
	{
		Node* p=Front;
		Node* q=p;
		for(int j=0; j<(I-1); j++) //find node I
		{
			q=p; //set q to I-1
			p=p->Next;
		}
		Node* r=p->Next; //set r to I+1
		q->Next=r;//set q to point to r
		OldNum=p->Elem;
		delete p;	//delete the node
		Count--;
	}
}

void llist::addbeforeIth(int I, el_t newNum)
{
	if(I>(Count+1)||I<1)
	{
		throw OutOfRange();
	}
	else if(I==1)
	{
		addFront(newNum);
	}
	else if(I==(Count+1))
	{
		addRear(newNum);
	}
	else
	{
		Node* p=Front;
		for(int j=1; j<(I-1); j++) //find node I
		{
			p=p->Next;
		}
		Node* q=p->Next; //set q to I+1
		Node* r=new Node; 
		r->Elem=newNum;
		r->Next=q;//set new node r to point to q
		p->Next=r;//set p to point to r
		Count++;
	}
}