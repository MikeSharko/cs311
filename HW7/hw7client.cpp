//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Mike Sharko
// File type: client hw7client.cpp 
//==========================================
#include "dgraph.h"
#include "stack.h"
#include "slist.h"
// Be sure to include dgraph, slist and stack

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // use the algorithm (read carefully) in the HW7
  // assignment sheet
  //------------**

  //Display the graph before DFS begins.
  dgraph TheGraph;
  TheGraph.fillTable();
  TheGraph.displayGraph();
  slist adjacencyList;
  
  //Push A onto the stack to start.
  stack TheStack;
  char TheVertex = 'A';
  int TheVertNum = 1; //Start A as 1
  TheStack.push(TheVertex);

  //While the stack is not empty do:

      while(!TheStack.isEmpty())
	{
	  //Remove a vertex v from the stack.
	  TheStack.pop(TheVertex);
	  
	  //Display the vertex name.  E.G. “Removed B from stack”
	  cout << "Removed " << TheVertex << " from stack" << endl;

	  //If v is not marked yet (visit number is 0) then...	  
	  if(TheGraph.isMarked(TheVertex) == 0)
	    {
	      //1) mark it (visit it **) and inform the user E.G. “Visit B as 2”
	      TheGraph.visit(TheVertNum, TheVertex);
	      cout << "Visit " << TheVertex << " as " << TheVertNum+1 << endl;

	      //2) get its adjacency list
	      adjacencyList = TheGraph.findAdjacency(TheVertex);


	      //if no adjacent ones...
	      if(adjacencyList.isEmpty())
		{
		  //...inform the user E.G. “Deadend reached – backup”
		  cout << "Deadend reached – backup" << endl;
		}
	      else
		{
		  //else, put adjacent ones on the stack (delete from the rear and push)
		  cout << "...pushing "; adjacencyList.displayAll();
		  while(!adjacencyList.isEmpty())
		    {
		      adjacencyList.deleteRear(TheVertex);
		      TheStack.push(TheVertex);
 		    }		  
		} 
	      TheVertNum++; //move up the vertex number to traverse
	    } //end (original) if
	  
	  else
	    {
	      //else, inform the user E.G. “B had been visited already - backup.”
	      cout << TheVertex << " has been visited already - backup" << endl;
	    }//end last else

	  cout << "The Stack is now: " << endl;
	  TheStack.displayAll();
	}
      //display graph
      cout << endl << "The Final Graph is: " << endl;
      TheGraph.displayGraph();
}
