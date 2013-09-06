//------------------------------------------------------------------------------
// Van is a container class that can hold a load of Boxes.
// A. Fischer October 9, 2000                                      file: van.hpp 
// Hex addresses from a run on OS-X, March 1, 2009
//------------------------------------------------------------------------------
#pragma once;
#include "tools.hpp"
#include "box.hpp"
//------------------------------------------------------------------------------
class Van { 
  private: 
	int Count;      // @ f718, 4 bytes
	int Max;        // @ f71c, 4 bytes
	Box* Load1;     // @ f720, 4 bytes -> 1001b4, 0x40 = 48 bytes: 12*3 + 4 + ?
	Box* Load2;     // @ f724, 4 bytes -> 1001f4

  public:  
	Van (int n=6);
  	~Van(); 
	ostream& print( ostream& out );
	void dump( ostream& out );
    int load_dim(){ return *( (int*)(&Load1) - 1 ); } 
};
//----------------------------------------------------------- Global declaration
inline ostream& operator<< (ostream& out, Van& V) { return V.print( out ); }
