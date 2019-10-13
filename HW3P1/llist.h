//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Mike Sharko
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
   void moveTo(int, Node*&); 
  
 public:

  // Exception handling classes 
  class Underflow{}; // thrown when Underflow
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // Checks if the link list is empty or not.
  bool isEmpty();
    
  //Displays all the nodes in the link list.
  void displayAll();

  //  Adds a new node to the front of the linked list.
  void addFront(el_t);
    
  // Adds a new node to the rear of linked list
  void addRear(el_t);

  // Deletes front node
  void deleteFront(el_t&);
    
  // Deletes rear node
  void deleteRear(el_t&);
    
  //Deletes the node in the I'th position
  void deleteIth(int, el_t&);  // calls moveTo

  //Inserts node to the I'th position
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
