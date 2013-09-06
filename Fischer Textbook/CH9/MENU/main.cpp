#include "tools.hpp" 
#define INPUT "menu.in"

char* getRag( istream& ); 
void print_menu( char*[], int );

// ------------------------------------------------------------------
int main (void) 
{ 
	int k;							// Line counter.
	char* menu[20];					// Backbone of ragged array.
	
	cout <<"Ragged Array Demo Program\n"; 
	ifstream menufile( INPUT );		// Open file named by define.
	if (!menufile) fatal( "Cannot open file %s." INPUT );
	
	cout <<"Reading menu items from " <<INPUT <<"\n"; 
	for(k=0; k<20; ++k)  {
		menu[k] = getRag( menufile );
		if (menufile.eof()) break;  // User decided to quit.
	}
	print_menu( menu, k );
    return 0;
}

// ------------------------------------------------------------------
void print_menu( char* menu[], int n ) 
{  	   
    int k;         		  			/* subscript variable for loop */              
    cout <<"\n" <<n <<" skating sessions are available:\n";   	
    for (k = 0; k < n; ++k)  cout << '\t' <<menu[k] <<endl;
}
