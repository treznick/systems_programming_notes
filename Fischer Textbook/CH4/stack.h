// =============================================================================
// Project: Bracket-matching example of stack usage                File: stack.h 
// =============================================================================
#ifndef STACK_H 
#define STACK_H

#include "tools.h"
#include "token.h"
 
#define INIT_DEPTH 10           // initial stack size
typedef Token T;
/*-------------------------------------------- Type definition for stack of T */
typedef struct {
  	int max;    	/* Number of slots in stack.  */
  	int top;		/* Stack cursor.              */
  	T* s;			/* Beginning of stack.	      */
	string name;	/* Internal label, used to make output clearer. */
} Stack;

/*---------------------------------------------------------------- Prototypes */
void init   ( Stack* St, string label );
void recycle( Stack* St );
void print  ( Stack* St );
void push   ( Stack* St, T c ); 
T    pop    ( Stack* St );
T    peek   ( Stack* St );
bool empty  ( Stack* St ); 
int  size   ( Stack* St );
#endif // STACK_H 