//================================================================================    
// A. Fischer, April 2001                                                file: getline.cpp
//--------------------------------------------------------------------------------
// The get function leaves the trailing \n in the input stream. 
//--------------------------------------------------------------------------------
void use_get( istream& instr )  
{    
    cout <<"\nUsing get to read entire lines.\n";
    char buf[80];
    while (instr.good() ){
        instr >> ws;                   // Without this line, it is an infinite loop.
        instr.get( buf, 80 ); 
        cout <<instr.rdstate() <<" = ";
        cout <<instr.good() <<":" <<instr.eof() <<":" <<instr.fail() <<":"     
             <<instr.bad() <<": ";
        if (!instr.fail() && !instr.bad()) cout << buf << endl;
    }
    if ( instr.eof() ) cout << "-----------------------------------\n" ;
    else cout << "Low-level failure; stream corrupted.\n" ; 
}

//================================================================================
// The getline function removes the trailing \n from the stream and discards it. 
//--------------------------------------------------------------------------------
#include "tools.hpp"

void use_getline( istream& instr )
{    
    cout <<"\nUsing getline to read entire lines.\n";
    char buf[80];
    while (instr.good()) {  
        instr.getline( buf, 80 ); 
         cout <<instr.rdstate() <<" = ";
         cout << instr.good() <<":" << instr.eof() <<":" << instr.fail() <<":"    
              << instr.bad() <<": ";
        if (!instr.fail()) cout << buf << endl; 
    }
    cout << "-----------------------------------\n";
}

//================================================================================    
// Handle conflicts between input data type and expected data type like this.
//--------------------------------------------------------------------------------
#include "tools.hpp"

void use_nums( istream& instr )  
{    
    cout <<"\nReading numbers.\n";
    int number;  
    for(;;) {
        instr >> number;     
        cout <<instr.good()<<": "<<instr.eof()<<":"<<instr.fail()<<":"<<instr.bad()<<": ";    
        if (instr.good()) cout << number << endl;
        else if (instr.eof() ) break;    
        else if (instr.fail()) {        // Without these three lines
           instr.clear();                // an alphabetic character in the input 
           instr.ignore(1);                // stream causes an infinite loop.
        }
        else if (instr.bad())             // Abort after an unrecoverable stream error.
            fatal( "Bad error while reading input stream." );
    }
    cout << "-----------------------------------\n" ;               
}
