// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Mike Sharko
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet

}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
void pqueue::insertjob(int j)
{
	  // to myself maybe better to use try catch here
	if (Q[count] < Q[MAX]) { 
		cout << "Adding: " << j << endl;
		// ** add the job j at the rear (and update count)
		Q[count] = j;		//---------------- added SHARK
		count++;			//---------------- added SHARK
		// **   if possible else display error message. 
		trickleup(); // moves the job to the right place
	 }
	else cout << "Error , cant add anymore Q is full"; 
	 
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
// **loop to display jobs from slot 0 to slot count - 1 horizontally.No need to show a tree format.
{ cout << "Jobs: " ;
for (int i = 0; i <= count - 1; i++) {   //---------------- added SHARK
	cout << Q[i] << " ";				//---------------- added SHARK
}
cout << endl;
  
} 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
	// ** swap the values in these locations in Q
	int temp;		//---------------- added SHARK
	temp = loc1;	//---------------- added SHARK
	loc1 = loc2;	//---------------- added SHARK
	loc2 = temp;	//---------------- added SHARK
	
}

// Purpose: to make the very last job trickle up to the right location 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  int parent{};    //initialized parent;
  while (x > 0) { // ** While x is > 0   
	  
	  parent = getParent(x); // calling  getParent function and asssigning the value to parent
	  if (Q[x] > Q[parent]) {  //    compare Q[x] with the parent (*) and if the parent is bigger 
		  swap(x, parent);  // swap & update x 
	  }
  
	  x--;  // to exit the cycle;
  }
 
 
  //    to be the parent . Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.

}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  // ** return the parent location based on the child loc
	return even(childloc);
}

//
// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  // ** Start X at 0 (the root)
  //    while X is within the array:
  //       Find the location of the smaller child
  //         (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent,
  //          swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop.
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
//int pqueue::getSmallerchild(int i)
//{
//// ** return the location of the smaller child 
////    Be careful because one or both of them may be
////    beyond count-1.  Check boundaries before you 
////    compare Q contents!!!!
//}


