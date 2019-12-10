//=================================================
// HW#: CS 311 Final
// Name: James Bertel
// File: slist.h
// NOTE *** This file was not modified for the final
//=================================================

#include <iostream>
#include "llist.h"

using namespace std;
#ifndef SLIST_H
#define SLIST_H

class slist : public llist // **
{
 public: // **

  slist();

  int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its POSITION (>=1). Otherwise, return 0.
  
  void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    
  bool operator==(const slist&);
    // checks to see of the two lists look the same

  el_t search2(int);
    //search through the list to see if any node contains the key
    // If so, return the ELEMENT of the node. Otherwise return black element.
};
#endif
