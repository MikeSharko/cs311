#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW2EC Matrix 
// Your name: Mike Sharko
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{
	//in ASCII 'a' is 97, by subtracking  char -97 we will get the number we need, in our case 0
	return x - 97;
}

// IT took me 8 hours to make this readTable function . I hope next time will be faster.
int readTable()
{
	int row, col;
	char col_c;
	ifstream fin("lines.txt", ios::in);
	// Read in the file into T
	while (fin >> row)
	{
		fin >> col_c; col = convert(col_c);  // to a slot number
		vector<char> v;  // a vector to fill
		char c; // one char from the file
		for (int i = 0; i < VM; i++) {
			fin >> c;
			v.push_back(c);   // ** Fill v with chars from the file (a loop)
		}

		T[row][col].push_back('-'); // didn't know how to make without it and i am just tired.
		for (int i = 0; i < 3; i++) {
			T[row][col].push_back(v[i]); // 
		}


	}//end of while
	return 0;
}


void showVector(vector<char> v)
{
	if (v.size() == 0)  // empty entry
		for (int i = 1; i <= VM; i++) cout << "- ";
	else
		for (int i = 1; i < v.size(); i++)
			cout << v[i] << " "; // show the content of v separated by blanks
}


void displayTable()
{
	// ** display T nicely labeled with row numbers
	//    by calling showVector

	for (int row = 0; row < R; row++)
	{
		cout << row << "| ";
		for (int col = 0; col < C; col++)
		{
			showVector(T[row][col]);
			cout << " | ";
		}
		cout << endl;
	}
}

int main()
{

	readTable();
	displayTable();

}
