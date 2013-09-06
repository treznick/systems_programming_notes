//===========================================================================
// StringArray, StringStore, and qsort Demo Program 
// A. Fischer, February 8, 2003					    file: ArrayQsort/main.cpp
//===========================================================================
#include "tools.hpp"
#include "sarray.hpp"

int main ( int argc, char* argv[] )
{
    banner();
	if (argc < 2) fatal( "Usage: ArrayQsort input_file");    
	ifstream vocabIn( argv[1] );
	if (!vocabIn) fatal( "\nCould not open file vocab.in" );

	StringArray vocab( vocabIn );
	cout << "\nFile successfully read; ready for sorting.\n\n";
	vocab.sort();
	vocab.print( cout ); 
    return 0;
}
