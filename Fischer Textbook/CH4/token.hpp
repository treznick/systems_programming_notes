// ============================================================================
// Project: Bracket-matching example of stack usage             File: token.hpp
// ============================================================================
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "tools.hpp"

enum BracketType {BKT_SQ, BKT_RND, BKT_CURLY, BKT_ANGLE, BKT_NONE};
enum TokenSense {SENSE_LEFT, SENSE_RIGHT};

class Token {
private:
	BracketType type;
	TokenSense sense;
	char ch; 
    void classify( char ch );
    
public:
    Token( char ch );
    Token(){}
    ~Token(){}
    ostream&    print( ostream& out) { return out << ch; }
    BracketType getType()            { return type; }
    TokenSense  getSense()           { return sense; }
};

inline ostream& operator<<( ostream& out, Token t ) { return t.print( out ); }
#endif // TOKEN_HPP 
