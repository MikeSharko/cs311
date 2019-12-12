// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Mike Sharko
// File type: client client.cpp (tester)
//===========================================
//#include "elem.h"
using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>




 
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
  //string file = "input.txt"; //doesn't want to compile on emacs when using  a variable
  ifstream fin; //for input
  ofstream fout; //for output
  fin.open("input.txt");
 
 
  if (!fin.is_open()) {
	  cout << "File open error";
  }
  else {
	  cout << "\tDataBase opens fine V. 1.1-beta" << endl;
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
			  cout << "\t--------------M E N U-----------------" << endl;
			  cout << endl;
			  
			  cout << "\t1. [ Search in DB ]" << endl;
			  cout << "\t2. [ Add Person to DB ]" << endl;
			  cout << "\t3. [ List all DB ]" << endl;
			  cout << "\t4. [ About ]" << endl;
			  cout << "\t5. [ End Program ]" << endl;
			  cout << endl;
			  cout << "\t--------------------------------------" << endl;
			 
			  cout << "\n\tEnter choice: ";
			  cin >> choice;
			  system("clear");
		  }
		  while (choice < 1 || choice > 5);


		  if (choice == 1) {
			  cout << endl;
			  cout << "\tEnter a key: ";
			  cin >> key;

			  el_t E = theTable.find(key); //find the key and put in an element
			  el_t blank;

			  if (E == blank) //if key element returned to be blank, key not found
				  cout << key << "\tPerson is not found." << endl;

			  else //else, show found key
				  cout << "\tFound " << key << ": " << E << endl;

		  }
		  else if (choice == 2) { // adding Person to DB

			  cout << "\n\tEnter a key to add to the table: ";
			  cin >> key;
			  cout << "\n\tEnter a name: ";
			  cin >> name;
			  cout << "\n\tEnter last name: ";
			  cin >> lastname;
			  cout << "\\tnEnter phone number in format 000-000-0000: ";
			  cin >> phone;
			  cout << "\n\tEnter age: ";
			  cin >> age;
			  cout << "\n\tEnter sex: (M/F) ";
			  cin >> sex;

			  el_t element(key, name, lastname, phone, age, sex); //add key and name into an element
			  int slot = theTable.add(element); //add element to the table
			  fout.open("input.txt", ofstream::app); //saving back to file
			  fout << "\n" << key << " " << name << " " << lastname << " " << phone << " " << age << " " << sex; // what saving
			  cout << "\tPerson added to DB ";
		  }
		  else if (choice == 3) {
			  cout << endl;
			  theTable.displayTable();
		  }
		  else if (choice == 4) {
			  cout << endl;
			  cout << "\t -------------A B O U T --------------" << endl;
			  cout << "\t This is a demo program simulating a simple registery data base of famous people." << endl;
			  cout << "\t It is using hash table function and linked list. You can make a simple search by ID, add people to data base." << endl;
			  cout << "\t They will be saved in input.txt file which works like a simple data base." << endl;
			  cout << "\t You can also list all the people who are in data base." << endl;
			  cout << "\t Program is written by Mike Sharko for CS311 course." << endl;
			  cout << "\t -------------------------------------" << endl;
		  }
		 
		   
		  
		  else if (choice == 5) {
			  cout << endl;
			  cout << "\t Thank you for using our program, see you next time." << endl;
			  system("pause");
			 
			  end = true;
		  }

	  }//endwhile
  }

 
  }//main
   

