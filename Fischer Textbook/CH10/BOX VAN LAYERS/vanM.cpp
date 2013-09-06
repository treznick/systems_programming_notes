//--------------------------------------------------------------------------------
// Array construction example, October 8, 2000				   	    file: vanM.cpp 
//--------------------------------------------------------------------------------
#include "tools.hpp"
#include "van.hpp"	
//--------------------------------------------------------------------------------
int main( void ) 
{	cout << "\nA dynamic array of class objects.\n";   
	Van V;									// Make a Van with space for 5 Boxes.
	// Van V(2);                            // Alternate version has 2 Boxes.
	cout <<"\nAbout to dump the van:\n";               
	V.dump( cout );
	bye();
}
