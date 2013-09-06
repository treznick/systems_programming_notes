//-----------------------------------------------------------------------
// Three odd average functions.							file: odds.cpp 
//-----------------------------------------------------------------------
#include "odds.hpp"

void odd1( int aa, int bb ){				// Make copies of the argument values.
	int ansr = (aa + bb) / 2;         		// See diagram 1.
	cout <<"\nIn odd1, average of " <<aa <<", " <<bb <<" = " <<ansr <<endl;
	++aa;  ++bb;							// Increment the two local integers.
}

void odd2( int* aa, int* bb ){				// Call by address or pointer.
	int ansr = (*aa + *bb) / 2;   			// See diagram 2.
	cout << "\nIn odd2, average of " <<*aa <<", " <<*bb <<" = " <<ansr <<endl; 
	++aa;  									// increment the local pointer 
	++*bb;									// increment main's integer indirectly
}

void odd4( int& aa, int& bb ){				// Call by reference
	int ansr = (aa + bb) / 2;    			// See diagram 3.
	cout << "\nIn odd4, average of " <<aa <<", " <<bb <<" = " <<ansr <<endl; 
	++aa;  ++bb;							// increment two integers in main.
}
