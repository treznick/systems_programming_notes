//===========================================================================
// Class declaration for StringArray: an array of words using a StringStore.                
// A. Fischer, October 3, 2000                               file: sarray.hpp
//
#ifndef SARRAY
#define SARRAY

#include "flexChars.hpp"
#include "sstore.hpp"
#include "compare.hpp"
#define MAXWORDS 300			// Limit on number of words in vocabulary.

//---------------------------------------------------------------------------
class StringArray { 
  private:                      //-------------------------------------------
	StringStore Letters;		// Storage behind string array.
	char* Words[MAXWORDS];   	// String array.
	int Many;					// Number of words and first available slot.
  public:						//-------------------------------------------
	StringArray( istream& in );
	~StringArray(){}
	void print( ostream& out ) const;	 
	void sort(){ qsort( Words, Many, sizeof(char*), compare ); }
};
#endif
