// ------------------------------------------------------------------------
//  Syntax and semantics for copy constructors, initialization, assignment.
//	Alice E. Fischer May 6, 2001	       					 file: ball.hpp
// ------------------------------------------------------------------------
#pragma once;
class Ball {	// --------------------------------------------------------
  private:
	static int Counter;
	const int ID;
	char* Name; 

  public:		// --------------------------------------------------------
	//Ball(){ cerr<< "Null constructor........"; }	// Null constructor
	//~Ball(){}									    // Null destructor.
	~Ball(){
		--Counter;  delete Name;   
		cerr <<"\tDestructor..." << Counter <<" Balls remain.\n";
	}						    
	Ball( int alpha = 66 ): ID( ++Counter ) {  // --- Default constructor.
		cerr <<"Default or normal constructor. ";
		Name = new char[ 2 ]; 
		Name[0] = alpha; Name[1] = '\0';
	}
	Ball( char* arg ): ID( ++Counter ) {	// -------- Normal constructor.
		cerr <<"Normal constructor.............";
		Name = new char[ 1+strlen(arg) ]; 
		strcpy( Name, arg );
	}
	Ball( Ball& a ): ID( ++Counter ) { // ---------- Deep copy constructor.
		cerr <<"Copy constructor..............."; 
		Name = new char[ 1+ strlen(a.Name) ];
		strcpy( Name, a.Name );
	}
	Ball& operator = ( Ball& source ){ // -- Changes data but not identity.
		cerr<<"Assignment function...........\n "; 
		Name[0] = source.Name[0]; 
		return *this; 
	}

	void print() { cerr <<ID <<"  " <<Name ; }
	int getcount() { return Counter; }
}; 
ostream& operator <<( ostream& out, Ball& C ){ C.print(); return out; }
