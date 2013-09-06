//-----------------------------------------------------------------------
// Three odd average functions.							   file: odds.hpp 
//-----------------------------------------------------------------------
#ifndef ODDS
#define ODDS
#include <iostream>
using namespace std;

void odd1( int aa, int bb );				// Call by value.
void odd2( int* aa, int* bb );				// Call by address or pointer.
void odd4( int& aa, int& bb );				// Call by reference
#endif