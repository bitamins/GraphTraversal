/*************************************************************************
Created by: Michael Bridges
Date: 4/26/2016
Type: Implementation file
Compiler: G++
*************************************************************************/
#include "dgraph.h"
#include <fstream>

dgraph::dgraph()
{
	for(int i=0;i<SIZE;i++)//sets SIZE verticies to default values
	{
		Gtable[i].vertexName=' ';
		Gtable[i].visit=0;
	}
	countUsed=0;//initializes the count of verticies used to 0
}

dgraph::~dgraph()
{}

void dgraph::displayGraph()
{

	cout<<"=====================================================\n";
	cout<<"Name\t"<<"Out Degree\t"<<"Visit Number\t"<<"Adjacent Vertices\n";
	cout<<"=====================================================\n";
	for(int i=0;i<countUsed;i++)//displays all of the the used verticies to the user
	{
		cout<<Gtable[i].vertexName<<"\t"<<Gtable[i].outDegree<<"\t\t"<<Gtable[i].visit<<"\t\t";
		Gtable[i].adjacentOnes.displayAll();
		cout<<endl;
	}//end of for
	cout<<"=====================================================\n";
}//end of displayGraph

void dgraph::fillTable()
{
	char adjVertex;//this holds the vertex name from the file
	string fileName="table.txt";//default filename table.txt
	ifstream fin;
	fin.open(fileName.c_str());
	
	for(int i=0;fin>>Gtable[i].vertexName;i++)//continue while there are still verticies to be read in
	{
		fin>>Gtable[i].outDegree;//read in the out degree of this vertex
		for(int j=0;j<Gtable[i].outDegree;j++)//read in the verticies based on the out degree
		{
			fin>>adjVertex;//holds the adjacent vertex name
			Gtable[i].adjacentOnes.addRear(adjVertex);//pushes the vertex name onto the slist of this vertex
		}//end of for
		countUsed++;//increment the used spaces in the table
		if(i==(SIZE-1))//if there is no more room in the table, break out
		{
			//throw Overflow();
			break;
		}//end of if
	}//end of while
	fin.close();
}//end of fillTable

int dgraph::findOutDegree(char vertex)
{
	for(int i=0;i<countUsed;i++)
	{
		if(Gtable[i].vertexName==vertex)
		{
			return Gtable[i].outDegree;
		}//end of if
	}//end of for
	throw BadVertex();
}//end of findOutDegree

slist dgraph::findAdjacency(char vertex)
{
	for(int i=0;i<countUsed;i++)
	{
		if(Gtable[i].vertexName==vertex)
		{
			return Gtable[i].adjacentOnes;
		}//end of if
	}//end of for 
	throw BadVertex();
}//end of findAdjacency


void dgraph::visitNumber(int visitNum, char vertex)
{
	Gtable[(vertex-65)].visit=visitNum;
}//end of vist

bool dgraph::isMarked(char vertex)
{
	if(Gtable[(vertex-65)].visit!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dgraph::getFirstVertex(char& vertex)
{
	vertex = Gtable[0].vertexName;
}