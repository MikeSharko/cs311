// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Mike Sharko
// File type:  hw6client.cpp  (tester file)
// ================================================

#include "dgraph.h"
using namespace std;
int main()
{  
 
	
	/* 0.Declare table object
  1.fillTable()
  2.displayGraph()
  while (the user does not want to stop)
    a.the user will specify which vertex     
    b.findOutDegree of the vertex and display the result
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception to display error mesg but do not exit*/

	/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/


	int run = 2; //variable that determines if the program keeps running
	bool error = false; //checks if Bad Vertex (error) was found

	char vertex; //vertex being searched for in seach function
	int degree; //degree of the vertex
	slist adjecencyList; //adjacency of the vertex

	dgraph Table; //0.Declare table object
	Table.fillTable(); //1.fillTable()
	Table.displayGraph(); //2.displayGraph()

	while (run > 1 && run <= 3) //while user does not want to stop
	{
	//a.the user will specify which vertex     
	cout << endl << "Enter vertex: ";
	cin >> vertex;

	//b.findOutDegree of the vertex and display the result
	//b.findAdjacency of the vertex and display the result (see Hint)
	try
	{
		if (run == 2) //find degree of vertex
			degree = Table.findOutDegree(vertex);
		else if (run == 3) //find adjacencies of vertex
			adjecencyList = Table.findAdjacency(vertex);
	}

	//c.catch exception to display error msg but do not exit
	catch (dgraph::BadVertex)
	{
		cerr << "ERROR: The vertex does not exist!" << endl;
		error = true;
	}

	//if no error, display result(s)
	if (error == false)
	{
		if (run == 2)
			cout << "The degree is: " << degree << endl;
		else if (run == 3)
		{
			cout << "The  adjacents are: ";
			adjecencyList.displayAll();
		}
		cout << endl;
	}

	//display menu (repeats if option entered is invalid)
	do {
		cout << "OPTIONS:" << endl;
		cout << "1. Quit" << endl;
		cout << "2. Search for the degree of another vertex" << endl;
		cout << "3. Search for the adjacents of another vertex" << endl;
		cout << "Choose an option: ";
		cin >> run;
		error = 0;
	} while (run < 1 || run > 3);
}

}// end of main

 

