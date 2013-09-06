//  ----------------------------------------------------------------------------
//  Header file for all DataPack programs.                              pack.hpp
//  Created by Alice Fischer on Sunday August 23, 2009
// -----------------------------------------------------------------------------
#pragma once
#include "tools.hpp" // includes all the other headers you need.

typedef float BT ;   // Generic base type for data pack; BT must implement <=
#define LENGTH  20

class DataPack {
private:
private: // ------------------------------------------------------------------
    int n;      // The current number of items in the array.
    int max;    // Allocation length of the array.
    BT* data;  // For a dynamically allocated data array.
public:    
    // ---------------------------------------------- Constructor and Destructor  
    DataPack( int len = LENGTH ){
        n = 0;
        max = len;
        data = new BT[max];
        // C++ throws an exception if allocation fails.  No test needed here.
    }
    ~DataPack(){
        delete[] data;
    }
     
    // ------------------------------------------------ Functions and Prototypes  
    int nItems() { return n; }          // Allow read-only access to data.
    void getData( const char* filename );
    void print( ostream& sout );  
    void sort( );
};

// ---------------------------------------------- Extension of global operator<<
inline ostream& operator<< (ostream& out, DataPack& dp) {
    dp.print( out );
    return out;
}