// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: James Bertel
// File type: client hw8client.cpp (tester)
//===========================================
//#include "elem.h"
using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{
  htable theTable;
  int key;
  string name;
  int end = 1;

  while(end != 0)
    {
      cout << "\nEnter a key to add to the table: ";
      cin >> key;
      cout << "\nEnter a name for the key: ";
      cin >> name;

      el_t element(key, name); //add key and name into an element
      int slot = theTable.add(element); //add element to the table
           
      //offer to end program
      cout << "Enter 0 to stop adding elements, or enter 1 to continue: ";
      cin >> end;
    }
  theTable.displayTable();
  end = 1;

  while(end != 0)
    {
      cout << "Look for? ";
      cin >> key;

      el_t E = theTable.find(key); //find the key and put in an element
      el_t blank; //purposely blank element

      if(E == blank) //if key element returned to be blank, key not found
	cout << key << " not found." << endl;

      else //else, show found key
	  cout << "Found " << key << ": " << E << endl;

      //offer to end program
      cout << "Enter 0 to stop add elements, or enter 1 to continue: ";
      cin >> end;
    }

  /* **
 Loop:  
   Interactively add about 20 keys and names to the table,
     making sure some of them  collide. (function add)
     You can create el_t containing a key and name using a constructor.
 DisplayTable.
 Loop:
  Interactively look up names using keys. (function find)
  Cout the key + name if found else (blank element was returned) error message. */
 }
