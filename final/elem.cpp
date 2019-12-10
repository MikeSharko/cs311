/*****************
James Bertel
CS 311
Dr. Yoshii
May 2019

Element type of a list node is defined here 
*****************/
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  firstName = "N/A";
  lastName = "N/A";
  major = "N/A";
  position = 'N';
  email = "N/A";
  phoneNum = 1234567890;
  rank = 0;
}

// initializing constructor to create an el_t object 
el_t::el_t(string f, string l, string k, char n, string e, long p, int r)
{
  firstName = f;
  lastName = l;
  major = k;
  position = n;
  email = e;
  phoneNum = p;
  rank = r;
}

// overload == for search based on all el_t information
bool el_t::operator==(el_t OtherOne)
{
  //if the element doesnt match in any way, return false

  if (firstName != OtherOne.firstName) 
    return false;
  else if (lastName != OtherOne.lastName) 
    return false;
  else if (major != OtherOne.major) 
    return false;
  else if (position != OtherOne.position) 
    return false;
  else if (phoneNum != OtherOne.phoneNum) 
    return false;

  return true;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << left;
  os << setw(12) << E.firstName;
  os << setw(15) << E.lastName;
  os << setw(6) << E.major;
  os << setw(3) << E.position;
  os << setw(9) << E.email;
  os << setw(12) << E.phoneNum;
  os << endl; //rank does not need to be shown here
  return os;  
}  


