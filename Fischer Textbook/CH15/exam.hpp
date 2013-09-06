//===========================================================================
//  Exam: A student's initials and one exam score.
//  A. Fischer, October 1, 2000                                file: exam.hpp
//===========================================================================
#ifndef EXAM_H
#define EXAM_H
#include <string.h>
#include <iostream.h>
typedef int KeyType;
//---------------------------------------------------------------------------
class Exam						// One name-score pair
{
  private:	//--------------------------------------------------------------- 
	char Initials [4];          // Array of char for student name	
  protected://--------------------------------------------------------------- 
	int Score;                  // Integer to hold score 
  public:  //----------------------------------------------------------------
	Exam (const char* init, int sc){
		strncpy( Initials, init, 3 );
		Initials[3] = '\0';
		Score = sc;
	}    
	~Exam (){ cerr << "    Deleting Score " <<Initials <<"..."; }
	ostream& Print ( ostream& os ){ 
		return os <<Initials <<": " <<Score <<"  "; 
	}
};
//---------------------------------------------------------------------------
inline ostream& operator << (ostream& out, Exam& T){ return T.Print( out ); }
#endif
