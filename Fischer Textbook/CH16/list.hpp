// ------------------------------------------------------------------------
// Unsorted list: derived from  Container-<--Linear-<--List 			
// A. Fischer   June 9, 2001	                             file: list.hpp
// ------------------------------------------------------------------------
#ifndef LIST_H
#define LIST_H
#include "linear.hpp"
#include "item.hpp"

// ------------------------------------------------------------------------
class List : public Linear {
  public:
	void  insert( Cell* cp ) { reset(); Linear::insert(cp); }

	// --------------------------------------------------------------------
	void  focus(){ 
		KeyType k;
		cout <<"\n  What key would you like to remove? ";
		cin >> k;
  		for (reset(); !end(); ++*this) if (*this == k) break;
	}
};
#endif
