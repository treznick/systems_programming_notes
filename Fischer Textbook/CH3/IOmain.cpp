//--------------------------------------------------------------------------------
// C++ demonstration program for end of file and error handling.  
// A. Fischer, April 2001 	           	   			              file: IOmain.cpp
#include "tools.hpp"
#include "getline.cpp"

int main( int argc, char* argv[] )  
{	
	banner();    
	// Command line must give the name of the program followed by 2 file names.
	if (argc < 3)  fatal( "Usage: eof_demo textfile numberfile" );

	ifstream alpha_stream( argv[1] );
	if (! alpha_stream)  fatal( "Cannot open text file %s", argv[1] );
	ifstream num_stream( argv[2] );
	if (! num_stream)  fatal( "Cannot open numeric file %s", argv[2] );

 	cout <<"\nIOstream flags are printed after each read in order:\n"
         <<"goodbit : eofbit : failbit : badbit :\n";

	use_get( alpha_stream );
	
    alpha_stream.close();					// Close file.
    ifstream new_stream ( argv[1] );	// Re-open the file to use it again.
	if (! new_stream)  fatal( "Cannot open text file %s", argv[1] );
	
    use_getline( new_stream );
    use_nums( num_stream );
}
