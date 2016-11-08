/*************************************************************************
Created by: Michael Bridges
Date: 4/26/2016
Type: Header File
Compiler: G++
*************************************************************************/
#ifndef dgraph_H
#define dgraph_H
#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;   // for the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph
{

private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used

public:

  class BadVertex {};  // thrown when the vertex is not in the graph
  class Overflow {};//thrown when there are too many vertex names in the file
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // do we have to delete all nodes of slists in table??
	       // Question: If we do not do this, will the llist destructor
               // be called automatically??? Try it.

 // read from the input file table.txt and fill GTable
  void fillTable();  

 // displays in an easy to read format 
  void displayGraph(); 

// returns the out degree of a given vertex - may throw BadVertex
  int findOutDegree(char);  
	
// returns the adjacency list of a given vertex - may throw BadVertexx
  slist findAdjacency(char);  
  
// This is to indicate the order in which vertices were visited.
  void visitNumber(int, char);
	
//which returns true if a given vertex was already visited  (0 means not visited)
  bool isMarked(char);

//places the first element of the graph into a variable container
  void getFirstVertex(char&);
		

};

#endif

