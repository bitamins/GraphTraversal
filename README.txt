Intro:
	The purpose of these programs is to show my knowledge of graph traversal using DFS and BFS,

	These programs were based off programming assignments from my cs311 (data structures) class
	taught by Dr. Rika Yoshii, the header files were also created by her.
Run:
	run bfsdfs.exe to see breadth first search and depth first search applied to the graph in table.txt.

Files:
	DFS_BFS.cpp - this file contains the depth first and breadth first search functions used on our graph.
	dgraph.cpp, dgraph.h - this class creates an array of verticies based on table.txt. Current max size of the array = 20
	llist.cpp, llist.h - this is a linked list class 
	slist.cpp, slist.h - this class adds searching functionality and overloaded '=' operater to the linked list
				. This is used for holding adjacent verticies from the graph
	stack.cpp, stack.h - this is a stack class used for the depth first traversal of the graph
	queue.cpp, queue.h - this is a queue class used for the breadth first traversal of the graph. Current max size of queue = 20
	table.txt - this is the table for the graph. It contains the vertex, outdegree (number of adjacent verticies), and adjacent verticies
			ex. A 2 B F, vertex A with 2 adjacent verticies B and F.
