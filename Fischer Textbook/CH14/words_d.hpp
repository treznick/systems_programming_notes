// ==========================================================================
// Derived Word classes. 
// A. Fischer, June 4, 2000 						        file: words_d.hpp
#ifndef WORDSDERIVED
#define WORDSDERIVED

#include "words.hpp"
// ==========================================================================
class Alphabet : public BaseWord {
  public:
    Alphabet(const char* st, bool on_off) : BaseWord(st) { 
		set_all(on_off); 
		//cerr << "Constructing Alphabet."; 
	}
    int find(char c) const;	    // return index of first c in word
    ostream& print (ostream&);  // print an alphabet
};

inline ostream& operator<<(ostream& out, Alphabet& x){ return x.print(out); }

// ==========================================================================
class HangWord : public BaseWord {
  public:
    HangWord(const char* st) : BaseWord(st) { 
		set_all(false);
		//cerr << "Constructing HangWord. " <<st; 
	}
    int try_letter(char);
    ostream& print (ostream&);  // print a hang word
};

inline ostream& operator<<(ostream& out, HangWord& x){ return x.print(out); }
#endif
