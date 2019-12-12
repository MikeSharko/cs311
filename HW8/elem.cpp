// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"
#include<iomanip>

// blank element
el_t::el_t()
{
  key = -1;
  name = "";
  lastname = "";
  phone = "";
  age = -1;
  sex = "";
}
 
// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aname, string alastname, string aphone, int aage, string asex)
{
  key = akey;
  name = aname;
  lastname = alastname;
  phone = aphone;
  age = aage;
  sex = asex;
}

// initializing constructor to delete an el_t object   
el_t::el_t(int akey) { // i suppose to make it but i didn't finish it in this version. maybe in future.
	key = -1;
}


// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

// overload != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout to display everything nicely
ostream& operator<<(ostream& db, const el_t& E)  
{ 
	db << left;
	
	db << "Name: " << E.name;
	db <<" "<< E.lastname;
	db << "\t";
	db << " | " << "Phone: " << E.phone; 
	db << " | " << "Age: " << E.age;
	db << " | " << "Sex: " << E.sex;
	 
  return db;  
}  
