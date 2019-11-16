// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: James Bertel
// File type:  client cpp (tester)
// ================================================
//**

#include "dgraph.h"
using namespace std;

int main()
{ 
  int runProgram = 2; //variable that determines if the program keeps running
  bool error = false; //checks if Bad Vertex (error) was found

  char vertex; //vertex being searched for in seach function
  int degree; //degree of the vertex
  slist adjList; //adjacency of the vertex

  dgraph Table; //0.Declare table object
  Table.fillTable(); //1.fillTable()
  Table.displayGraph(); //2.displayGraph()

  while(runProgram > 1 && runProgram <= 3) //while user does not want to stop
    {
      //a.the user will specify which vertex     
      cout << endl << "Enter vertex: ";
      cin >> vertex;
     
      //b.findOutDegree of the vertex and display the result
      //b.findAdjacency of the vertex and display the result (see Hint)
      try
	{
	  if(runProgram == 2) //find degree of vertex
	    degree = Table.findOutDegree(vertex);
	  else if(runProgram == 3) //find adjacencies of vertex
	    adjList = Table.findAdjacency(vertex);
	}

      //c.catch exception to display error mesg but do not exit
      catch(dgraph::BadVertex)
	{
	  cerr << "ERROR: The vertex does not exist!" << endl;
	  error = true;
	}

      //if no error, display result(s)
      if(error == false) 
	{
	  if(runProgram == 2)
	    cout << "The degree is: " << degree << endl;
	  else if(runProgram == 3)
	    {
	      cout << "The  adjacents are: "; 
	      adjList.displayAll();
	    }
	  cout << endl;
	}

      //display menu (repeats if option entered is invalid)
      do{
	cout << "OPTIONS:" << endl;
	cout << "1. Quit" << endl;
	cout << "2. Search for the degree of another vertex" << endl;
	cout << "3. Search for the adjacents of another vertex" << endl;
	cout << "Choose an option: ";	       
	cin >> runProgram;
	error = 0;
      }while(runProgram < 1 || runProgram > 3);
    }
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
