//===========================================================================
// 	Functions and constants for the Card class.	
//	Alice E. Fischer, June 16, 1998                                 cards.cpp
//===========================================================================
#include "cards.hpp"
const char* suitlabels[5] = {"spades", "hearts", "diamonds", "clubs", "bad"};

const char* spotlabels[16] = {
	"bad","Ace","2","3","4","5","6","7","8","9",
	"10","Jack","Queen","King","Ace" 
};

// --------------------------------------------------------------------------
Card::Card (istream& sin) throw (BadInput, BadSpot, BadSuit) {
	char inspot, insuit;
	sin >> inspot >> insuit;
	if (!sin.good()) throw BadInput(inspot, insuit);
	if (inspot >='2' && inspot<='9') spot_ = inspot - '0';
	else switch( toupper(inspot) ){
        case 'T': spot_ = 10; break;
        case 'J': spot_ = 11; break;
        case 'Q': spot_ = 12; break;
        case 'K': spot_ = 13; break;
        case 'A': spot_ = 1; break;
        default : spot_ = 0;  	
	};
	switch( toupper(insuit) ){
		case 'S': suit_ = spades; 	break;
		case 'H': suit_ = hearts; 	break;
		case 'D': suit_ = diamonds; break;
		case 'C': suit_ = clubs; 	break;
		default : suit_ = bad; 	
	};
	if (spot_ == 0 && suit_ == bad) throw BadInput(inspot, insuit);
	if (spot_ == 0) throw BadSpot(inspot, insuit);		
	if (suit_ == bad) throw   BadSuit(inspot, insuit);	
}

// --------------------------------------------------------------------------
ostream&
Card::print(ostream& sout) {
	return sout <<spotlabels[spot_] <<" of " <<suitlabels[suit_] <<endl;
}
