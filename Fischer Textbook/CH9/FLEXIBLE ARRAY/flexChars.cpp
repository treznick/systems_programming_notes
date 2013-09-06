//-------------------------------------------------------------------------------------
// Implementation of the FlexChars class.                
// A. Fischer, February 7, 2003                                     file: flexChars.cpp

#include "flexChars.hpp" 
void  FlexChars ::   // ------------------- Read and return one line from input stream.
inputLine( istream& ins ){			        // Discard prior contents of the buffer.
		char ch;    
		for (N=0; ; ){						// Start with slot 0 of the buffer.
			ins.get( ch );
			if (!ins.good() || ch == '\n') break;  // Go until eof or newline.
			put( ch );						// The put function takes care if itself.
		}
	    put( '\0' );						// Terminate the string in the buffer.
		//cerr <<"Input length = " << N <<endl;
}

char& FlexChars :: //-------------------------------- Access the kth char in the array.
operator[]( int k ) {
    if ( k >= N ) fatal("Flex_array bounds error.");
    return Data[k];				             // Return reference to desired array slot.
}
	
int FlexChars :: // --------------------------------------- Copy a char into the array.
put( char ch ) {
    if ( N == Max ) grow();	   	// Create more space if necessary.
    Data[N] = ch;
	return N++;				   	// Return subscript at which item was stored.
}

void FlexChars :: // ------------------------------------ Double the allocation length.
grow() {
	char* temp = Data;						// hang onto old data array.
	Max>0 ? Max*=2 : Max = CHARS_START;
	Data = new char[Max];					// allocate a bigger one.
	memcpy(Data, temp, N*sizeof(char));	    // copy info into new array.
	delete temp;						    // recycle (free) old array.
			    // but do not free the things that were contained in it.
}
