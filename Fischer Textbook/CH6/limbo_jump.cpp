#include "tools.hpp"

int main( void )
{
 	char fname[20];
	char* lname = new char[20];
	char* here;

	for(int k=0; k<2000; k+=200){ 
		here = &fname[k];
		cout << "Enter two names: ";
 		cin >> fname >> lname;
 		cout << k << ": " << here << " " << lname << endl;
	 }
}
