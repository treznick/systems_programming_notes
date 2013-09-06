//-----------------------------------------------------------------------
// Calling the odd average functions.					   file: oddM.cpp 
//-----------------------------------------------------------------------
#include "odds.hpp"					// Contains the three odd functions.

void print( int* ap, int n ) {      //  Print the n values in an array.
	for( int k=0; k<n; ++k )  cout << "    [" << k << "] = " << ap[k] ;
	cout << endl;
}  
//-----------------------------------------------------------------------
int main( void )
{	
	int  ar[6] = {11, 22, 33, 44, 55, 66};
	int* ip = ar;	  	// Set a pointer to beginning of an array.
	int* iq = &ar[2];	// Set a pointer to 3rd item of array.

	cout << "\nInitially, ar is: ------------------------------------\n";
	print( ar, 6 );  
	odd1( ar[0], *iq );	    print( ar, 6 ); 	// See Figure 5.1.
	odd2( ip, iq );	        print( ar, 6 ); 	// See Figure 5.2.
	odd2( &ar[1], &ar[4] );	print( ar, 6 ); 	// See Figure 5.3.
	odd4( ar[2], *(iq+2) );	print( ar, 6 ); 	// See Figure 5.4.
}
