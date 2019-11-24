// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: James Bertel
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#ifndef HTABLE_CPP
#define HTABLE_CPP

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{
  return key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element); //put element in hashed slot
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element
el_t htable::find(int skey)
{ 
 el_t E; // a blank element
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.key = skey; // initialize it with just the skey
 E = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return E;// return the found element from here
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}
#endif
