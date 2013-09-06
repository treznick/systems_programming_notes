#ifndef EVAL_H
#define EVAL_H
//--------------------------------------------------------------------------
// A. Fischer, June 9, 2002                                  file: eval.hpp
//
// Parse and evaluate a prefix expression.  All operators are binary; 
// they are: +, -, *, /, % (a mod b) and ^ (a to the power b) 
// Whitespace must be used to delimit both operators and operands. 
// Operands must start with a digit and may or may not have a decimal point.
// Operands must not exceed 30 keystrokes.
#include "tools.hpp"
#include "stackT.hpp"
#include "operator.hpp"

class Eval {
  private: // --------------------------------------------------------------
	enum Intype { bad, number, op, end };
	istrstream instream;
	Stack<Operator> Ators;	// Stack of operators.
	Stack<double> Ands;		// Stack of operands and intermediate results.
	Intype classify();
	void   dispatch();
	void   force( int rprec );
	double expError() const;

  public: // ---------------------------------------------------------------
    Eval( char* expr ) : instream(expr) {} 
    ~Eval() {}
	static void instructions( void );
	double evaluate();	 
	ostream& print( ostream& out ) const;
};
#endif
