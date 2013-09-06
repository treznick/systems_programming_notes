//===========================================================================
// Class for a linked-list row and its cells                
// A. Fischer, October 1, 2000                                  file: row.hpp
//===========================================================================
#ifndef ROW
#define ROW
#include <iostream>
#include "item.hpp"
using namespace std;
//---------------------------------------------------------------------------
class Cell	   // Dependent class.  Holds an Item and points to another Cell.
{
  friend class Row;
  private:					 
	Item* Data;           // Pointer to one data Item    (Aggregation)
    Cell* Next;			  // Pointer to next cell in row (Association)

	Cell (char* d, int s, Cell* nx){ Data = new Item(d, s); Next = nx; }
	~Cell (){ delete Data; cout <<"  Cell " <<"\n"; }              
};

//---------------------------------------------------------------------------
class Row	{	// Interface class for one bar of the bargraph.
  private:
	char Label[10];         	// Row header label
	Cell* Head;         		// Pointer to head of row

  public:
	Row ( int n );
	~Row ();
	void Insert ( char* name, int score );
	ostream& Print ( ostream& os );
};

//---------------------------------------------------------------------------
inline ostream& operator << ( ostream& out, Row& T){ return T.Print( out ); }
#endif
