//--------------------------------------------------------------------------
// Class declaration for a flexible array of base type T.                
// A. Fischer, A. Fischer, February 7, 2003             file: flexString.hpp
#ifndef FLEXS
#define FLEXS
#include "tools.hpp"
#define STRINGS_START 20	// Default length for initial array.
typedef char** handle ;

class FlexString {
  private: // --------------------------------------------------------------
	int Max;  				// Current allocation size.
    int N;	  				// Number of array slots that contain data.
    handle Data;		    // Pointer to dynamic array of char*.
	void grow(); 			// Double the allocation length.

  public: // ---------------------------------------------------------------
    FlexString( int ss = STRINGS_START ): Max(ss), N(0), Data(new char* [Max]){} 
    ~FlexString() { if (Data != NULL) delete[] Data; }
	
	int put( char* data );    		// Store data and return the subscript.
	int	length() { return N; }      // Provide read-only access to array length.	
	
    char*& operator[]( int k );     // Extend subscript operator for new class.
	int find( const char* );		// Return subscript of argument, if found.
    handle extract();				// Convert a flex-array to a normal array. 
	
	ostream& print(ostream& out) {		// Print the filled part, ignore the rest.
		for (int k=0; k<N; ++k) out <<Data[k] <<endl;
		return out;
	}
};
inline ostream& operator <<( ostream& out, FlexString F ){ return F.print(out); }
#endif
