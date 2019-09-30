#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do.
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Mike Sharko
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r) // f=0, r = 9
{
	int left = f;   // pointer from the left
	int right = r;  // pointer from the right
	while (left <= right) {
		// loop for finding out of place pairs and swap them
			// ** until the left and right cross
			//    if left OK, move left
			//    if right OK, move right
			//    if both are bad, s wap
		while (a[left] < pivot)  //checking if left is less the pivot 
			left++;      // moving the left index
		while (a[right] > pivot)
			right--;	// moving the right index

		if (left <= right)
		{
			swap(a[left], a[right]); // swaping elements
			left++;
			right--;
		}
		//**there is a special cases and a regular case 
	}
	if (left <= right)     // i really don't know how i came with it, but it works :)
		return  a[left] - 1; // returning the partition index
}

int main()
{
	int x;  // number of elements
	int nums[10];
	cout << "How many elements? (must be less than 10) ";
	cin >> x;
	cout << "Enter elements one per line.." << endl;
	for (int i = 0; i < x; i++)
	{
		cin >> nums[i];
	}

	// the pivot is always the first element
	cout << "Ok the pivot is " << nums[0] << endl;

	int part = partition(nums[0], nums, 0, x - 1);

	cout << "Results..." << endl;
	// display up to the partition without endl
	for (int i = 0; i < part; i++)
		cout << nums[i];

	cout << "|";
	// display from the partition on.. without endl
	for (int i = part; i < x; i++)
		cout << nums[i];

	cout << endl;

}