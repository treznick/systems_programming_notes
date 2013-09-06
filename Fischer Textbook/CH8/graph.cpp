//==========================================================================
// Implementation of the Graph class.                
// A. Fischer, April 22, 2000                            file: graph.cpp
//==========================================================================
#include "graph.hpp"
//--------------------------------------- Use an input file to build a graph.
Graph::Graph( istream& infile ){
	char Inits [4];
    int Score;
    for (int k=0; k<11; ++k) Bar[k] = new Row(k);
    for (;;){
		infile >> ws;				// Skip leading whitespace before get.
    	infile.get(Inits, 4, ' ');  // Read three initials ... safely.
        if (infile.eof()) break;
		infile >> Score;			// No need to skip ws before using >>.
        Insert (Inits, Score);
    }
}

// --------------------------------------------------------- Delete all Rows.
Graph::~Graph() { 
    for (int k=0; k<11; ++k) delete Bar[k];
	cerr <<" Deleting Graph\n";  		
}

// ------------------------------------------------ Insert a node into a Row.
void	
Graph::Insert( char *init, int score ){ // Function is private within class.  
    int index = 10;						// Default to last row of graph.  
	
	if (score >= 0 && score < 100)		// But if score is between 0-99...  
		index = (score / 10); 			// it belongs in one of first 10 rows. 
	Bar[index]->Insert( init, score );
}

// ---------------------------------------------- Print the entire bar graph.
ostream& 
Graph::Print( ostream& out ){
	out << "\n";
	for (int k=0; k<11; ++k) out << *Bar[k] << "\n";
	return out;
}
