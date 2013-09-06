#include "tools.hpp"
char* badread( int n ){ 
	char buf[n]; 
    cin.get( buf, n ); 
	return buf; 
} 
//-------------------------------------------------
char* goodread( int n ){ 
	char* buf = new char[n]; 
	cin.get( buf, n ); 
	return buf; 
} 
//-------------------------------------------------
int main(void)
{	
	cout << "Enter the alphabet: ";
	char* word1 = goodread( 8 );
	char* word2 = badread( 5 );
	char* word3 = goodread( 8 );
	cout << "Your letters: " <<word1 <<" " <<word2 <<" "<<word3 <<endl;
}
