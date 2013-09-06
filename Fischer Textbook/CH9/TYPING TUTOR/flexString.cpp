//--------------------------------------------------------------------------
// Implementation of the FlexString class.                
// A. Fischer, A. Fischer, February 7, 2003             file: flexString.cpp

#include "flexString.hpp" 
int //------------------------- search for the word in the dictionary array.
FlexString::find( const char* word) {
	int k;
	//cerr <<"    Looking for " <<word <<"  " <<"N is " <<N <<"  ";
	for (k=0; k<N; ++k) {
		//cerr <<Data[k] <<"  ";
		if (strcmp( word, Data[k] ) == 0) break;
	}
	return (k < N) ? k : -1;
}

int // --------------------------------- Copy a char* into the FlexString.
FlexString::put( char* data ) {
    if ( N == Max ) grow();	   // Create more space if necessary.
	//cerr <<"Putting " <<data <<" into bucket " <<N <<endl;
    Data[N] = data;
	return N++;				   // Return subscript at which item was stored.
}

char*& //------------------------------- Access the kth string in the array.
FlexString::operator[]( int k ) {
    if ( k >= N ) fatal("Flex_array bounds error.");
    return Data[k];				  // Return reference to desired array slot.
}

void  // ------------------------------------- Double the allocation length.
FlexString::grow() {
	handle temp = Data;						// hang onto old data array.
	Max>0 ? Max*=2 : Max = STRINGS_START;
	Data = new char*[Max];				    // allocate a bigger one.
	memcpy(Data, temp, N*sizeof(char*));	// copy info into new array.
	delete temp;							// recycle (free) old array.
				// but do not free the things that were contained in it.
}
