//===========================================================================
// 	A playing card class and related exception classes.	
//	Alice E. Fischer, June 16, 1998                                 cards.hpp
//===========================================================================
#pragma once;
#include "tools.hpp"
#include "bad.hpp"

enum SuitType{ spades, hearts, diamonds, clubs, bad };

//===========================================================================
// This is the main data class; it represents one playing card.
//
class  Card {
    int 	 	spot_;
    SuitType 	suit_;
public:
    Card (istream& sin) throw (BadInput, BadSpot, BadSuit);
    int			spot(){ return spot_; }
    SuitType	suit(){ return suit_; }
    ostream& 	print(ostream&);
};
