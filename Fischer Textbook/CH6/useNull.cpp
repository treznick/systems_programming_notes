#include "tools.hpp"
int main(void)
{   
    char buf[80];
	cout << "Enter some words and some punctuation: \n\t";
    cin.getline( buf, 80 );
    char* scan = strchr(buf, '?'); 
	cout << "I like the last part: " <<scan+1 <<"\n\n";
	cout << "buf: " <<buf <<endl;
	bye();
}
