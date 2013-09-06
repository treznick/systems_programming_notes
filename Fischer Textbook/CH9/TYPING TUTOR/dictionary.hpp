//===========================================================================
// Class declarations for Dictionary.               
// A. Fischer, April 25, 2001						     file: dictionary.hpp
#ifndef DICT
#define DICT

#include "tools.hpp"
#include "sstore.hpp"
#include "flexChars.hpp"
#include "flexString.hpp"

//===========================================================================
class Dictionary {
  private:
	StringStore SS;			      // Vocabulary is stored in the StringStore.
	FlexString* HT;			      // Vocabulary is accessed using a HashTable.
    ifstream fin;		  		  // Stream for reading the vocabulary file. 
	int NumBuk;				      // Number of buckets in the HashTable.
	int CurrentBuk;			      // Bucket currently in use; set by hash.
	void hash( const char* s );	  // Sets CurrentBuk to correct bucket for s.
	void put( char* s );	  	  // Put new words in the dictionary.

  public:					      //-----------------------------------------
	Dictionary( char* infile, int buckets=101 );
	~Dictionary(){ delete[] HT; }
   	bool find( const char* s );	
};
#endif