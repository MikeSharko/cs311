using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Mike Sharko
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
void combine(vector<int>A, vector<int> B, vector<int>& R)
{
	// reverses vecotors
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	//Until vector A or vector B runs out of elements, make comparisons.
	while (!A.empty() && !B.empty()) {

		// comparsion for when last element of vector A is less than B.
		// push last element of vector A to vector R.
		if (A.back() < B.back()) {
			R.push_back(A.back());
			A.pop_back();
		}
		// comparsion for when last element of vector A is greater than B.
		// push last element of vector A to vector R.
		else {
			R.push_back(B.back());
			B.pop_back();
		}

		cout << " - comparison!" << endl;
	}

	// If there are any remaining elements in either vector A or B, pop until empty.
	// If vector A is not empty
	if (!A.empty()) {
		while (!A.empty()) {
			R.push_back(A.back());
			A.pop_back();
		}
	}

	// If vector B is not empty
	// push last element of vector A
	else if (!B.empty()) {
		while (!B.empty()) {
			R.push_back(B.back());
			B.pop_back();
		}
	}
}


int main()
{
	vector<int> L1;
	vector<int> L2;
	vector<int> L3;
	int N;  // how many elements in each of L1 and L2
	int e;  // for each element

	cout << "How many elements in each list?" << endl;
	cin >> N;

	cout << "List1" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "element :"; cin >> e; L1.push_back(e);
	}

	cout << "List2" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "element :"; cin >> e; L2.push_back(e);
	}


	// call combine here to combine L1 and L2 into L3
	combine(L1, L2, L3);

	cout << "The result is: ";
	for (int i = 0; i < N * 2; i++)
	{
		cout << L3[i];
	} cout << endl;

}// end of main
