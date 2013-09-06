//==============================================================================
// 	Exception handling demonstration.	
//	Alice E. Fischer, June 16, 1998                                   except.cpp
//==============================================================================
#include "tools.hpp"
#include "cards.hpp"
#include "bad.hpp"
#define NCARDS 3

int main( void )
{
 	Card* hand[NCARDS];
	int k;
    bool success;
    Card::instructions( cout, NCARDS );
	//------------------------------------------ Main loop that reads all cards.
	for (k=0; k<NCARDS; ){				
		success = false;         // Will not be changed if an exception happens.
		//------------------------------ Here is the single line of active code.
 		try {			     			
            cout << "\nEnter a card (spot code, suit code): " ;
			hand[k] = new Card(cin);	//---------------------- Input one card.
            success = true;             //-- No exception - we have a good card.
		   	cout << "  Card successfully entered into hand: ";
		   	hand[k]->print(cout);
			++k;
		} 
		//----------------- Check for the three application-specific exceptions.
 		catch (Bad& bs) { bs.print(); }          // Will catch all 3 Bad errors.

		//------------------- Now check for general exceptions thrown by system.
 		catch (bad_alloc bs) {			//-------------- Catch a malloc failure.
			cerr << "  Allocation error for card #" <<k <<".\n";
			return 1;
		}
		catch (...) {					//--------------- Catch everything else.
			cerr << "  Last-ditch effort to catch exceptions.\n";
		}
        // ----------------- Control comes here after the try/catch is finished.
		if(!success) delete hand[k];       // ----- Delete the half-made object. 
	}	
	cout << "\nHand is complete:" << endl;
	for (k = 0; k < NCARDS; ++k) { hand[k]->print( cout ); }
}
