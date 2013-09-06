//===========================================================================
// Exception Classes for Playing Card Errors.
// ---------------------------------------------- Error reading input stream.
#pragma once;

class  BadInput {
public:
    char spot;
    char suit;
    BadInput (char n, char s) : spot(n),  suit(s) {};
};

// -------------------------------------------------- Only the suit is wrong.
class  BadSuit : public BadInput {
public:
    BadSuit (char n, char s) : BadInput( n, s ) {};
};

//-------------------------------------------- Only the face value  is wrong.
class  BadSpot : public BadInput {
public:
    BadSpot (char n, char s) : BadInput( n, s ) {};
};
