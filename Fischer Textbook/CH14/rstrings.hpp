// ==========================================================================
// Declaration for a string array with random selection
// A. Fischer, May 13, 2001                                file: rstrings.hpp

#include "flexT.hpp"
#include "sstore.hpp"
// ==========================================================================
class RandString : public FlexArray<char*> {
  protected:
	StringStore Store;					// Storage behind string array.

  private:
    inline cstring remove( int r );
	void print( ostream& outs ) const;	// For debugging, make this public.

  public:
	RandString( istream& vocin, int sz = 100 );
	~RandString(){}
    const char* randword();
	const char* operator[] ( int index );
};
