//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Mike Sharko
// File Type: .cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
	for (int i = 0; i < SIZE; i++)
	{
		Gtable[i].vertexName = ' ';
		Gtable[i].visit = 0;
	}
	countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  char c;
 
  cout << "Enter a file name: ";
  cin >> fname;

 
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  // the rest is in HW6-help ---- thank you
 
  
  while (fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
  {
	  fin >> Gtable[countUsed].outDegree;
	  for (int i = 1; i <= Gtable[countUsed].outDegree; i++) {
		  fin >> c;
		  (Gtable[countUsed].adjacentOnes).addRear(c); // this is a slist function from HW3
	  }   
	  countUsed++;
  }
  fin.close();
 }


void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows
	 
	for (int i = 0; i < countUsed; i++)
	{
		cout << Gtable[i].vertexName << " ";
		cout << Gtable[i].outDegree << " ";
		(Gtable[i].adjacentOnes).displayAll();
	}
	 
}

int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
	int tmp = int(V) - 65; // Converting ASCII
	if (tmp >= 0 && tmp < countUsed)
		return Gtable[tmp].outDegree;
	throw BadVertex(); // else throw exeption
}

slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop

	int tmp = int(V) - 65; //change V to integer V is 86
	if (tmp >= 0 && tmp < countUsed)
		return Gtable[tmp].adjacentOnes;
	throw BadVertex(); // else throw exeption
}
