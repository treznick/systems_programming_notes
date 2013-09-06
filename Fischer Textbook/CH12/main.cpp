//------------------------------------------------------------------------------
// Class Derivation and Static Class Members                      file: main.cpp
// A. Fischer March 2, 2009                                
//------------------------------------------------------------------------------
#include "Pubs.h"
#include "Printed.h"
#include "Book.h"

int Pubs::pubCount = 0;	// Number of Pubs objects that now exist.
int Printed::prinCount = 0;     // Number of Printed objects that now exist.
int Book::bookCount = 0;        // Number of Book objects that now exist.

//------------------------------------------------------------------------
int main( void ) {
	Pubs A("A-Wesley");
	Printed B("Trade Books", "Pearson");
	Book D( "Anatomy", "Out-of-print", "P-Hall" );
	Book G( "Applied C", "Textbook", "McGraw-Hill" );
	cout <<"\nThe population is:\n"<< A << B <<  D << G;
	bye();
    return 0;
}
