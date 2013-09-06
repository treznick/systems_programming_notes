// ---------------------------------------------------------------------------
// Bargraph of Exam Scores: An introduction to class interactions.  
// Read scores from a user-specified file; display them as a bar graph.
//                                              A. Fischer, September 30, 2000
// ---------------------------------------------------------------------------
#include "tools.hpp"
#include "graph.hpp"

int main ( void )
{
    banner();
	char fname [80];
    cout << "Name of data file: ";
    cin >> fname;
    ifstream infile (fname);		// Declare and open input stream 
    if (!infile)  fatal( "Cannot open %s for input - aborting!!\n", fname );

	Graph curve( infile );			// Declare and construct a Graph object.
	cout <<curve;					// Print the graph. 
	// OR: curve.Print( cout );		// Print the graph. 

	bye();  
	// Storage belonging to curve will be freed by destructors at this time. 
}
