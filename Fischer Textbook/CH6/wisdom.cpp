#include "tools.hpp"

int main( void )
{
	char buf[80];
	char* input = buf;
	cout << "Enter some wisdom: ";
	cin.getline( input, 80 );
	cout << "Today's words for the wise: " <<input <<endl;
	delete input;
	bye();
}
