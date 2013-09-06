#ifndef COMPARE
#define COMPARE
// --------------------------------------------------------------------------  
// Called by qsort() to compare two strings (non-class objects).
// To compare two class objects, the last line would call a class function.
//
inline int 
compare( const void* s1, const void* s2 )
{    
	char* ss1 = *(char**)s1;
	char* ss2 = *(char**)s2;  
 	return strcmp( ss1, ss2 );		// This compares two non-class objects
}
#endif
