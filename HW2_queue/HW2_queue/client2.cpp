//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Mike Sharko
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program:  Using a queue it will generate 50 strings (can generate any number if needed) using characters A, B, and C.
//Algorithm: Initially we add characters "A" ,"B", "C" to the queue. Our program has to generate all new possible sequences using these characters. 
// an element is poped from the queue and is appended with elements from myset array which are A,B and C
// New strings are generated with this.
//The generation of strings stops when the queue is Overflowed.
int main()
{ // ** "A", "B", "C" in the queue
  // ** while loop -- indefinitely
	queue myQueue; // new queue object
	string myset[3] = { "A", "B", "C" }; //chars to generate new string
	string tmp; // It is needed when we pop elements from the queue to make a new queue
	string myNewString; //variable needed to keep new string that was generated

	try
	{		
		for (int i = 0; i <= 2; i++) {	// Loads elements A, B , C into the queue
										
			myQueue.add(myset[i]);
			cout << myset[i] << endl; // A, B, C are printed then
		}

		
		while (!myQueue.isFull()) { // This block will end if queue becomes full
			myQueue.remove(tmp);			
			for (int i = 0; i <= 2; i++) {  // New string is generated by appending element removed from queue with a character from myset
				myNewString = tmp + myset[i];	
				myQueue.add(myNewString);	//adding new string to the queue

				cout << myNewString << endl;	//prints the new string into the console
			}
		} // while loop end here

	}// try block ends here
		catch 
			(queue::Overflow) {  //catching Overflow
			cerr << "Err: Overflow happened! - Queue is Full. " << endl;
		} 
	return 0;
}
