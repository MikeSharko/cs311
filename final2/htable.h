//=================================================
// HW#: CS 311 Final
// James Bertel
// File: htable.h
//=================================================
// ------------------------------------------------
#include "slist.h"
#ifndef HTABLE_H
#define HTABLE_H

const int TSIZE = 53;  // 53 slots ; a prime number 

class htable
{
 private:
 slist table[TSIZE]; // each node of slist is el_t 
                          // as defined in elem.h
 int hash(int);  // private hash function
 int count;

 public:
  htable();
  ~htable();

  void add(el_t);  // adds an element to the table
  el_t find(int); // finds an element based on key and returns it
  void displayTable(); // displays the table with slot #s
  void loadTable(); //loads table from a file
};
#endif
