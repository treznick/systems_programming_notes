#include "donut.hpp"
// ------------------------------------------------------------ File:  "donut.cpp"
int main( void )
{
	A aa;	// Data member: x
	C cc;	// Data members: A::x, C::a
	D dd; 	// Data members: A::x, B::a, B::x, C::a, D::f

	cerr <<"Dumping aa\n";  aa.dump();
	cerr <<"Dumping cc\n";  cc.dump();
	cerr <<"Dumping the B part of dd\n";  dynamic_cast<B*>(&dd)->dump();

	// Upward casts. -------------------------------------------------------------------
	B* bp = &dd;						// Explicit Low->high pointer cast not needed.  
	B& br = dd;							// Explicit Low->high reference cast not needed.
	cerr <<"Dumping br\n";  br.dump();  // Use the reference variable to dump.
	  
	A* ap = dynamic_cast<A*>(bp);   	// Upward cast IS OK if derivation is public. 
	cerr <<"Dumping ap\n";  ap->dump();	// Show result of dynamic cast.
	//dynamic_cast<A*>(&cc)->dump(); 	// Upward cast NOT OK if derivation is private.
	
	// Downward casts. -----------------------------------------------------------------
	//D* dp = dynamic_cast<D*>(bp);     // Error: Cannot dynamic_cast downward.
}
