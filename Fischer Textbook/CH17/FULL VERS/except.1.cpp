//==============================================================================
// 	Exception handling demonstration.	
//	Alice E. Fischer, June 16, 1998                                   except.cpp
//==============================================================================
#include "tools.hpp"
#include "cards.hpp"
#include "bad.hpp"
#define NCARDS 3

int main(void)
{
 	Card* hand[NCARDS];
	int k;
    bool success;
	cout << "Please enter " << NCARDS << " cards.\n"
		 << "Spot codes are 2..9, T, J, Q, K, A \n"
	     << "Suit codes are S H D C \n\n";
	//------------------------------------------ Main loop that reads all cards.
	for (k=0; k<NCARDS; ){				
		success = true;
		cout << "Enter a card (spot code, suit code): " ;
		//------------------------------ Here is the single line of active code.
 		try {			     			
			hand[k] = new Card(cin);	//---------------------- Input one card.
		} 
		//----------------- Check for the three application-specific exceptions.
 		catch (const BadSpot& bs) {		
			cerr <<"You entered "<<bs.spot <<" of " <<bs.suit 
                 <<". Please reenter. \n";
			success=false;
		}
		catch (const BadSuit& bs) {		//------- Check specific problems first.
			cerr <<"You entered "<<bs.spot <<" of " <<bs.suit 
                 <<". Please reenter. \n";
			success=false;
		}
    	catch (const BadInput& bs) {	//---------- Check general problem last.
       		success=false;
			cerr << "Read error on input stream; try again\n";
			cin.clear();
			cin.ignore(100, '\n');
         	// throw bs;  				// -This command would kill the program.
        }
		//------------------- Now check for general exceptions thrown by system.
 		catch (bad_alloc bs) {			//-------------- Catch a malloc failure.
			cerr << "Allocation error for card #" <<k <<".\n";
			return 1;
		}
		catch (...) {					//--------------- Catch everything else.
			success=false;
			cerr << "Last-ditch effort to catch exceptions.\n";
		}
        // ----------------- Control comes here after the try/catch is finished.
		// ---- When a constructor throws an exception, the destructor should be   
		if(!success) {                 // called to delete the half-made object. 
            delete hand[k];  
		}
		// ----------------- Code that relies on having a valid input goes here.
		else{ 					  
		   	cout << "Card successfully entered into hand: ";
		   	hand[k]->print(cout);
			++k;
		}
	}	
	cout << "\nHand is complete:" << endl;
	for (k = 0; k < NCARDS; ++k) { hand[k]->print( cout ); }
}
