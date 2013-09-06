//==============================================================================
// Project: Bracket-matching example of stack usage               File: main.cpp
// Author:  Michael and Alice Fischer                    Copyright: January 2009
// =============================================================================
#include "tools.hpp"    
#include "brackets.hpp"

//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    banner();
    say("Welcome to the bracket checker!");
    
    if (argc!=2) fatal("usage: %s file", argv[0]);
    say("Checking file '%s'", argv[1]);
    
    ifstream in( argv[1] );
    if (! in ) fatal("can't open file '%s' for reading", argv[1]);
    
    Brackets b;             // Declare and initialize the application class.
    b.analyze( in );        // Execute the primary application function.
    in.close();
    bye();
}