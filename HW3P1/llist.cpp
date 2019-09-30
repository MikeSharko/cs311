//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: **
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ cout << "... in llist constructor..." << endl; }

llist::~llist()
{ cout << ".... in llist destructor..." << endl; }

PURPOSE:
PARAMETER:
bool llist::isEmpty() { } // be sure to check all 3 data members

PURPOSE:
PARAMETER:
void llist::displayAll() { }  // be sure to display horizontally in [  ] with
// blanks between elements
  
PURPOSE:
PARAMETER:
void llist::addRear(el_t NewNum) { } // comment the 2 cases

PURPOSE:
PARAMETER:
void llist::addFront(el_t NewNum) { } // comment the 2 cases

PURPOSE:
PARAMETER:
void llist::deleteFront(el_t& OldNum) { } // comment the 3 cases

PURPOSE:
PARAMETER:
void llist::deleteRear(el_t& OldNum){} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int I, Node*& temp)
{ // moves temp I-1 times
  for ( int j = ... ) temp = temp->Next;
}

PURPOSE:
PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) { } // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  

PURPOSE:
PARAMETER:
void llist::insertIth(int I, el_t newNum) { } // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

PURPOSE:
PARAMETER:
llist::llist(const llist& Original) { } // use my code

PURPOSE:
PARAMETER:
llist& llist::operator=(const llist& OtherOne) { } // use my code

