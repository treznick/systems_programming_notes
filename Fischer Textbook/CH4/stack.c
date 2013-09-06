// =============================================================================
// Project: Bracket-matching example of stack usage                File: stack.c 
// =============================================================================
#include "stack.h"
// -------------------------------------------------- the constructor 
void init( Stack* St, string label )  {
	St->s = malloc( INIT_DEPTH * sizeof(T) );
	St->max = INIT_DEPTH;
	St->top = 0;
	St->name = label; 
}

// --------------------------------------------------- the destructor 
void recycle(Stack* St){ free(St->s);  say( "\tdeleting %s", St->name); }

// -------------------------------------------------------------------
// ***** the printf statement must be modified for base type != Token  
void print( Stack* St )         // Print contents of stack, formatted. 
{	T* p = St->s;               // Scanner & end pointer for data. 
	T* pend = p + St->top;

	printf( "The stack '%s' contains: Bottom~~ ", St->name );
	for ( ;  p < pend;  ++p)  printf( " %c", p->ch ); 
  	printf( " ~~Top" );
}

// ---------------------------------------------- the Stack functions 
void push( Stack* St, T c )  
{ 
	if (St->top == St->max) { 	// If stack is full, allocate more space.
		say( "-Doubling stack length-" );		
		St->max*=2;
		St->s = realloc( St->s, St->max * sizeof(char) );
	}
	St->s[St->top++] = c;       // Store data in array, prepare for next push.
} 

// -------------------------------------------------------------------
T    pop( Stack* St )	{ return St->s[-- St->top]; }
T    peek( Stack* St )	{ return St->s[St->top-1]; } 
bool empty( Stack* St ) { return ( St->top == 0 ); } 
int  size( Stack* St )  { return St->top; }
