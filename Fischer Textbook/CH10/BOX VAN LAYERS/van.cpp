//--------------------------------------------------------------------------------
// Array construction example: Class implementation for Van.
// A. Fischer October 4, 2000                                        file: van.cpp 
//--------------------------------------------------------------------------------
#include "van.hpp"
Van::Van (int n){	//--------------------------------------------------------
	int a, b, c;
	Count = 0; 
	Load1 = new Box[Max=n]; 
	Load2 = new Box[2]; 

	cout <<"\nEnter the boxes; use a 0 dimension to quit\n";
	for (Count=0; Count<Max; ++Count) {
		cout <<"  Dimensions: ";   
    	cin >> a >> b >> c;
		if (a*b*c == 0) break;
    	Load1[Count] = Box(a, b, c); // Make a local box, copy it using assignment.
	}								 // Delete the local box at end of loop body.      
}	
 
Van::~Van(){	//----------------------------------------------------------------
	delete[] Load2;     				// Delete the boxes in the Load array.
	cerr <<"  Deleted Load2.\n";  
	delete[] Load1;     				// Delete the boxes in the Load array.
	cerr <<"  Deleted Load1.\n";  
} 	
	
ostream& Van::print( ostream& out ){  	//----------------------------------------
	out <<"Load 1 has " <<Count <<" Boxes.\n";  
	for (int k=0; k<Count; ++k)  out <<"        " <<Load1[k];
	return out << endl;
}

void Van::dump( ostream& out ) {  		//----------------------------------------
	out <<"  Van @ " <<this 
        <<"\n  Count @ " <<&Count <<" = " << Count
        <<"\n  Load2 @ " << &Load2 <<" = " << Load2<<".\n"
        <<"\n  Load1 @ " << &Load1 <<" = " << Load1 
        <<" slots " << load_dim() <<endl; 
	for (int k=0; k<Count; ++k)  Load1[k].dump( out );
	out << endl;
}
