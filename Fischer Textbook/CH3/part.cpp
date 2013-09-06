/*  ----------------------------------------------------------------------
//  Implementation file for hardware store parts.                 Part.cpp
//  Created by Alice Fischer on Mon Dec 29 2003.
*/
#include "Part.hpp"
//---------------------------------------------------------------------
int 
get_parts( ifstream& fin, Part* data ) {
	char buf[BUFLENGTH];
	int len;   		    // Length of input string.
	Part* p = data;		// Cursor to traverse data array.
	Part* pend = p+N;	// Off-board pointer to end of array.
 
	while (p<pend) {						   
		fin >> ws;						
		if (fin.eof()) break;
		fin.getline( buf, BUFLENGTH, ',' );
		len = fin.gcount();  
		fin >> p->store_code >> p->quantity >> p->price;
   
 		if (fin.good()) {   // All required data items were read.
			p->part_name = new char[len];
			strcpy( p->part_name, buf );
			++p; 			// Position cursor for next input.
		}
		else { 
		  	fin.clear();
			cerr <<"Error reading line " <<(p-data+1) <<":\n" 
                 <<"    Before error: " <<buf <<" " 
                 <<p->store_code <<"  " <<p->quantity <<endl;
		  	fin.getline( buf, BUFLENGTH ); // Skip rest of defective line.
			cerr <<"    After error: " <<buf <<endl;
		}
	}
	return p - data;  // Number of data lines read correctly and stored.
}

//------------------------------------------------------------------
void 
print_parts( ostream& fout, Part* inventory, int n ){
	Part* p = inventory;
	Part* pend = inventory+n;
  
	for ( ; p<pend; ++p) {
        fout <<left  <<setw(25) <<setfill('.') <<p->part_name; 
        fout         <<setw(3)  <<setfill(' ') <<p->store_code;  
        fout <<right <<setw(5)                 <<p->quantity;
	    fout <<fixed <<setw(8)  <<setprecision(2) <<p->price <<endl; 
    }
}
