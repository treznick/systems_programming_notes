//===========================================================================
// Exception Classes for Playing Card Errors.                   file: bad.hpp
// Exception demonstration program:  March 2009
// ----------------------------------------------- Error reading input stream.
#pragma once;
#include "tools.hpp"

class Bad {
public:
    char spot;
    char suit;
    //---------------------------------------------- Suit and Spot both wrong.
    Bad (char n, char s) : spot(n),  suit(s) {};
    virtual void print(){
        cerr <<"  Both spot value and suit are wrong\n"
        <<"  Legal spot values are 2..9, T, J, Q, K, A\n" 
        <<"  Legal suits are H D C S\n";
        pr();
    }    
    void pr(){
        cerr <<"  You entered "<<spot <<" of " <<suit 
        <<". Please reenter. \n";        
    }    
};

// --------------------------------------------------- Only the suit is wrong.
class  BadSuit : public Bad {
public:
    BadSuit (char n, char s) : Bad(n, s) {}
    virtual void print(){
        cerr <<"  Legal suits are H D C S\n";
        pr();
    }    
};

//---------------------------------------------- Only the spot value is wrong.
class  BadSpot : public Bad {
public:
    BadSpot (char n, char s) : Bad(n, s) {}
    virtual void print(){
        cerr <<"  Legal spot values are 2..9, T, J, Q, K, A\n";
        pr();
    }    
};
