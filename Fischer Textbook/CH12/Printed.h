/*  ----------------------------------------------------------------------------
 *  Illustrates private derivation and static class members      file: Printed.h
 *  Created by Alice Fischer on 3/2/09.
 */
#pragma once;
#include "Pubs.h"
//--------------------------------------------------------------------------------
class Printed : Pubs {
    private:    static int prinCount;   // Number of Printed objects that exist.
    protected:  const int serial;		// Serial number of this instance.
    public:     const char* name;		// Name given in the declaration.
	
  	Printed( char* np, char* pub ): Pubs(pub), serial(++prinCount), name(np) {
 		cerr <<"Creating " <<name <<" based on #" <<Pubs::serial 
        <<" Pubs named " <<Pubs::name <<endl; 
	}
  	~Printed(){ cerr <<"deleting "<<name <<", leaving " <<--prinCount <<" Printeds\n";}
    
	ostream& print( ostream& out) const { 
		out <<name <<": " <<" #" <<serial  <<"\n\twhose base object is ";
		return Pubs::print( out );  
	}
};
inline ostream& operator<< (ostream& out, const Printed& x){ return x.print(out);}
