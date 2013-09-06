//============================================================================
// StringStore data structure -- implementation.
// A. Fischer, May 29, 2000                                  file: sstore.cpp

#include "sstore.hpp"
//----------------------------------------------------------------------------
StringStore::~StringStore() {
    Pool* p;
	while (Current != NULL) {
	  p = Current;
	  Current = p->Prev;
	  delete p;
	}
}

//----------------------------------------------------------------------------
char* 
StringStore::put( char* s, int len ) {
	char* where;
	len++;							// number of characters including '\0'.
	if ( len > Remain ) {   		// no room to store s in current Pool.
		Current = new Pool( Current );
		Next = 0;
		Remain = MAXLETS;
	}
	where = &Current->Letters[Next];
	Next += len;
	Remain -= len;
	strcpy( where, s );
	return where;
}
