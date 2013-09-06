// ============================================================================
// Name: Bracket-matching example of stack usage                File: stack.hpp
// ============================================================================
#ifndef STACK_HPP
#define STACK_HPP

#include "tools.hpp"
#include "token.hpp"

#define INIT_DEPTH 16	// initial stack size
typedef Token T;

//--------------------------------- Type definition for stack of base type T 
class Stack {
private:
  	int max;    	// Number of slots in stack.   
  	int top;		// Stack cursor.               
  	T* s;			// Beginning of stack.	       
	string name;	// Internal label, used to make output clearer.  
    
public:
    //-------------------------------------------------------- Constructors  
    Stack( cstring name ){   
        s = new T[ max=INIT_DEPTH ];
        top = 0;
        this->name = name;
    }
    
    ~Stack(){ delete[] s;  cout <<"Freeing stack " <<name <<endl; }
    
    //-------------------------------------------------------- Prototypes  
    void print( ostream& out );
    void push   ( T c );     
    //-------------------------------------------------------- Inline functions  
    T    pop    ( ){ return s[--top]; }     // Pop top item and return it.
    T    peek   ( ){ return s[top-1]; }     // Return top item without popping it.
    bool empty  ( ){ return top == 0; } 
    int  size   ( ){ return top; }          // Number of items on the stack.
};
#endif
