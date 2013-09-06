//==========================================================================
// Using a FlexChars of characters.                
// A. Fischer, May 4, 2002             		             file: flex_test.cpp
//
#include "tools.hpp" 
#include "flexChars.hpp"
//--------------------------------------------------------------------------
int main( void ) 
{ 
    banner();
	FlexChars sentence;	// A FlexChars of 20 chars.

	cout <<"\nFlexible Array Demo Program \nEnter a long sentence:\n";
    // Read an entire line of text; the buffer will grow when necessary.
	sentence.inputLine( cin );

	// End of input phase -- ready for output.
	cout <<"\nSentence length is " <<sentence.length() <<endl;
	cout << sentence.message() <<endl;	// Print an ordinary string.
}           
