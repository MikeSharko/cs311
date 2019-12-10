// ====================================================
//HW#: CS 311 Final
//Your name: James Bertel
//Complier:  g++
//File type: llist.cpp implementation file
// NOTE *** This file was not modified for the final
//=====================================================

#include "llist.h" 
#ifndef LLIST_CPP
#define LLIST_CPP

llist::llist()
{
  //cout << "calling the llist constructor" << endl;
  Front = Rear = NULL;
  Count = 0;
}

llist::~llist() 
{ 
  el_t x; //temporary variable to hold deteled nodes 

  //cout << "calling the llist destructor" << endl;

  while(!isEmpty())
    deleteFront(x);

  //cout << "destructor function finished..." << endl;
}

//PURPOSE: Checks to see if list is empty 
//PARAMETER: None
bool llist::isEmpty() 
{
  if(Front == NULL && Rear == NULL && Count == 0)
    return true;
  else 
    return false;
}

//PURPOSE: Displays all elements of all nodes in the list  
//PARAMETER: None
void llist::displayAll() 
{ 
  //special case: if list is empty, abort function
  if(isEmpty())
    {cout << "[empty]" << endl; return;}

  //regular case: displays all characters using temporary Node pointer
  Node *p;
  p = Front;

  while(p != NULL)
    {
      cout << p->Elem;
      p = p->Next;
    }

}

//PURPOSE: Adds a node to the front of the list  
//PARAMETER: NewNum == Element being added
void llist::addFront(el_t NewNum) 
{ 
   //special case: the node added will be the first and rear node,
  // and NewNum is put in Elem field. Count is updated.
  if(isEmpty())
    {
      Node *P = new Node;
      P->Elem = NewNum;

      Front = Rear = P;
      Count++;
    }
  //regular case: adds a a new node in the front,
  // and NewNum is put in Elem field. Count is updated.
  else
    {
      Node *Q = new Node;
      Q->Elem = NewNum;
      Q->Next = Front;
      Front = Q;
      Count++;
    }      
}

//PURPOSE: Adds a node to the rear of the list  
//PARAMETER: NewNum == Element being added  
void llist::addRear(el_t NewNum) 
{ 
  //special case: the node added will be the first and rear node,
  // and NewNum is put in Elem field. Count is updated.
  if(isEmpty())
    {
      Node *P = new Node;

      P->Elem = NewNum;

      Front = P;
      Rear = P;
      Rear->Next = NULL;

      Count++;
    }
  //regular case: adds a new node at the rear of the list
  // and puts NewNum in the Elem field. Count is updated.
  else
    {
      Node *Q = new Node;
      Rear->Next = Q;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
}

//PURPOSE: Deletes a node in the front of the list 
//PARAMETER: OldNum == Element being deleted  
void llist::deleteFront(el_t& OldNum) 
{ 
  //error case: If list is empty, throws an exception
  if(isEmpty())
    throw Underflow();
  //special case: if node being deleted is the only node in the list, give back
  // the front node element (pass by reference) before removing. Count is updated.
  else if(Count == 1)
    {
      OldNum = Front->Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  //regular case: gives back front node (pass by reference) and removes
  // the front node. Count is updated.
  else //Count > 1
    {
      OldNum = Front->Elem;
      Node *Second;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
}

//PURPOSE: Deletes a node in the rear of the list  
//PARAMETER: OldNum == Element being deleted    
void llist::deleteRear(el_t& OldNum) 
{ 
  //error case: If list is empty, throws an exception
  if(isEmpty())
    throw Underflow();
  //special case: if node being deleted is the only node in the list, give back
  // the rear node element (pass by reference) before removing. Count is updated.
  else if(Count == 1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Rear = NULL;
      Front = NULL;
      Count--;
    }
  //regular case: gives back rear node (pass by reference) and removes
  // the front node. Count is updated.
  else //Count > 1
    {
      OldNum = Rear->Elem;

      Node *SecondToLast = Front;

      while(SecondToLast->Next != Rear) 
	SecondToLast = SecondToLast->Next;
      
      delete Rear;
      Rear = SecondToLast;
      Rear->Next = NULL;
      Count--;
    }
}

//PURPOSE: Deletes a certain node (the Ith node)  
//PARAMETERS: I == Node position being found; OldNum ==  element being deleted 
void llist::deleteIth(int I, el_t& OldNum) 
{ 
  //Error cases: If I is an illegal value, throws exception
  if(I > Count || I < 1)
    throw OutOfRange();
  //Special Cases: calls deleteFront if I == 1 ; calls deleteRear if I == Count
  else if(I == 1)
    deleteFront(OldNum);
  else if(I == Count)
    deleteRear(OldNum);
  //Regular case: Deletes Ith node (I starts at 1). Count is updated.
  else // 1 < I < Count
    {
      Node *J;
      J = Front;

      //place J before Ith Node
      for(int L = 1; L < I-1; L++)
	J = J->Next;

      Node *K; 
      K = J->Next; //places K at I 
      OldNum = K->Elem;
      J->Next = K->Next;
      delete K; //Delete I
      //J = J->Next; delete J;
      Count--;
    }
  cout << "\tCount: " << Count << endl;

}

//PURPOSE: Adds a node in the Ith position  
//PARAMETER: I == Node position being found; newNum == element being inserted
void llist::insertIth(int I, el_t newNum) 
{
  //Error cases: If I is an illegal value, throws exception
  if(I > (Count+1) || I < 1)
    throw OutOfRange();
  //Special Cases: calls addFront if I == 1 ; calls addRear if I == Count
  else if(I == 1)
    addFront(newNum);
  else if(I == (Count+1))
    addRear(newNum);
  //Regular case: Deletes Ith node (I starts at 1). Count is updated.
  else // 1 < I < Count+1
    {
      Node *J;
      J = Front;

      //place J before Ith Node Spot
      for(int L = 1; L < I-1; L++)
	J = J->Next;

      //create new node K to place at I
      Node *K = new Node;
      K->Elem = newNum;
      K->Next= J->Next; //place K-Next pointing to I
      J->Next = K; //places K at I 
      //J->Next = K->Next;
      //delete K;
      Count++;
    }
  cout << "\tCount: " << Count << endl;

}

//PURPOSE: Copy constructor to allow pass by value and return by vallue
//PARAMETER: Original == Original linked list being copied
llist::llist(const llist& Original) 
{ 

  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;

      if (&Original != this)  // if not the same
	{
	  // this-> object has to be emptied first.
	  while (! this->isEmpty() )
	  {
	  el_t OldNum;
	  this->deleteRear(OldNum); 
	  }
	  // this-> object has to be built up by allocating new cells with OtherOne elements (**)
	  Node* P = new Node;  // local pointer for OtherOne
	  P = Original.Front;
	  while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	    {
	      el_t newNum = P->Elem;
	      this->addRear(P->Elem);    //P’s element is added to this->
	      P = P->Next;                         // Go to the next node in OtherOne   
	    } 
	}// end of if              
}

//PURPOSE: Overloading of =
//PARAMETER: Linked list being overloaded 
llist& llist::operator=(const llist& OtherOne) 
{
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	{
	  //el_t OldNum;
	  this->deleteRear(this->Rear->Elem);
	}
      // this-> object has to be built up by allocating new cells with OtherOne elements 
      //(**)
      Node* P = new Node;  // local pointer for OtherOne
      P = OtherOne.Front;

      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.

}
#endif
