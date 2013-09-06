// STL_Vector_Example.cpp by Joseph Parker, modified by A. Fischer, March 2003
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//---------------------------------------------------------------------
void print(vector<int>& v)		// print out the elements of the vector
{
	int idx = 0;
	int count = v.size();
	for ( ; idx < count; idx++)
		cout << "Element " << idx << " = " << v.at(idx) << endl;
}

//---------------------------------------------------------------------
int main( void )
{	
	vector<int> int_vector;			// create a vector of int's

	// insert some numbers in random order
    int_vector.push_back(11);
    int_vector.push_back(82);
    int_vector.push_back(24);
    int_vector.push_back(56);
    int_vector.push_back(6);

	cout << "Before sorting: " <<endl;
	print(int_vector);							// print vector elements	
	sort(int_vector.begin(), int_vector.end());	// sort vector elements
	cout << "\nAfter sorting: " <<endl;
	print(int_vector);							// print elements again

	// search the vector for the number 3
	int val = 3;
	vector<int>::iterator pos;
	pos = find(int_vector.begin(), int_vector.end(), val);
	if (pos == int_vector.end())
		cout << "\nThe value " << val << " was not found" << endl;

	// print the first element
	cout << "First element in vector is " << int_vector.front() << endl;

	// remove last element
	cout << "\nNow remove last element and element=24 "<< endl;
	int_vector.pop_back();

	// remove an element from the middle
	val = 24;
	pos = find(int_vector.begin(), int_vector.end(), val);
	if (pos != int_vector.end())
		int_vector.erase(pos);

	// print vector elements
	print(int_vector);
	return 0;
}
