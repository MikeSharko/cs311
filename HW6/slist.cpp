// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P2 llist
//Your name: Mike Sharko
//Complier:  g++
//File type: slist implementation file
//=====================================================
using namespace std;

#include<iostream>
#include "slist.h"

//Constructor
 // ** Make sure llist constructor and destructors have couts in them
slist::slist()
{
	llist();
	cout << "slist Constructor: " << endl;
}

// positions always start at 1
//search through the list to see if any node contains Key
int slist::search(el_t Key)
{
	int position = 1;
	Node* p = Front;

	if (Count == 0)
	{
		return 0;
	}

	else
	{
		//looks through nodes in search of matching element
		while (p->Elem != Key)
		{
			//fail case if the element is not found within the list
			if (p->Next == NULL)
			{
				return 0;
			}
			//moves on to the next node
			p = p->Next;
			//increments the position in the Node
			position++;
		}
		//returns the position the element was found in, this should only happen if the element was actually found
		return position;
	}
}

//go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
//If I was an illegal value, throw an exception (OutOfRange).
void slist::replace(el_t Elem, int I)
{
	Node* p = Front;
	int position = 1;

	//checks to see if I is within the range of the list
	if (I < 1 || I > Count)
	{
		throw OutOfRange();
	}

	else
	{
		//looks through nodes in search of matching element
		while (position != I)
		{
			//moves on to the next node
			p = p->Next;
			//increments the position in the Node
			position++;
		}

		cout << "replaced " << p->Elem << " with " << Elem << endl;

		//at this point p should be in the Node requested
		p->Elem = Elem;
	}
}
//to compare two lists if they look the same
//if (L1 == L2) cout << "true" << endl; else cout << "false" << endl; // -------- for myself
//2. L1 is empty and L2 with 4, 5-------- for myself
//L1 with 1,2,3 and L2 with  1,2,3-------- for myself

bool slist::operator==(const slist& OtherOne)
{
 
	int count = 0; // counter for the first list
	Node* P1 = Front; // Initialize current  to points Otherones front 
	while (P1 != NULL)
	{
		count++;
		P1 = P1->Next;
	}

	int count2 = 0; //counter for second list
	Node* P2 = OtherOne.Front;   //L2
	while (P2 != NULL)
	{
		count2++;
		P2 = P2->Next;
	}



	// THIS PART WAS HARD :)
	//  To compare ELEMENTS of two lists   --- A little bit ugly but i was tired
	 P1 = Front; 
	 P2 = OtherOne.Front;
	 bool flag=1;
	 if (P1 != NULL && P2 != NULL) { 
		 while (P1 != NULL && P2!=NULL) {
			 if (P1->Elem == P2->Elem) {  //comaring elements of 2 lists
				 flag = 1; // my flag
				 
			 }
			 else
				 flag = 0;  // if the flag is 0 Elements are not the same
			 P1 = P1->Next; //moving the pointer to the next element
			 P2 = P2->Next; //moving the pointer next 
		 }
	 
	 }

	if (count == count2 && flag==1) // couunt and count2 must be equal(for lists length) and flag must
									//be 1 for different elements and my list1 will be  == list2
		return true;
	return false;
	 }
  	// if not the same length, return false
	// if the same lengths,
	//check each node to see if the elements are the same
 

 
