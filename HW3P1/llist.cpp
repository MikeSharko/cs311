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
//Your name: Mike Sharko
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
	{ cout << "... in llist constructor..." << endl; }
}
llist::~llist() {
	el_t temp;
	// variable to hold deleted nodes element.

	//while not empty, delete from front.
	while (!isEmpty()) {
		deleteFront(temp);
	}
	{ cout << ".... in llist destructor..." << endl; }
}
//PURPOSE: This checks if the link list is empty or not.
//PARAMETER: if front equals null & rear equals null & count equals 0, list is empty, return true
bool llist::isEmpty() {
	 
	if ((Front == NULL) && (Rear == NULL) && (Count == 0)) {  // be sure to check all 3 data members
		return true;
	}
	//else list is not empty, return false.
	 return false;
} 

//PURPOSE: This displays all the nodes in a link list.
//PARAMETER: if list is empty, print empty. if not, go through list by using while loop,
	//			  if pointer does not point to null, print element, update pointer to point to next node
	 		
void llist::displayAll() {
	Node* p = Front; // pointer to traverse list.

//if list empty, show empty.
	if (isEmpty()) {
		cout << " - [ empty ]" << endl; // be sure to display horizontally in [  ] with blanks between elements. Roger that!
	}
	
	//if list is not empty.
	else {
		cout << " - ";

		//traverse list until p is null and print.
		while (p != NULL) {
			cout << "[ " << p->Elem << " ]";

			p = p->Next;
		}
		cout << endl;
	}

}  
 

//PURPOSE:  Adds a new node to the rear of the linked list.
//PARAMETER:  NewNum = element to assign to the new node.
void llist::addRear(el_t NewNum) { // comment the 2 cases. Will do
	// 1) special case
		// new node called mynode is created then its element is set.
		// front and rear pointed to my node. then rear next points to null.
	if (Count == 0) {
		Node* mynode = new Node; // creates new node.
		mynode->Elem = NewNum;
		Front = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}

	// 2) regular case
	// new node called mynode is created then its element is set.
	// rear next points to mynode. rear points to my node, then rear next point to null.
	else {
		Node* mynode = new Node; // creates new node.
		mynode->Elem = NewNum;
		Rear->Next = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}
} 

// PURPOSE: This adds a new node to the front of the linked list.
// PARAMETER: NewNum = element to assign to  the new node.
void llist::addFront(el_t NewNum) { 
	// 1) special case
		// new node created, then element is set. front and rear points to mynode.
		// lastly rear points to null.
	if (Count == 0) {
		Node* mynode = new Node; // creates new node
		mynode->Elem = NewNum;
		Front = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}

	// 2) regular case
	// new node created, then element is set. mynode next set to front, then front points mynode.
	else {
		Node* mynode = new Node; // creates new node
		mynode->Elem = NewNum;
		mynode->Next = Front;
		Front = mynode;
		Count++;
	}

} // comment the 2 cases

//PURPOSE: This deletes a node in front of the linked list.
//PARAMETER: OldNum = variable to hold deleted nodes element.
void llist::deleteFront(el_t& OldNum) {  // comment the 3 cases
	// if empty, throw underflow.
	if (isEmpty()) {
		throw Underflow();
	}

	// 2) special case
	// fronts element held in oldNum varaible. then front is deleted.
	// front and rear set to null.
	else if (Count == 1) {
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}

	// 3) regular case
	// fronts element held in OldNum variable.
	// second points to node next to front and front is deleted.
	// second is now the front.
	else {
		OldNum = Front->Elem;  
		Node* second; // pointer points to node after front.
		second = Front->Next;
		delete Front;
		Front = second;
		Count--;
	}
} 

// PURPOSE: This deletes a node at the rear of a linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element.
void llist::deleteRear(el_t& OldNum){
	// 1) error case
	// if empty throw underflow
	if (isEmpty()) {
		throw Underflow();
	}

	// 2) special case
	// OldNum holds rears element, then rear is deleted.
	// front and rear set to null.
	else if (Count == 1) {
		OldNum = Rear->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}
	// 3) regular case
	// OldNum holds rears element. new pointer p points to front.
	// list is traversed to point to node before rear. rear is then deleted.
	// rear is set to bide before rear. rear next is set to point to null.
	else {
		OldNum = Rear->Elem;
		Node *p = Front; // pointer to traverse list.

		// loop to point to node before rear.
		while (p->Next != Rear) {
			p = p->Next;
		}

		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
}  


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int I, Node*& temp)
{ // moves temp I-1 times
	temp = Front;
	for ( int j =1; j<=I-1; j++) temp = temp->Next;
}

// PURPOSE: This deletes a node at the ith position in the linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element.
void llist::deleteIth(int I, el_t& OldNum) { 
	// 1) error case
		// if out of range, throw outofrange.
	if (I > Count || I < 1) {
		throw OutOfRange();
	}

	// 2) special case
	// if I equals 1, call deleteFront.
	else if (I == 1) {
		deleteFront(OldNum);
	}

	// 3) special case
	// if I equal Count, call deleteRear.
	else if (I == Count) {
		deleteRear(OldNum);
	}

	// 4) regular case
	// loop is used to point to ith node and get lag pointer.
	// node before p is lag pointer. lag pointer set to point to the node next to p.
	// Oldnum holds p's element, then p is deleted.
	else {
		Node* p = Front; // lead pointer to traverse list
		Node* lag = new Node; //lag pointer

		// loop to point to ith node.
		for (int k = 1; k <= I - 1; k++)
		{
			lag = p;
			p = p->Next;
		}

		lag->Next = p->Next;
		OldNum = p->Elem;
		delete p;
		Count--;
	}
} 

// PURPOSE: This adds a node before the ith position in the linked list.
// PARAMETER: newNum = element to assign to the new node.
void llist::insertIth(int I, el_t newNum) {  // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
	// 1) error case
		// if out of range, throw outofrange.
	if (I > Count + 1 || I < 1) {
		throw OutOfRange();
	}

	// 2) special case
	// if I equals 1, call addFront.
	else if (I == 1) {
		addFront(newNum);
	}

	// 3) special case
	// if I equals count + 1, call addRear.
	else if (I == Count + 1) {
		addRear(newNum);
	}

	// 4) regular case
	// lead and lag pointer created. loo is used to point to the node before Ith.
	// lag next set to point to new node. new nodes element set to newNum.
	// then new node next points to p.
	else {
		Node* myNode = new Node; // new node to add
		Node* p = Front; // lead pointer to traverse list
		Node* lag = new Node; // lag pointer

		//loop to point to the node before I
		for (int k = 1; k <= I - 1; k++)
		{
			lag = p;
			p = p->Next;
		}

		lag->Next = myNode;
		myNode->Elem = newNum;
		myNode->Next = p;
		Count++;
	}
} 

//PURPOSE: copies the list value by value
//PARAMETER: Original is the Original list that is being copid from
llist::llist(const llist &Original) { // !!!!!!!!!!!!!!!!!!! use my code!!!!!!!!!!!!!!!!!!

 
	Front = NULL;
	Rear = NULL;
	Count = 0;
	Node* P; //local pointer for Original
	P = Original.Front;
	 
	while (P != NULL)
	{
		this->addRear(P->Elem);
		P = P->Next;
	}

	   // return the result unconditionally.  Note that the result is returned by reference.
	}
 
//PURPOSE: allows client to use = operator for linked list objects
//PARAMETER: Otherone is the list that is being assigned to "This"
llist& llist::operator=(const llist& OtherOne) {
	el_t x;
 	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects .
	if (&OtherOne != this)  // if not the same
	{
		// this-> object has to be emptied first.
		while (!this->isEmpty())
			this->deleteRear(x);
		// this-> object has to be built up by allocating new cells with OtherOne elements (**)
		Node* P;  // local pointer for OtherOne
		P = OtherOne.Front;
		while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);    //P’s element is added to this->
			P = P->Next;                         // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;
}
