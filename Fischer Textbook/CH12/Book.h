/*  ----------------------------------------------------------------------------
 *  Public Derivation and static const class member.                file: Book.h
 *  Created by Alice Fischer on 3/2/09.
 */
#pragma once;
#include "Printed.h"
//--------------------------------------------------------------------------------
class Book : public Printed {
    private:    static int bookCount;   // Number of Book objects that exist.
    protected:  const int serial;		// Serial number of this instance.
    public:     const char* name;		// Name given in the declaration.
    
  	Book(char* b,char* np,char* pub): Printed(np,pub), serial(++bookCount), name(b){ 
		cerr <<"Creating " <<name 
        <<" based on #" <<Printed::serial <<" Printed named " <<Printed::name 
        <<endl; 
	}
  	~Book(){cerr <<"deleting "<<name <<", leaving " <<--bookCount <<" Book\n";}
    
	ostream& print( ostream& out) const { 
		out <<name <<" #" <<serial 
            <<"\n\tis " <<Printed::name <<endl 
            <<"\tmy Pubs' name is hidden from me." <<endl; 
        
        // out << Pubs::name;       // error: Pubs::name is inaccessible.
        // Pubs pp = (Pubs)(*this); // error: Pubs is an inaccessible base of Book.  
        // Printed p = (Printed)(*this);   // This line compiles, triggers copying.
        // out << p.Pubs::name;     // error: Pubs is an inaccessible base of Printed.
		return out;
	}
};
inline ostream& operator<< (ostream& out, const Book& x){ return x.print(out); }
