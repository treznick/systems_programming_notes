// ==========================================================================
// Build a board, play it, and return the score to main.
// A. Fischer, June 4, 2000                                    file: game.hpp
#ifndef GAME
#define GAME

#include "rstrings.hpp"
#include "board.hpp"
// ==========================================================================
class Game {
  private:
	char Alphabet[80];		// Normally the English Alphabet.
	RandString* Vocab;		// The randomized vocabulary list.
	
  public:
	Game( cstring wordfile = NULL );
	~Game(){ delete Vocab; }
	int play();				// Play hangman.
};
#endif
