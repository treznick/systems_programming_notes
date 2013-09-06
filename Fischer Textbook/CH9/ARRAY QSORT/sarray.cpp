//===========================================================================
// Implementation of StringArray: an array of words using a StringStore.                
// A. Fischer, February 8, 2003                              file: sarray.cpp

#include "sarray.hpp"
// -------------------------------------------------------------------------- 
StringArray::StringArray( istream& sin )
{											 
	Many = 0;		            // Array is empty; the first available slot is [0].
	const char* word;
	for (;;) {
		FlexChars buf;			// Allocate a new flexible char array for the input.
		buf.inputLine( sin );   // A flexible buffer has no fixed maximum length. 
		if ( sin.eof() ) break;
		word = buf.message();
		if ( word[0] != '\0') {
			Words[Many++] = Letters.put( word, buf.length() );
			//cout << "\n> " << word <<"\n"; 				
		}
	}
}			

// --------------------------------------------------------------------------
void StringArray::print( ostream& outs ) const 
{
    for (int k=0; k<Many; k++) cout << Words[k] << endl; 
}
