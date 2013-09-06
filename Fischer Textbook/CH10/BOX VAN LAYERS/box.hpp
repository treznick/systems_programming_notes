//--------------------------------------------------------------------------------
// A. Fischer October 9, 2000                                        file: box.hpp 
//--------------------------------------------------------------------------------
#pragma once;
#include "tools.hpp"
//--------------------------------------------------------------------------------
class Box {
  private:
	int length, width, high;   // The 3 dimensions of a box; occupies 12 bytes.

  public:
	Box(int ln, int wd, int ht){
        length=ln; width=wd; high=ht; cout<<"\n  Real Box ";
    } 
	Box(){ length = width = high = 1; cout <<"Default Box ";}
    
  	~Box() {  cerr<< "  Deleting: ";  dump( cerr ); }
    
	ostream& print( ostream& out ){ 
		return out <<length <<" by " <<width <<" by " <<high <<".  ";
	}
	inline void dump( ostream& out );
};
//-------------------------------------------------------------------------------
inline ostream& operator<< (ostream& out, Box& B) { return B.print( out ); }
inline void Box::dump(ostream& out){ out <<"  Box @ " <<this <<" : " <<*this <<endl;}
