// ==========================================================================
// Template example -- Using a stack template.
// Alice E. Fischer  June 9, 2002                         file: evaluateM.cpp
//
#include "eval.hpp"

// =========================================================================
int main( void ) 
{
    char buf[256];
	double answer;
	
	Eval::instructions();
	for(;;){
		cout <<"\nEnter an expression:\n\t";
		cin.getline( buf, 256 );
		if ( buf[0] == ';') break;
		Eval E( buf );
		answer = E.evaluate();
		cout << answer <<" = " <<buf <<endl;
	}
    bye();
}
