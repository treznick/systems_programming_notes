// ============================================================================
// Name: Bracket-matching example of stack usage                File: stack.cpp
// ============================================================================
#include "stack.hpp"
//-----------------------------------------------------------------------
void Stack::
print( ostream& out )  {
	T* p=s;							// Scanner & end pointer for data 
	T* pend = s+top;  
  	out << "The stack " <<name << " contains: Bottom~~ ";
	for ( ; p < pend; ++p)  cout <<' ' << *p; 
  	out << " ~~Top" <<endl;
}

//-----------------------------------------------------------------------------
void Stack::
push( T c ) { 
	if (top == max) {       // If stack is full, allocate more space.
		say( "-Doubling stack length-" );		
		T* temp = s;							// grab old array.
		s = new T[max*=2];						// make bigger one,
		memcpy( s, temp, top*sizeof(T) ); 	    // copy data to it.
		delete temp;							// free old array.
	}
	s[top++] = c;           // Store data in array, prepare for next push.
} 
