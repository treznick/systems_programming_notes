// ==========================================================================
// board.cpp: Implementation for hangman board
// A. Fischer, June 4, 2000                                  file: board.cpp

#include "board.hpp"
// ==========================================================================
Board::Board(const char* a, const char* puz) : 
    Errcnt(0), Found(0), Alpha(a, true), Errors(a, false), Puzzle(puz){ 
	//cerr << "\nConstructing Board.  "; 
}

//--------------------------------------------------------- display the board
ostream& 
Board::print( ostream& out ) {
    out << "\n\nPuzzle is: " << Puzzle << "\n\n";
    out << "    Letters left-->" << Alpha << "\n";
    out << "    Bad guesses--->" << Errors;

    for (int k = Errcnt; k < HANG_MAX; k++) out << " _";
    return out << endl;
}

//----------------------------------------------------------- process a guess
Board::status 
Board::guess(char c) {
    int where = Alpha.find(c);
    if (where == -1) return NOT_IN_ALPHA;
    if ( !Alpha.mask_slot(where) ) return USED_ALREADY;
    Alpha.mask_slot(where) = false;

    int matches = Puzzle.try_letter(c);
    if (matches <= 0) {
		Errors.mask_slot(where) = true;
		Errcnt++;
		return BAD_GUESS;
    }
    Found += matches;
    return GOOD_GUESS;
}

//--------------------------------------------- user interaction for one move 
void
Board::move() {
    char ch;
    cout << "Guess a letter: ";
    cin >> ch;
    cout << "You guessed '" << ch << "'";
    switch (guess( ch )) {
       case NOT_IN_ALPHA:
			cout << " -- but it's not in the alphabet." << endl;    break;
       case USED_ALREADY:
			cout << " -- but you guessed it once before." << endl;	break;
       case BAD_GUESS:
			cout << " -- too bad." << endl;							break;
       case GOOD_GUESS:
			cout << ".  You scored!" << endl;						break;
    }
    print(cout);
}

//-------------------------------------------------------------- play a board
int  														 
Board::play() {   
    print(cout);
    while (Errcnt < HANG_MAX && Found < Puzzle.length()) move();
    if (Found == Puzzle.length()) {
		cout << "Congratulations -- you win!" << endl;
		return 1;
    }
    cout << "Sorry, you lose!" << "\nThe answer is: " 
         << Puzzle.word() << endl;
    return 0;
}
