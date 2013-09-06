//===========================================================================
// Class implementation for the Dictionary.                
// A. Fischer, April 25, 2001					         file: dictionary.cpp

#include "dictionary.hpp" 
//---------------------------------------------------------------------------
void
Dictionary::hash( const char* s ){
	int len = strlen(s);
	const char* p = s;
	const char* q = &p[len-1];
	unsigned long hashval = *p;
	for(int k=0; q>=s && k<3; ++k){
		hashval = hashval << 6 ^ *q--;
		hashval = hashval << 3 ^ *(++p);
	}
	CurrentBuk = hashval % NumBuk;
}

//---------------------------------------------------------------------------
void
Dictionary::put( char* word ){ 
	char* saved;			// Pointer to beginning of word in StringStore.
	if (!find( word )){ 
		saved = SS.put( word, fin.gcount() -1 );
		HT[CurrentBuk].put( saved ); 
	}
}

//---------------------------------------------------------------------------
bool
Dictionary::find( const char* s ){
	hash( s );
	int result = HT[CurrentBuk].find( s );  
	return result >= 0;			// -1 indicates not found.
}

//---------------------------------------------------------------------------
Dictionary::Dictionary( char* infile, int buckets ){
	fin.open( infile );
    if (!fin)  fatal( "Cannot open %s for input - aborting!!", infile );
	HT = new FlexString[ NumBuk = buckets ];
	
	char buf[80];
	//cerr <<"Reading words from file " <<infile <<".\n";
	for (;;) {
		fin >> ws;
	    fin.getline( buf, 80 );
		if (!fin.good()) break;
		put( buf );
		cout << buf <<" ";
	}
	if ( !fin.eof() ) fatal( "Read error on tutor file" );
	fin.close();
}
