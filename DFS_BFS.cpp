/*************************************************************************
Created by: Michael Bridges
Date: 5/5/2016
Compiler: G++
*************************************************************************/
//depth first search and breadth first search implementation
#include "dgraph.h"
#include "stack.h"
#include "queue.h"

void DFS() 
{
	int counter=1;//increments every time a new node is visited
	char temp=' ';//this is the starting name
	
	stack dfsStack;//initialize a stack
	slist dfsList;//initialize a list
	
	cout<<"===================="<<endl;
	cout<<"Depth First Search"<<endl;
	cout<<"===================="<<endl;

	dgraph G;//initialize a graph
	G.fillTable();//fill the graph
	G.displayGraph();//display the graph
	G.getFirstVertex(temp);
	
	cout<<"Vertex: "<<temp<<endl; //output the first nodes name
	G.visitNumber(counter, temp);//update the nodes visit number
	counter++;//update the visit number counter
	cout<<"Visited: "<<temp<<endl;//inform user of visited node
	dfsList=G.findAdjacency(temp);//gets adjacent nodes

	while(!dfsList.isEmpty())//continue pushing nodes onto the stack untill there are none
	{
		dfsList.deleteRear(temp);
		dfsStack.push(temp);
	}
	cout<<"=========="<<endl;
	cout<<"Current Stack"<<endl;
	cout<<"=========="<<endl;
	dfsStack.displayAll(); //display the current stack
	cout<<"=========="<<endl;

	while(!dfsStack.isEmpty())//continue while the stack is not empty
	{
		dfsStack.pop(temp);
		cout<<"Vertex: "<<temp<<endl;
		if(!G.isMarked(temp))//if the node has not been visited yet
		{
			G.visitNumber(counter,temp);//visit the node
			counter++;//increment the nodes visit number
			cout<<"Visited: "<<temp<<endl;
			dfsList=G.findAdjacency(temp);//gets adjacent nodes
			while(!dfsList.isEmpty())//push all adjacent nodes of temp onto the stack
			{
				dfsList.deleteRear(temp);
				dfsStack.push(temp);
			}
			cout<<"=========="<<endl;
			cout<<"Current Stack"<<endl;
			cout<<"=========="<<endl;
			dfsStack.displayAll(); //display the current stack
			cout<<"=========="<<endl;
		}
	}
	G.displayGraph();//show the graph with the visit order
}

void BFS()
{
	int counter = 1; //increments after visiting a vertex
	char temp = ' ';

	queue bfsQueue; //initialize the stack
	slist bfsList; //initialize the list

	cout<<"===================="<<endl;
	cout<<"Breadth First Search"<<endl;
	cout<<"===================="<<endl;

	dgraph G; //initialize the graph
	G.fillTable();
	G.displayGraph();
	G.getFirstVertex(temp);

	cout<<"Vertex: "<<temp<<endl; //output the first nodes name
	G.visitNumber(counter, temp);//update the nodes visit number
	counter++;//update the visit number counter
	cout<<"Visited: "<<temp<<endl;//inform user of visited node
	bfsList=G.findAdjacency(temp);//gets adjacent nodes

	while(!bfsList.isEmpty())
	{
		bfsList.deleteRear(temp);
		bfsQueue.add(temp);
	}

	cout<<"=========="<<endl;
	cout<<"Current Queue"<<endl;
	cout<<"=========="<<endl;
	bfsQueue.displayAll(); //display the current stack
	cout<<"=========="<<endl;

	while(!bfsQueue.isEmpty())
	{
		bfsQueue.remove(temp); //places the first element of the queue into temp
		cout<<"Vertex: "<<temp<<endl;
		if(!G.isMarked(temp))//if the node has not been visited yet
		{
			G.visitNumber(counter,temp);//visit the node
			counter++;//increment the nodes visit number
			cout<<"Visited: "<<temp<<endl;
			bfsList=G.findAdjacency(temp);//gets adjacent nodes
			while(!bfsList.isEmpty())//push all adjacent nodes of temp onto the stack
			{
				bfsList.deleteRear(temp);
				bfsQueue.add(temp);
			}
			cout<<"=========="<<endl;
			cout<<"Current Queue"<<endl;
			cout<<"=========="<<endl;
			bfsQueue.displayAll(); //display the current stack
			cout<<"=========="<<endl;
		}

	}
	G.displayGraph();
}

void exit()
{
	cout << "Enter any key to exit";
	cin.ignore();
}

int main()
{
	DFS(); //perform a depth first search
	BFS(); //perform a breadth first search
	exit();
}

