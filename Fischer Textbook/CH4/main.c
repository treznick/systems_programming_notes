// =============================================================================
// Project: Bracket-matching example of stack usage                 File: main.c
// Author:  Michael and Alice Fischer                    Copyright: January 2009
// =============================================================================
#include "tools.h"
#include "token.h"
#include "stack.h"

void analyze( stream in );
void mismatch( string msg, int lineno, Stack* stkp, Token* tokp );

//-----------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
	banner();
	say("Welcome to the bracket checker!");
	
	if (argc!=2) fatal( "usage: %s file", argv[0] );
	say( "Checking file '%s'", argv[1] );
    
	stream instream = fopen( argv[1], "r" );
	if (instream==NULL) fatal( "can't open file '%s' for reading", argv[1] );
    
    analyze( instream );
    fclose( instream );
	bye();
}

//-----------------------------------------------------------------------------
void analyze( stream in )
{
    char ch;
    Token curtok;
    Token toptok;
    Stack stk;
    int lineno = 1;             // Number of lines of text in the  input file.
    
    init( &stk, "bracket stack" );
    
    for(;;){                    // Read and process each character in the file.
        ch = getc(in);
        if (feof( in )) break;
        if (ch == '\n') lineno ++;
        curtok = classify(ch);
        if (curtok.typ == BKT_NONE) continue;	// skip non-bracket characters
        switch (curtok.sense) {
            case SENSE_LEFT:
                push(&stk, curtok);
                break;
                
            case SENSE_RIGHT:
                if (empty(&stk)) 
                    mismatch("Too many right brackets", lineno, &stk, &curtok);
                toptok = peek(&stk);
                if (toptok.typ != curtok.typ)
                    mismatch("Closing bracket has wrong type", lineno, &stk, &curtok);
                pop(&stk);
                break;
        }
    }
    
    if (!empty( &stk )) mismatch("Too many left brackets", lineno, &stk, NULL);
    else printf("The brackets in this file are properly nested and matched.\n");
    recycle( &stk );
}

//-----------------------------------------------------------------------------
void mismatch(string msg, int lineno, Stack* stkp, Token* tokp )
{
    if (tokp == NULL)  printf("Mismatch at end of file: %s\n", msg);
    else  printf("Mismatch on line %d: %s\n", lineno, msg);
    
    print( stkp ); printf( "\n\n" );        // print stack contents
    if (tokp != NULL)                       // print current token, if any
        printf("The current mismatching bracket is '%c'\n\n", tokp->ch );
    
    exit(1);                                // abort further processing
}
