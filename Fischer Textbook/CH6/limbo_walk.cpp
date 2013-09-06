#include "tools.hpp"

int main( void )
{
 	char* name[5] = {"Jane", "Yonit", "Theo", "Xin"};
	char* selection;

	for(int k=0; k<5; k++){ 
		selection = name[k];
		cerr << "Name [" << k <<"] is " << selection << " \t";
		cerr << "[" << k <<"][" << k <<"] = "<<selection[k] << "\n";
	}
	bye();
}
