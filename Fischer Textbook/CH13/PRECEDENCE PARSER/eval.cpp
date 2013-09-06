//------------------------------------------------------------------------------------
// A. Fischer, June 9, 2002                                             file: eval.cpp
//
#include "eval.hpp"
#include "operator.hpp"
// ---------------------------------------------------- Instructions for the operator.
void Eval::instructions( void ){
	cout << "This is an infix expression evaluator.\n"
		 << "* Operands start with a digit and may or may not have a decimal point.\n"
		 << "* Operands must not exceed 31 keystrokes.\n"
		 << "* All operators are binary operators.\n"
		 << "* Operators are: +, -, *, /, % (a mod b) and ^ (a to the power b).\n"
		 << "* Whitespace must be used to delimit both operators and operands.\n"  
		 << "To quit, type semicolon instead of an expression.\n";        
}

// ----------------------------------------------------------------- Print the stacks.
ostream&
Eval::print( ostream& out ) const {
	out << "\tRemaining contents of operator stack: " <<Ators; 
	out << "\tRemaining contents of operand stack: " <<Ands;	 
	return out;
}

// ------------------------------------------------------------------- Error comments.
double
Eval::expError() const {
	cerr << "\tIllegal expression.\n";
	print(cerr); 
	return HUGE_VAL;	
}

// -------------------------------- Evaluate all higher precedence operators on stack.
void
Eval::force( int rprec ) {		
	while( Ators.depth()>0 && Ators.top().precedence() >= rprec ) dispatch();
}

//---------- Decide whether next input char is an operator, a semicolon, the beginning 
Eval::Intype											 // of an operand, or garbage.
Eval::classify(){
	instream >> ws;
	if (instream.eof()) return end;
	char ch = instream.peek();
	if (isdigit( ch )) return number;
	switch(ch){
	  case '+': 
	  case '-': 
	  case '*': 
	  case '/': 
	  case '%': 
	  case '^': return op;  
      default : return bad;
	}
}
//------------------------------------------------ Read input and evaluate expression.
double
Eval::evaluate() {
	Intype next;	// Classification of next input character.
	char inSymbol;  // Read input operators into this.
	Operator inOp;  // Operator object constructed from inSymbol.
	double inNum;   // Read input operands into this.
	
	for(;;) {
		next = classify();
		switch( next ){
		  case number: 	
				instream >> inNum;
				if ( Ands.depth() != Ators.depth() ) return expError();	
				Ands.push( inNum );
				break;
				
		  case op: 
				instream >> inSymbol;
				inOp = Operator(inSymbol);
				if ( Ands.depth() != Ators.depth()+1 ) return expError();
				force( inOp.precedence() );
				Ators.push( inOp );
				break;
				
		  case end:
				if ( Ands.depth() != Ators.depth()+1 ) return expError();
				force( 0 );
				return  Ands.pop();
				break; 
				
		  case bad: 
		  default: return expError(); 
		}
	}
} 

// ------------------------------------------------------------ Evaluate one operator.
void
Eval::dispatch() {
	double result;
	double right = Ands.pop();
	double left = Ands.pop();
	Operator op = Ators.pop();
	cerr << "  Evaluating: "<< left << op.symbol() << right <<"\n";
	switch (op.symbol()) {
	    case '+': result = left + right; 		break;
	    case '-': result = left - right; 		break;
	    case '*': result = left * right; 		break;
	    case '/': result = left / right; 		break;
	    case '%': result = fmod(left, right); 	break;
	    case '^': result = pow (left, right); 	break;
	}
	Ands.push( result );
}
