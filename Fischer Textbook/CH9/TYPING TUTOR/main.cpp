//===========================================================================
// HashTable, FlexArray, and StringStore Demo Program 
// A. Fischer, February 7, 2003						  	 file: Tutor/main.cpp
//===========================================================================
#include "tools.hpp"
#include "dictionary.hpp"

int main ( int argc, char* argv[] )
{
    cout <<"Typing Tutor\n------------\n";
	if (argc < 2) fatal( "Usage: tutor input_file");    
	Dictionary Dic( argv[1] );	// Create dictionary from words in the input file.	
	cout << "\n\nReady for typing practice? "
		 << "At each prompt, type one of the words shown above.";
	
	int k, right = 0;			// Prompt for a word 10 times and count correct entries.
	for (k=0; k<10; ++k) {
		FlexChars buf;			// Allocate a new flexible char array for the input.
		cout << "\n> "; 				
		buf.inputLine( cin );   // A flexible buffer has no fixed maximum length. 
		if ( Dic.find(buf.message()) ) { 	// Is input in dictionary?
			cout << "\t Correct!";	
			++right;						// Keep score.
		}	
		else { 
			cout <<"\t " << buf <<" is wrong."; 
		}
	}
	cout << "\nYou typed "<<right <<" words correctly, out of 10";
    return 0;
}
