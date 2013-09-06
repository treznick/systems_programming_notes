//-----------------------------------------------------------------------
// Calling functions with the five kinds of function-return values.  
// A. Fischer Apr 19, 1998                                 file: retM.cpp 
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;
#include "returns.cpp"

#define DUMPv(k) "\n" <<"    " #k " @ " <<&k <<"    value = " <<k 
#define DUMPp(p) "\n" <<"    " #p " @ " <<&p <<"    value = " <<p \
                      <<"    " #p " --> " << dec << *p 
//-----------------------------------------------------------------------
void print5( int* ap ) {       		// Print the five values in an array.
	for( int k=0; k<5; ++k )  cout << "    [" << k << "] = " << ap[k] ;
}  

//-----------------------------------------------------------------------
int main( void )
{   
	int ar[5] = {11, 22, 33, 44, 55};
	int h, j, k, m, n;
	int *p = ar; 

	cout << "Initially, variables are: ------------------------------\n";
	print5( ar );  
	cout <<DUMPp(p);

	h  =  ret0( ar );	// Answer should be 11 
	j  = *ret1( ar );	// Answer should be 22	 
	k  = *ret2( ar );	// Answer should be 33	 
	m  =  ret3( ar );	// Answer should be 44	 
	n  =  ret4( ar );   // Answer should be 55
	cout <<DUMPv(h) <<DUMPv(j) <<DUMPv(k) <<DUMPv(m) <<DUMPv(n) <<endl;

	p = ret1( ar );		// Answer should be a pointer to ar[1].
	*ret1( ar ) = 17;	// Storing through the pointer.	 
	//*ret2( ar ) = 17;	// Illegal: read-only location.	 
	ret3( ar ) = -2;	// Assigning to the reference. 
	//ret4( ar ) = -2;	// Illegal: read-only location.	 

	cout << "\nAfter return from functions variables are: -----------\n";
	print5( ar );  
	cout <<DUMPp(p) <<endl;
}
