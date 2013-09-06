/*  ----------------------------------------------------------------------------
 *  Pubs: the base class.                                           file: Pubs.h
 *  Created by Alice Fischer on 3/2/09.
 */
#pragma once;
#include "tools.hpp"

class Pubs { 
    private:    static int pubCount;	// Number of Pubs that exist.
    protected:  const int serial;		// Serial number of this instance.
    public:     const char* name;		// Name given in the declaration.
    
	//----------------------------------------------------------------------------
  	Pubs( char* g ): serial(++pubCount), name(g) { 
 		cerr <<"Creating " <<name <<endl; 
	}
 	~Pubs(){ 
		cerr <<"deleting "<<name 
        <<", leaving " <<--pubCount <<" Pubs\n"; 
    }
	ostream& print( ostream& out) const { 	// Name, rank, serial number.
        out <<name <<" #" <<serial <<" out of " <<pubCount <<'\n'; 
        return out;  
    }
};
inline ostream& operator<< (ostream& out, const Pubs& x){ return x.print(out); }
