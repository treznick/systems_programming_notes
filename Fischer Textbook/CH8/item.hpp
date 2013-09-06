//===========================================================================
//  Item: A student's initials and one exam score.
//  A. Fischer, October 1, 2000                                file: item.hpp
//===========================================================================
#ifndef ITEM
#define ITEM
#include <iostream>
#include <string.h>
using namespace std;
//---------------------------------------------------------------------------
class Item                      // One name-score pair
{
  private:						// Variable names are private
    char Initials [4];          // Array of char for student name
    int  Score;                 // Integer to hold score

  public:
    inline Item (char* inits, int sc);
    ~Item (){ cerr << "    Deleting Item " <<Initials <<" ..."; }
    inline ostream& Print ( ostream& os ); 

};
//---------------------------------------------------------------------------
Item::Item (char* inits, int sc){
    strcpy( Initials, inits );
    Score = sc;
}
ostream& 
Item::Print ( ostream& os ){ 
    return os <<Initials <<" " <<Score <<" "; 
}
inline ostream& 
operator << (ostream& out, Item& T){ return T.Print( out ); }
#endif
