//===================================================
// HW#: CS 311 Final
// James Bertel
// File: oteam client file
//==================================================

#include "htable.h"

void SearchforOteamer(htable Oteam2019)
{
  int key; //key == rank being searched

  cout << "Enter the ranking you want to search: ";
  cin >> key;
  el_t E = Oteam2019.find(key); //finds element with associated rank
  el_t blank; //purposely blank element
  
  if(E == blank)
    cout << key << " not found." << endl;
  else //if rank found, show Oteamer
    cout << "Found " << key << ":\n\t" << E << endl;  
}

void showMenu(htable Oteam2019)
{
  bool end = false; //variable to end program
  int choice; //menu choice

  while(end == false)
    {
      do{
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "\t1. Search for an Oteamer" << endl;
	cout << "\t2. Show all Oteamers" << endl;
	cout << "\t3. End Program" << endl;
	cout << "\nEnter choice: ";
	cin >> choice;
      }while(choice < 1 || choice > 3);

      if(choice == 1)
	SearchforOteamer(Oteam2019);
      else if(choice == 2)
	Oteam2019.displayTable();
      else //choice == 3
	end = true;

    }//endwhile
}

void loadTable(htable Oteam2019)
{
  {
    ifstream fin;
    fin.open("oteam.txt");

    el_t Oteamer;
    int count = 0;

    while(fin >> Oteamer.firstName)
      {
	fin >> Oteamer.lastName;
	fin >> Oteamer.major;
	fin >> Oteamer.position;
	fin >> Oteamer.email;
	fin >> Oteamer.phoneNum;
	fin >> Oteamer.rank;

	Oteam2019.add(Oteamer);

      }
    Oteam2019.count = count;
    fin.close();
  }
}

void runProgram()
{
  htable Oteam2019;
  
  loadTable(Oteam2019);
  showMenu(Oteam2019);
}

int main()
{
  runProgram(); //this is how hadaegh taught us to write our programs
  return 0;
}
