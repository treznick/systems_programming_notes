#include "tools.hpp"
int main( void )
{	
	char* buf1 = new char(100);
	char* buf2 = new char(100);
	cout <<"Enter two lines of text: \n";
	cin.getline( buf1, 100 );
	cin.getline( buf2, 100 );
	cout <<"Echo [(" <<buf1 <<endl <<buf2 <<")]\n" ;
}
