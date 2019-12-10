// ====================================================
//HW#: CS 311 Final
//Your name: James Bertel
//Complier:  g++
//File type: slist.cpp implementation file
// NOTE *** The only function that was modified here
//          was a single line in search2
//=====================================================

#include"slist.h" 

#ifndef SLIST_CPP
#define SLIST_CPP

// ** Make sure llist constructor and destructors have couts in them

//empty constructor of slist
slist::slist()
{}

//Purpose: Searches through the list to see if any node contains the key
//If so, returns the position (>=1). Otherwise, returns 0.
//Parameter: el_t key == element in the list being searched for

int slist::search(el_t key) 
{
  Node *P = Front;
  int counter = 1;

  while(P != NULL)
    {
      //if key found, return POSITION
      if(P->Elem == key)
	return counter++;
      else
	counter++;

      P = P->Next;
    }
  
  //exits while loop if key was not found
  return 0;
}

//Purpose: Searches through the list to see if any node contains the key
//If so, returns the element. Otherwise, returns 0.
//Parameter: el_t key == element in the list being searched for

el_t slist::search2(int key)
{
  Node *P = Front;
  int counter = 0;

  while(P != NULL)
    {
      //if key found, return ELEMENT

      if(P->Elem.getrank() == key) //if Oteam ranking is found
        return P->Elem;
      else
        counter++;

      P = P->Next;
    }

  //exits while loop if key was not found
  //return a blank element
  el_t blank;
  return blank;
}

//Purpose: Goes to the Ith node (1 <= I <= Count) and replaced the element
//there with a new element. If I is an illegal value, throw OutOfRange()
//Parameters: int pos == position of element being replaced; el_t element == new element  
void slist::replace(el_t element, int pos)
{
  Node *P = Front;

  if(pos < 1 || pos > Count)
    throw OutOfRange();


  for(int i = 1; i < pos; i++)
    P = P->Next;

  P->Elem = element;
}
    
//Purpose: Checks to see if the two lists look the same
//Parameter: OtherOne == One of the lists being compared.
bool slist::operator==(const slist& OtherOne)
{
  //assign pointers to each list
  Node *P = Front;
  Node *Q = OtherOne.Front;
 
  //if both lists are empty, return true
  //if one list is empty and the other is not, return false
  //Otherwise, check both lists' elements.
  if(P == NULL && Q  == NULL)
    return true;
  else if(P == NULL || Q == NULL)
    return false;

  //check each element in P and Q to make sure they match
  while(P != NULL && Q != NULL)
    {
      if(P->Elem == Q->Elem)
	{ P = P->Next;
	  Q = Q->Next;}
      else
	return false;
    }

  //if one list is now null but the other is not, return false.
  //otherwise, the lists have passed all the tests. return true.
  if(P == NULL && Q != NULL)
    return false;
  else if(P != NULL && Q == NULL)
    return false;

  return true; //once lists have passed both tests, return true
}
#endif
