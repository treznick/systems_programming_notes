//===========================================================================
//  Person: A student's initials and one exam score.
//  A. Fischer, March 3, 2006                                file: person.hpp
//===========================================================================
#ifndef PERSON
#define PERSON
#include "tools.hpp"

//---------------------------------------------------------------------------
class Person                    // One name-score pair
{
  private:						// Variable names are private
    char initials [4];          // Array of char for student name
    int  score;                 // Integer to hold score

  public:
    inline Person (char* inits, int sc);
    ~Person (){ cerr << "Deleting Person " <<initials <<"\n"; }
    inline ostream& print( ostream& os ); 
    inline int compare( const Person* p) const;
};

//---------------------------------------------------------------------------
Person::Person (char* inits, int sc){
    strcpy( initials, inits );
    score = sc;
}

//---------------------------------------------------------------------------
int Person::compare( const Person* p) const {
    return score - p->score;             // A negative, zero, positive result. 
}

//---------------------------------------------------------------------------
ostream& 
Person::print ( ostream& os ){ 
    return os << initials <<" " <<score <<"   "; 
}

//---------------------------------------------------------------------------
inline ostream& 
operator << (ostream& out, Person& T){ return T.print( out ); }

#endif
