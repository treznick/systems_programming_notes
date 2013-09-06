#ifndef OPERATOR_H
#define OPERATOR_H
//--------------------------------------------------------------------------
// A. Fischer, June 9, 2002                               file: operator.hpp
//
#include "tools.hpp"
class Operator {
  private: // --------------------------------------------------------------
	char symb;		
	int  prec; 

  public: // ---------------------------------------------------------------
    Operator( char op = 0) : symb(op) {
		switch (op){
		  case '+': case '-': 			prec = 1; break;
		  case '*': case '/': case '%': prec = 2; break;
		  case '^': 					prec = 3; break;
		  default:                      prec = -1; break;
		}
	} 
    ~Operator() {}
	int precedence() const { return prec; }	 
	char symbol()    const { return symb; }	 
	ostream& print( ostream& out ){ 
		return out <<"Symbol: " <<symb <<"  Precedence: " <<prec <<endl; 
	}
};
inline ostream& operator<<( ostream & out, Operator& op) {return op.print(out); }
#endif
