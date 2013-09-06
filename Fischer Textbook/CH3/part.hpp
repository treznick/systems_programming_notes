/*  ----------------------------------------------------------------------
//  Header file for hardware store parts.                         Part.hpp
//  Created by Alice Fischer on Mon Dec 29 2003.
*/
#include "tools.hpp"
#define BUFLENGTH 100   // Maximum length of the name of a part
#define N 1000          // Maximum number of parts in the inventory

struct Part{
	  char* part_name; 
	  int store_code, quantity; 
	  float price;
};

int get_parts( ifstream& fin, Part* data );
void print_parts( ostream& fout, Part* inventory, int n );
