//------------------------------------------------------------------------------
// Array construction example, October 8, 2000				   	  file: BoxM.cpp 
//------------------------------------------------------------------------------
#include "tools.hpp"
#include "box.hpp"	
//------------------------------------------------------------------------------
int main( void ) 
{	cout << "\nTesting the default parameters\n";   
	Box B1;				// Make a default Box.
	Box B2(2);			// Make Boxes with various parameters.
	Box B3(2, 3);          
	cout <<"\nDumping the boxes:\n" << B1 << B2 << B3 <<endl;
}
