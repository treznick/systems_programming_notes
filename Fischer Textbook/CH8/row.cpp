//===========================================================================
// Implementation of class Row. 
// A. Fischer, April 22, 2000                                   file: row.cpp
//===========================================================================
#include "row.hpp"
//---------------------------------------------------------------------------
Row::Row( int n ){
	if (n == 10) strcpy( Label, "Errors:  " );
	else {
		strcpy( Label, " 0.. 9:  " );
		Label[0] = Label[4] = '0'+ n;
	}
	Head = NULL; 
}
//---------------------------------------------------------------------------
Row::~Row(){
	Cell* curr;
	while (Head != NULL){ 
		curr=Head;
		Head=Head->Next;
		delete curr;
	}
	cerr << " Deleting row " <<Label <<" >>> \n";
}
//---------------------------------------------------------------------------
void 
Row::Insert( char* name, int score ){
	Head = new Cell( name, score, Head );	
}
//---------------------------------------------------------------------------
ostream& 
Row::Print( ostream& os ){
	Cell* curr;
	os << Label;
	for (curr=Head; curr!=NULL; curr=curr->Next) 
		curr->Data->Print( os );	//	OR: os << *(curr->Data);
	return os;
}
