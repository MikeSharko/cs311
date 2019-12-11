//-------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "oteam.h"

int main()
{
  OrientationTeam Oteam;

  for(int i = 1; i <= 9; i=i+2) //inserts 1 3 5 7 9
    Oteam.InsertVertex(i);
  for(int i = 10; i >= 2; i=i-2)

  Oteam.Display();


  cout << "Searching for 5" << endl;
  if(Oteam.Search(5)) cout << "found 5 " << endl;
  else cout << "5 not found" << endl;

  cout << "Searching for 11" << endl;
  if(Oteam.Search(11)) cout << "found 11 " << endl;
  else cout << "11 not found" << endl;

  Oteam.InsertVertex(11);
  Oteam.InsertVertex(5);
  Oteam.DeleteVertex(7);
  Oteam.DeleteVertex(12);

  

  /*
    //examples from hw4client

  BST MyTree, Nums1;
  MyTree.Display();
  MyTree.Search(5 
  Nums1.InsertVertex(3);
  Nums1.DeleteVertex(7);
  */  

}// end of program


