#include "tools.hpp"
int main( void )
{	
    char fname[10], lname[10];
	int nums[4], total = 0;
	cout <<"Enter two names: ";  cin  >>fname >>lname;
	cout <<"You typed: " <<fname << " " << lname << endl;
	cout <<"Enter four numbers: ";
	for( int k=1; k<=4; ++k)  {
		cin >> nums[k];
		total += nums[k];
	}
	cout <<"First: " <<fname << "\nLast: " <<lname <<"\nTotal = " <<total <<endl;
}
