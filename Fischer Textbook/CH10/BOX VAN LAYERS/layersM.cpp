//--------------------------------------------------------------------------------
// Layered construction and destruction example.
// A. Fischer October 10, 2000                                   file: layersM.cpp 
//--------------------------------------------------------------------------------
#include "tools.hpp"
#include "layers.hpp"
//--------------------------------------------------------------------------------
int main( void ) {
	cout << "Creating an object of class Layers. ";
	Layers f1( "PackRat" ); 
    f1.print(cout);
    // Layers f2(f1);        // A call on the copy constructor.
	bye();
}
