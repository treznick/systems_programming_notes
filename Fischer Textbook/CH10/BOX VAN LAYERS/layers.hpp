//--------------------------------------------------------------------------------
// The Layers class aggregates Van and Box.
// A. Fischer October 10, 2000                                    file: layers.hpp 
//--------------------------------------------------------------------------------
#pragma once;
#include "van.hpp"

class Layers {      //------------------------------------------------------------
  	char* name;	// Memory is allocated by body of Layers constructor.
	Box B;			   
	Van V;			 

 public:			//------------------------------------------------------------
	Layers( char* nm ) : B(8,7,6), V(4) {    		     // constructor with ctors
		cout <<"  Constructing " <<nm <<"\n";
		name = new char[strlen(nm) + 1];
		strcpy(name, nm);
		cout <<"  " <<nm <<" is complete.\n\n";
	}

  	~Layers() {                            				// destructor
		cout << "  Deleting name @ " <<(unsigned)name <<": " <<name << endl;
		delete name;
	}

    void print( ostream& out ){
		out << "Instance is: " <<this <<" name: " <<name <<endl
        	<<"   Box: " <<B <<"\n   Van: " <<V; 
	}
};
