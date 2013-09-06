//===========================================================================
// Class declarations for StringStore and Pool.                
// A. Fischer, June 4, 2000                                 file: sstore.hpp
#ifndef SSTORE
#define SSTORE

#include "tools.hpp"
#define MAXLETS	 1000	// Pool size.
//===========================================================================
class Pool {
  friend class StringStore;
  private:	    
    char  Letters[MAXLETS];	// Memory behind stringarray.
    Pool* Prev;		        // Previous StringStore, for deallocation.

    Pool( Pool* pv = NULL ) { Prev = pv; }
	~Pool(){}
};

//===========================================================================
class StringStore { 
  private:
    Pool* Current;	// Pool that is currently being filled.
    int Remain;		// Space remaining in current Pool.
    int Next;		// Subscript of next available slot.

  public:			//-------------------------------------------------
    StringStore( int sz = MAXLETS ): Current(new Pool), Remain(sz), Next(0) {}
    ~StringStore();
    char* put( const char* s, int len );
};
#endif
