// ==========================================================================
// Maskable word base class. 
// A. Fischer, June 4, 2000 					              file: words.hpp
#ifndef WORDS
#define WORDS
#include "tools.hpp"
// ==========================================================================
class BaseWord {
  protected:
    const int Len;		// length of word, excluding terminator.
    const char* const W;	// partially concealed word
    bool* const Mask;		// concealment mask

  public:
	BaseWord(const char* st) : Len(strlen(st)), W(st), Mask(new bool[Len+1]){
	 	//cerr << "\nConstructing BaseWord.  "; 
	}
	~BaseWord() { delete [] Mask; }
    int length() const { return Len; }
    bool& mask_slot(int k) const { return Mask[k]; }
    const char* const word() const { return W; }

    void set_all(bool on_off){	// set false to hide letter, true to expose.
		for (int k=0; k<Len; k++) Mask[k] = on_off; 
	}
};
#endif
