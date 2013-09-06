//---------------------------------------------------------------------------------
// Return by value, reference, and pointer, and how they differ.  
// A. Fischer Apr 19, 1998                                        file: returns.cpp 
//---------------------------------------------------------------------------------
int 		ret0( int* ar ) { return  ar[0]; }    // Returns an integer R-value.
int*		ret1( int* ar ) { return &ar[1]; }    // A pointer R-value.
const int* 	ret2( int* ar ) { return &ar[2]; }    // A read-only pointer R-value.
int& 		ret3( int* ar ) { return  ar[3]; }    // An L-value (reference).
const int& 	ret4( int* ar ) { return  ar[4]; }    // A read-only L-value reference.
