// CS311 Yoshii
// HW3P2 Instruction: Inherit everything publicly from llist
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================
// HW#: HW3P2 slist
// Name: Mike Sharko
// File: slist.h
//=================================================
#include "llist.h"

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  // elements will be int (for now)

//class slist, inheriting publicly from llist
class slist : public llist
{
public:

	 
	slist(); // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!

	
	// search through the list to see if any node contains the key.
	// If so, return its position (>=1). Otherwise, return 0.
	int search(el_t Key);

	// go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
	void replace(el_t Elem, int I);
	
	// checks to see of the two lists look the same
	bool operator==(const slist&);
};