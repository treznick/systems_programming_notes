// --------------------------------------------------------------------------                                     
// Read one string and store in dynamic memory.              file: getRag.cpp
//
#include "tools.hpp"  

char* getRag( istream& fin ) 
{  	   
	static char buf[80];    	// Input buffer limited to 80 chars. 
	int len;    				// Length of input phrase. 
	char* item;

	fin.getline( buf, 80 );     // Don't read past end of buffer.
	len = fin.gcount();    		// Measure the input string.
	item = new char[len]; 	    // With getline, len is always >= 1. 
	strcpy( item, buf );		// Copy input into the new space. 
	return item;				// Return dynamic storage containing input.
}
