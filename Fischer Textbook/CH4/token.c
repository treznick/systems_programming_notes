// =============================================================================
// Project: Bracket-matching example of stack usage                File: token.c 
// =============================================================================
#include "token.h"

Token classify( char ch )
{
	static const string brackets = "[](){}<>";
	Token tok;
	tok.ch = ch;
	
	char* p = strchr( brackets, ch );  
	if (p==NULL) {
		tok.typ = BKT_NONE;
		tok.sense = SENSE_LEFT;	         // arbitrary value
	}
	else {
		int pos = p-brackets;            // pointer difference gives subscript.
		tok.sense = (pos%2 == 0) ? SENSE_LEFT : SENSE_RIGHT;
		tok.typ = (pos/2);               // integer arithmetic, with truncation.
	}
	return tok;
}
