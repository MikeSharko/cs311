/****************
James Bertel
CS 311
Dr. Yoshii
May 2019

Element type of a list node is defined here
****************/
//-----------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//el_t hold information about all Oriention Team Leaders (Oteamers)
class el_t
{
 private:
  string firstName; //first name of Oteamer
  string lastName; //last name of Oteamer
  string major; //major of Oteamer (ex: CS, SE, PSCI)
  char position; //D = Co-Director , L = Leader, R = Returning Oteamer, O = First Fime Oteamer
  string email; //email handle of Oteamer
  long phoneNum; //(raw) phone number of Oteamer
  int rank; //each Oteamer is ranked by how great they have been doing at orientations

 public:

  el_t();  // to create a blank el_t object
  el_t(string, string, string, char, string, long, int);

  int getrank() {return rank;};
  bool operator==(el_t);  // overload == for search
  friend ostream& operator<<(ostream&, const el_t&); 
 
  friend class htable;
};
