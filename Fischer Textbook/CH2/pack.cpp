// ----------------------------------------------------------------------------- 
//  DataPack class:  an array plus its management information.
//  Implementation file for all DataPack programs.                      pack.cpp
//  Created by Alice Fischer on Mon August 23, 2009
// ----------------------------------------------------------------------------- 
#include "pack.hpp"

// --------------------------------------------------------------------- 
//  Read (from user) name of input file and open it.  
//  Read up to max items from input stream and store in array. 
void DataPack::
getData( const char* filename ) {   
    ifstream infile( filename ); 
    if (! infile)  fatal( "    Error: could not open input %s\n", filename ); 

    BT* cursor = data;     // Scanning pointer, set to start of array.     
    BT* end = data + max;  // An off-board sentinel 
    for( ; cursor<end; ++cursor ) {
        infile >> *cursor;
        if( ! infile.good() ) break;    // Quit for bad data or for end of file.
    }
    if (! infile.eof() ) fatal("  Error reading input file %s", filename );
    n = cursor-data;                   // Actual # of items read.
    infile.close();
}

//  ------------------------------------------------------------------------
// Print array values, one per line, to the selected stream.
void DataPack::
print( ostream& out )
{     
    for( int k=0; k<n; ++k)    out <<k <<".\t" << data[k] <<endl;     
}

//  ------------------------------------------------------------------------
// Generic insertion sort using a DataPack.            
// Sort n values starting at myData.head by an insertion sort algorithm. 
void DataPack::
sort()  
{
    BT* const end = &data[n];    // Off-board sentinel. 
    BT* pass;                    // First unsorted item; begin pass here. 
    BT  newcomer;                // Data value being inserted. 
    BT* hole;                    // Array slot containing no data. 
    
    for ( pass=&data[1]; pass<end; ++pass ) { 
        // Pick up next item and insert into sorted portion of array. 
        newcomer = *pass;
        for ( hole=pass; hole>data; --hole ) {
            if ( *(hole-1) <= newcomer ) break;   // Insertion slot is found. 
            *hole = *(hole-1);                    // Move item back one slot. 
        }
        *hole = newcomer;
    }
}