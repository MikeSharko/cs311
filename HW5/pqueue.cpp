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
	
		cout << "Adding: " << j << endl;
		try {
			if (count >= MAX) {  // if to many jobs throw  error
				throw -1;
			}// checking if count less than our array
			// ** add the job j at the rear (and update count)
				
				Q[count] = j;		//adding a job to proper place
				count++;			//increasing job counter

				trickleup(); // moves the job to the right place
			
			
			// **   if possible else display error message. 
		}
			catch (int x) {
				cout << "Error , cant add anymore Job's Q is full" << endl << endl;
			}
		
		//else cout << "Error , cant add anymore Job's Q is full" << endl << endl;
	 
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
for (int i = 0; i <= count - 1; i++) {   // counter to cycle through the array
	cout << Q[i] << " ";				 // 
}
cout << endl;
  
} 
 
// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)  
{
	// ** swap the values in these locations in Q
 // standart swapping algorithm, nothing new here :);
	int temp = Q[loc1]; 
	Q[loc1] = Q[loc2];   
	Q[loc2] = temp;
	
}

// Purpose: to make the very last job trickle up to the right location 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  int parent{};    //initialized parent;
 
  while (x > 0) { // ** While x is > 0   
	  
	  parent = getParent(x); // (*) Call getParent to get the location of the parent
	  if (Q[parent] > Q[x]) {  //    compare Q[x] with the parent (*) and if the parent is bigger 
		  swap(x, parent); // swap & update x 
		  //x = parent;  //is wrong because i've already swapped them!
		  // that's why i don't know what update x mean!
		  // maybe in my implementation there is no need to update x
	 	  }
   	  x--;  // to exit the cycle;
  }
}

// Purpose: find the location of the parent 
// The child location is given.   
int pqueue::getParent(int childloc)
{  // ** return the parent location based on the child loc
	if (even(childloc))
		return  (childloc / 2) - 1;
	else
		return childloc / 2;
  
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }

 
 
// Purpose: to reheapify the Pqueue after printing
//  This trickles down
void pqueue::reheapify()
{
	int x = 0 ;   //the current location initializing it to 0 to start X is a root 
	Q[0] = Q[count - 1];  // move the last job to the front
	count--;
	
	    //**Start X at 0 (the root)
		//    while X is within the array:
		//       Find the location of the smaller child
		//         (if the location of both children are off the tree, stop the loop).

		//       If the smaller child is smaller than the parent,
		//          swap and X becomes the smaller child's location.
		//       else no swaps so stop to loop.

	while (x < count - 1) {
		int child = getSmallerchild(x); //smaller child of x
		if (child == -1)
		{
			return;
		}
		else if (Q[child] < Q[x]) // if child less than parent
		{
			swap(x, child);
		}
		x++;
	}
}

// Purpose: to find the location of the smaller child
// where children at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
	    // **return the location of the smaller child
		//  Be careful because one or both of them may be
		//  beyond count-1.  Check boundaries before you 
		//  compare Q contents!!!!

	int left = 2 * i + 1;
	int right = 2 * i + 2;
	 
	if (left >= count && right >= count)
		return -1;
	else if (right >= count)
		return left;
	else if (left >= count)
		return right;
	else if (Q[left] < Q[right])
		return left;
	else  
		return right;
}
