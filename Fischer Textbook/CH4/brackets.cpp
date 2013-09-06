// ============================================================================
// Name: Bracket-matching example of stack usage             File: brackets.cpp
// ============================================================================
#include "brackets.hpp"
//-----------------------------------------------------------------------------
void Brackets::
analyze( istream& in)
{
    char ch;
    
    for (;;) {                  // Read and process the file.
        in.get(ch);             // This does not skip leading whitespace.
        if ( in.eof() ) break;  
        if (ch == '\n') lineno ++;
        Token curtok( ch );
        if (curtok.getType() == BKT_NONE) continue;	// skip non-bracket characters
        
        switch (curtok.getSense()) {
            case SENSE_LEFT:
                stk->push(curtok);
                break;
                
            case SENSE_RIGHT:
                if (stk->empty()) 
                    mismatch("Too many right brackets", curtok, false);
                toptok = stk->peek();
                if (toptok.getType() != curtok.getType())
                    mismatch("Closing bracket has wrong type", curtok, false);
                stk->pop();
                break;
        }
    }
    if ( stk->empty())
        cout <<"The brackets in this file are properly nested and matched.\n";
    else
        mismatch("Too many left brackets", toptok, true);
}

//-----------------------------------------------------------------------------
void Brackets:: 
mismatch( cstring msg, Token tok, bool eofile )
{
    if (eofile) cout <<"\nMismatch at end of file: " <<msg <<endl;
    else        cout <<"\nMismatch on line " <<lineno <<" : " <<msg <<endl;
    
    stk->print( cout );         // print stack contents
    if (!eofile)                // print current token, if any
        cout <<"The current mismatching bracket is " << tok;
    
    fatal("\n");                // Call  exit.
}
