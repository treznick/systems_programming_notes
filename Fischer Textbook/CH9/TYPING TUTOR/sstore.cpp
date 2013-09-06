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
StringStore::put( const char* s, int len ) {
	char* where;
	len++;								// number of characters including '\0'.
	if ( len > Remain ) {   			// no room to store s in current Pool.
		Current = new Pool( Current );	// Attach new pool at head of chain.
		Next = 0;						// New pool is empty.
		Remain = MAXLETS;				// All slots are unused.
	}
	where = &Current->Letters[Next];	// Number of characters including '\0'.
	Next += len;						// Move pointer to next empty slot.
	Remain -= len;						// Decrease number of remaining bytes.
	strcpy( where, s );					// Copy the new string into the array.
	//cerr << where <<" ";
	return where;						// First letter of newly stored string.
}
