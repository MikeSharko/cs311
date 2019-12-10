// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: CS 311 Final
// Name: James Bertel
// File Type: implementation htable.cpp
// =============================================
#include "htable.h"
#ifndef HTABLE_CPP
#define HTABLE_CPP

htable::htable()
{count = 0;}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{
  return (key % TSIZE);
}

// adds the element to the table and returns slot#
void htable::add(el_t element )
{
  int slot = hash(element.rank);  // hash with the rank
  table[slot].addRear(element); //put element in hashed slot
}

// finds element using the skey and returns the found element itself
// or a blank element
el_t htable::find(int skey)
{ 
 el_t E; // a blank element
 int slot = hash(skey); // hash with skey

 E = table[slot].search2(skey); // call slist's search2 with selement which returns the found element 
 return E;// return the found element from here
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  cout << endl;
  for (int i = 1; i <= count; i++)
    {
      cout << left << setw(2) << i << ": ";
      table[i].displayAll(); // call slist's displayAll
    }
  cout << endl;
}

// loads the hash table from a text file
void htable::loadTable()
{
  ifstream fin;
  fin.open("oteam.txt");

  el_t Oteamer;

  while(fin >> Oteamer.firstName)
    {
      fin >> Oteamer.lastName;
      fin >> Oteamer.major;
      fin >> Oteamer.position;
      fin >> Oteamer.email;
      fin >> Oteamer.phoneNum;
      fin >> Oteamer.rank;

      add(Oteamer);
      count++;
    }

  fin.close();
}
#endif
