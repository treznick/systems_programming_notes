// ======================================================================
// Hangman program:    Let the user guess words from the vocabulary file.
// A. Fischer, May 13, 2001                                file: main.cpp
#include "tools.hpp" 
#include "game.hpp"
//-----------------------------------------------------------------------
int main( int argc, char* argv[] ) 
{
    char response;				// For query, "Play again?"
    int wins = 0, rounds = 0;	// For keeping score.
    const char* timeword;		// For grammatical output: time, times.
    const char* tryword;		// For grammatical output: try, tries.
 
    cout << "\n--------- Constructing Hangman ----------\n";
    Game g( argc>1 ? argv[1] : NULL );  	// Get optional file name. 
 
    cout << "\n---------- Welcome to Hangman ----------\n"
            "You win if you can guess the hidden word.\n"
            "You lose if you guess " << HANG_MAX << " wrong letters.\n";
    do {
		wins += g.play();					// Play one round of game.
		rounds++;
		timeword = (wins == 1) ? "time" : "times";
		tryword = (rounds == 1) ? "try" : "tries";
		cout << "\nYou won " << wins << " " << timeword 
	         << " out of " << rounds << " " << tryword 
             << ".\n\nType p to play another round, q to quit: ";
		cin >> response;
    } while (tolower(response) == 'p');
    cout << "\n----------- Have a good day! -----------\n\n";
}
