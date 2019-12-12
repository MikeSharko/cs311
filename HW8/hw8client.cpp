// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Mike Sharko
// File type: client hw8client.cpp (tester)
//===========================================
//#include "elem.h"
using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>



 
// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{
  htable theTable;
  int key;
  string name;
  string lastname;
  string phone;
  int age;
  string sex;
  int end = 1;
  string file = "input.txt";
  ifstream fin; //for input
  ofstream fout; //for output
  fin.open(file);
 
 
  if (!fin.is_open()) {
	  cout << "File open error";
  }
  else {
	  cout << "DataBase opens fine V. 1.0-beta" << endl;
	  while (fin >> key)
	  {
		  fin >> name;
		  fin >> lastname;
		  fin >> phone;
		  fin >> age;
		  fin >> sex;
		  //cout << key << " " << name << " " << phone<< age << sex<<" "<< endl;
		  el_t element(key, name, lastname, phone, age, sex); //add key and name, phone, age, sex into an element class
		  int slot = theTable.add(element); //add element to the table
	  }
	  fin.close();
  }
  
  {
	  bool end = false; //variable to end program
	  int choice; //menu choice

	  while (end == false)
	  {
		  do {
			  cout << endl;
			  cout << "--------------M E N U-----------------" << endl;
			  cout << "\tWhat would you like to do?" << endl <<endl;
			  cout << "\t1. Search for a Person" << endl;
			  cout << "\t2. Add Person to DB" << endl;
			  cout << "\t3. Show all Persons" << endl;
			  cout << "\t4. End Program" << endl;

			  cout << "--------------------------------------" << endl;
			  cout << "\nEnter choice: ";
			  cin >> choice;
		  }
		  while (choice < 1 || choice > 4);


		  if (choice == 1) {
			  cout << "Enter a key: " ;
			  cin >> key;

			  el_t E = theTable.find(key); //find the key and put in an element
			  el_t blank; 

			  if (E == blank) //if key element returned to be blank, key not found
				  cout << key << " person not found." << endl;

			  else //else, show found key
				  cout << "Found " << key << ": " << E << endl;
		  
		  }
		  else if (choice == 2) { // adding Person to DB
			  
			  cout << "\nEnter a key to add to the table: ";
			  cin >> key;
			  cout << "\nEnter a name: ";
			  cin >> name;
			  cout << "\nEnter last name: ";
			  cin >> lastname;
			  cout << "\nEnter phone number in format 000-000-0000: ";
			  cin >> phone;
			  cout << "\nEnter age: ";
			  cin >> age;
			  cout << "\nEnter sex: (M/F) ";
			  cin >> sex;

			  el_t element(key, name, lastname, phone,age,sex) ; //add key and name into an element
			  int slot = theTable.add(element); //add element to the table
			  fout.open(file, ofstream::app); //saving back to file
			  fout << "\n" << key <<" "<< name<< " " << lastname<< " " << phone<< " " << age<< " " << sex; // what saving
			  cout << "Person added to DB ";
		  }
		  else if (choice == 3)
			  theTable.displayTable();
		  else if (choice == 4) 
			  end = true; 

	  }//endwhile
  }

 
  }//main
   

