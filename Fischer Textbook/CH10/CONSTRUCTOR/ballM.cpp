// ------------------------------------------------------------------------
//  Syntax and semantics for copy constructors, initialization, assignment.
//	Alice E. Fischer May 6, 2001	       					file: ballM.hpp
// ------------------------------------------------------------------------
#include "tools.hpp"
#include "ball.hpp"
int Ball::Counter = 0;     // Create & initialize the static class member.

// ------------------------------------------------------------------------
int main( void ) {
	cout <<"                                 ID  Name\n";
	Ball One;			cerr <<"a. " << One <<endl;     // Default constructor 
	Ball Two( 75 );		cerr <<"b. " << Two <<endl;     // Normal constructor		
	Ball Three("Ali");	cerr <<"c. " << Three <<endl;	// Normal constructor		
	Ball Four( One );	cerr <<"d. " << Four <<endl; 	// Copy constructor
	Ball Five = Three;	cerr <<"e. " << Five <<endl;	// Copy Constructor
    cout << "\nReady to construct an array:" <<"\n";
	Ball Six[2];		cerr <<"\t" <<"f. "<< Six[0] <<"\t   " <<Six[1] <<"\n";
	// Ball Bad = Ball(77);						// Bad: Ball(77) not a Ball&
	cerr <<"\nNow " << One.getcount() <<" Ball objects have been created.\n"; 
	Four = Two; 		cerr << "g............................\n" // Assignment
                             <<"\t" << Four <<"\n\t"  << Two <<endl;   
	bye();
	return 0;
}
