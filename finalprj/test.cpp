#include <iostream>
#include <string>
using namespace std;

bool theSize(string, string);

int main()
{















  return 0;
}




  /*  string one, two;

  cout << "\nEnter first: ";
  cin >> one;
  cout << "\nEnter two: ";
  cin >> two;

  bool ans = theSize(one, two);

  cout << "One > Two ?: " << ans << endl;

  /*  string name1;
  string name2;
  int size;

  cout << "\nName 1: ";
  cin >> name1;
  cout << "\nName 2: ";
  cin >> name2;

  if(name1.size() > name2.size())
    size = name1.size();
  else
    size = name2.size();

  for(int i = 0; i < size; i++)
    {
      if(name1[i] != name2[i])
        {
	  cout << "\nNOT EQUAL!" << endl;
	  i = name1.size() + name2.size();
	}
    }      

  cout << "\nEQUAL" << endl;

  */

bool operator==(const elem_t& OtherOne)
{
  if (firstName != OtherOne.firstName)
    return false;
  else if(lastName != OtherOne.lastName)
    return false;
  else if(major != OtherOne.major)
    return false;
  else if(position != OtherOne.position)
    return false;
  else if(numOrts != OtherOne.numOrts)
    return false;
  else if(returner != OtherOne.returner)
    return false;

  //if fallacies do not fail, return true                                       
  return true;
}

bool thesize(string a, string b)
{
  int s;

  if(a.size() < b.size())
    s = b.size();
  else
    s = a.size();

  for(int i = 0; i < s; i++)
    {
      if(a[i] == b[i]);
      else if(a[i] < b[i]) return true;
      else return false;
    }

  return true;
}
