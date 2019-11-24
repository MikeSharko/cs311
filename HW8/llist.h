//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: James Bertel
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

#ifndef LLIST_H
#define LLIST_H

// alias el_t : element type definition
#include "elem.h" //typedef char el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: Checks to see if list is empty
  bool isEmpty();
    
  //Purpose: Displays all elements of all nodes in the list
  void displayAll();

  //Purpose: Adds a node to the front of the list
  //Parameter: Element being added
  void addFront(el_t);
    
  //Purpose: Adds a node to the rear of the list
  //Parameter: Element being added
  void addRear(el_t);

  //Purpose: Deletes a node in the front of the list
  //Parameter: Element being deleted
  void deleteFront(el_t&);
    
  //Purpose: Deletes a node in the rear of the list
  //Parameter: Element being deleted
  void deleteRear(el_t&);
    
  //Purpose: Deletes a certain node (the Ith node)
  //Parameters: Node position being found; element being deleted
  void deleteIth(int, el_t&);

  //Purpose: Adds a node in the Ith position
  //Parameters: Node position being found; element being inserted
  void insertIth(int, el_t);

  //Purpose: Copy Constructor to allow pass by value and return by value
  llist(const llist&);
  
  //Overloading of = 
  llist& operator=(const llist&); 

};
#endif
