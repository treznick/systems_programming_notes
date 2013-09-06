//------------------------------------------------------------------------------
// Demonstrate syntax and usage of default parameters.
// A. Fischer February 10, 2009                                    file: box.hpp 
//------------------------------------------------------------------------------
#pragma once;
#include "tools.hpp"
//------------------------------------------------------------------------------
class Box {
  private:
	int length, width, high;	// The three dimensions of a box.

  public:
	Box(int ln=1, int wd=1, int ht=1){
        length=ln; width=wd; high=ht; 
    } 
    
    ~Box() {} 
    
	ostream& print( ostream& out = cout ){ 
		return out <<length <<" by " <<width <<" by " <<high <<".  ";
	}
};

//------------------------------------------------------------------------------
inline ostream& operator<< (ostream& out, Box& B) { return B.print( out ); }

