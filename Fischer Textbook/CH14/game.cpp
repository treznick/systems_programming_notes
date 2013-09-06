// ==========================================================================
// Implementation of the Hangman game.
// A. Fischer, June 4, 2000                                   file: game.cpp

#include "game.hpp"
// ==========================================================================
Game::Game( char* wordfile ){ 
	char file_name[80];  
	//cerr << "Constructing Game.  ";		// For debugging.
    if (wordfile) strcpy( file_name, wordfile );			
 	else strcpy( file_name, "vocab.in" );

	ifstream source( file_name );
	if (!source) fatal( "Could not open %s.\nEnding Hangman.\n", file_name );
	//cerr << "File " <<file_name <<" is open for reading." <<endl;

    source.getline( Alphabet, 80 );
 	Vocab = new RandString( source );		// Create vocabulary database.
    source.close();
	//Vocab->print( cerr );					// For debugging.
}

//---------------------------------------------------------------------------
int Game::play() {
    const char* puzzle_word = Vocab->randword(); 	// pick puzzle word.
	//cerr << puzzle_word; 

    Board b( Alphabet, puzzle_word ); 		 		// construct game board
    return b.play();			   			 		// play the round
}
