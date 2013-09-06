#include "tools.h"

char* badread( int n ){ 
	int k = 3*n;
	char buf[k]; 
	fgets( buf, n, stdin ); 
	return buf; 
} 
//-------------------------------------------------
char* goodread( int n ){ 
	char* buf = malloc( n ); 
	fgets( buf, n, stdin ); 
	return buf; 
} 
//-------------------------------------------------

void main(void)
{	
	string word1, word2, word3;
	puts( "Enter the alphabet: " );
	word1 = goodread( 8 );
	word2 = badread( 5 );
	word3 = goodread( 8 );
	
	printf( "Your letters: %s %s %s\n", word1, word2, word3 );
}

/* Output: -----------------------------------------------
(beth:1.43)~/<2>book/c6_debug/ccode> gcc -o danglec -Wall -I../.. dangle.c

dangle.c: In function `badread':
dangle.c:6: warning: function returns address of local variable
*/
