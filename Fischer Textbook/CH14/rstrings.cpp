// ==========================================================================
// Implementation for a string array with random selection
// A. Fischer, June 4, Nov 14, 2000                        file: rstrings.cpp

#include "tools.hpp"
#include "rstrings.hpp"
// ==========================================================================
RandString::RandString( istream& vocin, int sz ) : FlexArray<char*>(sz) {
	//cerr << "\nConstructing RandString  ";
	char line[80];						// input buffer
	srand( time( NULL ) );				// start up random number generator.	

	for(;;) { 
		vocin >> ws;
		vocin.getline( line, 80 );
		if (!vocin.good()) break;
 		put( Store.put(line, vocin.gcount())); // Add to SStore & FlexArray.
	}
	//cerr << "\nRead " <<Many <<" Data from vocabulary file " << endl;
	if ( !vocin.eof() ) fatal( "Read error on vocabulary file" );
}
// -------------------------------------------------------------------------
void 
RandString::print( ostream& outs ) const {
	outs << "The vocabulary: \n";
    for (int k=0; k<N; k++) outs << Data[k] << endl; 
}

// -------------------------------------------------------------------------
const char*  
RandString::randword() {
	if (N < 1) fatal( "Sorry, out of Data!"); 
    int r = rand(); 
    return remove( r % N );
}

//---------------------------------------------------------------------------
inline cstring 
RandString::remove( int r ) {
    cstring ret = Data[r];		// Grab the word that was selected.
    Data[r] = Data[--N];		// Replace by last word in array.
    return ret;					// Return word and decrease word count.
}

// -------------------------------------------------------------------------
const char* 			// Override; block access to function in base class.
RandString::operator[] ( int index ) 
{ 
	cerr <<"No random access to vocabulary list";
	return "";
} 
