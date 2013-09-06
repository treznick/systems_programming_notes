#include "Part.hpp"

//---------------------------------------------------------------------
int main( void )  
{
	Part inventory[N];
	ifstream instr( "parts.in" );
	if ( !instr )  fatal( "Cannot open parts file %s", "parts.in" );

	cerr << "\nReading inventory from parts input file.\n";
	int n = get_parts( instr, inventory );                // Bad style!
	instr.close();

	cerr <<n <<" parts read successfully.\n\n";
	print_parts( cout, inventory, n );
	bye();
}

