// ==========================================================================
// Implementation for maskable words.
// A. Fischer, June 4, 2000                                 file: words_d.cpp

#include "tools.hpp"
#include "words_d.hpp"
// ================================================= Alphabet class functions 
int								// Return index of first occurrence of c in W					
Alphabet::find(char c) const {
    int k;
    for (k=0; k<Len && c != W[k]; k++);		// Loop body is empty.
    return (k==Len) ? -1 : k;
}
//---------------------------------------------------------------------------
ostream& 
Alphabet::print (ostream& out) {
    for (int k=0; k < Len; k++)  if ( Mask[k] ) out << " " << W[k];
    return out;
}

// ================================================= Hangword class functions 
int		  // Count the number of times letter c occurs in puzzle; unmask each 
HangWord::try_letter(char c) {
    int count = 0;
    for (int k=0; k<Len; k++) {
		if (c == W[k]) {
		    count++;
		    Mask[k] = true;
		}
    }
    return count;
}
//---------------------------------------------------------------------------
ostream& 
HangWord::print (ostream& out) {
    out << "<[" ;
    for (int k=0; k < Len; k++) out  << ' ' << (Mask[k] ? W[k] : '_') ;
    out << " ]>";
    return out;
}
