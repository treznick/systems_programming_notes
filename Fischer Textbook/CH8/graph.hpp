//===========================================================================
// Declarations for a bar graph.                
// A. Fischer, April 22, 2000                                 file: graph.hpp
//===========================================================================
#ifndef GRAPH
#define GRAPH
#include <iostream>
#include "row.hpp"
using namespace std;
//---------------------------------------------------------------------------
class Graph {
  private:
    Row* Bar[11];		// Each list is one bar of the graph.  (Aggregation)
	void Insert( char* name, int score );

  public:
	Graph ( istream& infile );
	~Graph(); 		
	ostream& Print ( ostream& out );
};

inline ostream& operator<<( ostream& out, Graph& G){ return G.Print( out ); }
#endif  
