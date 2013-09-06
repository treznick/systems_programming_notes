// ==========================================================================
// Choose a word, use it to create a playing board.
// A. Fischer, June 4, 2000                                   file: board.hpp
#ifndef BOARD
#define BOARD

#include "words_d.hpp"
#define HANG_MAX 7
// ==========================================================================
class Board {
    enum status {GOOD_GUESS, BAD_GUESS, NOT_IN_ALPHA, USED_ALREADY};
    int Errcnt;			// Wrong guesses so far,
    int Found;			// Number of Letters correctly filled in.
    Alphabet Alpha;		// Masked alphabet.
    Alphabet Errors;	// Masked alphabet for error list.
	HangWord Puzzle;	// Masked mystery word.

  public:
    Board(const char* a, const char* puz);	// Alphabet and puzzle word. 
	~Board(){}
    int play();								// play a board
    void move();							// user interaction for one move
    status guess(char c);					// process a guess
    ostream& print(ostream&);	    		// print a board
};
#endif
