// ============================================================================
// Name: Bracket-matching example of stack usage             File: brackets.hpp
// ============================================================================
#ifndef BRACKETS_H
#define BRACKETS_H

#include "tools.hpp"
#include "token.hpp"
#include "stack.hpp"

class Brackets {
  private:
    Stack* stk;
    Token toptok;
    int lineno;

  public:
    Brackets() {
        stk = new Stack( "brackets" );
        lineno = 1;
    }
    ~Brackets(){ delete stk; }
    
    void analyze( istream& in);   // Check bracket nesting and matching in file.
    void mismatch( cstring msg, Token tok, bool eofile );      // Handle errors.
};
#endif