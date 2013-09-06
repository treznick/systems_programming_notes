//--------------------------------------------------------------------------
// Class declaration for a flexible array of base type char.                
// A. Fischer, February 7, 2003                         file: flexChars.hpp
#ifndef FLEXC
#define FLEXC
#include "tools.hpp"
#define CHARS_START 4		// Default length for initial array.

class FlexChars {
  private: // --------------------------------------------------------------
	int Max;        // Current allocation size.
    int N;          // Number of array slots that contain data.
    char* Data;     // Pointer to dynamic array of char.
	void grow();    // Double the allocation length.

  public: // ---------------------------------------------------------------
    FlexChars( int ss = CHARS_START ) {
		Max = ss;				 // Current allocation length
		N = 0;					 // Number of data items stored in array.
		Data = new char[Max];	 // An array to contain objects of type char.
	} 
    ~FlexChars() { if (Data != NULL) delete[] Data; }

	void inputLine( istream& ins );
    int	 put( char data );  	 // Store data and return the subscript.
	char& operator[]( int k );

	int	 length() { return N; }  // Provide read-only access to array length.	
    const char* message() { return Data; }  // Read-only access to the chars. 
	
	ostream& print(ostream& out) { // Print the filled part, ignore the rest.
		Data[N] = '\0';
		return out <<Data;
	}
};
inline ostream& operator<< (ostream& out, FlexChars& F){ return F.print( out ); }
#endif
