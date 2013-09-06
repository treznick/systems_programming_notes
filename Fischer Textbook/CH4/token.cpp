// ============================================================================
// Name: Bracket-matching example of stack usage             File: token.cpp
// ============================================================================
#include "token.hpp"
//-----------------------------------------------------------------------------
Token::Token( char ch ){
    this->ch = ch;  
    classify( ch );
}

//-----------------------------------------------------------------------------
void Token::
classify( char ch )
{
	static const cstring brackets = "[](){}<>";
	char* p = strchr( brackets, ch );  
	if (p==NULL) {
		type = BKT_NONE;
		sense = SENSE_LEFT;             // arbitrary value
	}
	else {
		int pos = p-brackets;           // pointer difference gives subscript.
		sense = (pos % 2 == 0) ? SENSE_LEFT : SENSE_RIGHT;
		type = (BracketType)(pos/2);    // integer arithmetic, with truncation.
	}
}

