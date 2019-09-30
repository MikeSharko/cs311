using namespace std;
#include <iostream>
#include <math.h>
//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Mike Sharko
// Compiler: g++
// File type: binarysearch program
// --------------------------------------------



// PURPOSE: This function(binarySearch) does a binary search on an sorted arraylist.

// ALGORITHM:
// We are performing a serch of a number in a sorted array using recursion. We have a sorted array 
// and a number that we need to search. With our two variables first and last we are setting 
// the boundary of our array. We need to find a middle point by deviding first +last by two. 
// Than we compairing it with our element x, if it is found returning it, if not we continue  
// our comaprison.  If the element is not found returning -1



// x is what we are looking for in L; first and last are slot numbers 
int binarySearch(int L[], int x, int first, int last) 
{
	if (first > last) return -1; //if the first is bigger than last that means number couldnt be found
	int middle = floor((first + last) / 2);  // note that if first == last, there is only one element left
	cout << "comparing against an element in slot " << middle << endl;
	if (x == L[middle]) return middle;  // found x at location middle, so return the location
	else if (x < L[middle]) last = middle - 1; 	// go to first half
	else if (x > L[middle]) first = middle + 1; 	// go to second half
	
 
	
	return binarySearch(L, x, first, last); 		// recursive call
}


int main()
{ int A[10];
  int e;  // to look for this
  int myfirst = 0;     
  int mylast = 9; //  set up initial indices 
  // fixed elements for A
  A[0] = 1; A[1] = 3; A[2] = 5; A[3] = 7; A[4] = 9; A[5] = 11; A[6] = 13;
  A[7] = 15; A[8] = 17; A[9] = 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, myfirst, mylast);

  if (respos == -1) cout << "Element is not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}


 
