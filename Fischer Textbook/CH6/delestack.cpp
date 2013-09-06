#include "tools.hpp"
int main(void)
{   
    char* scan, * buf = new char[80];
	cout << "Enter some words and some punctuation: \n\t";
	for(;;) {
		cin.getline( buf, 80 );
		scan = strchr( buf, '.' );
		if (scan != NULL) break;
		cout << "I don't like " <<buf <<" Try again.\n\t";
	}
	cout << "I like the last one.\n" <<scan <<endl;
	delete scan;
}
