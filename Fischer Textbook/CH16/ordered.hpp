// ------------------------------------------------------------------------
// Ordered base class -- An abstract class
// A. Fischer  June 8, 1998                               file: ordered.hpp
//
#ifndef ORDERED_H
#define ORDERED_H
#include <limits.h>
#include <iostream.h>
// ------------------------------------------------------------------------
class Ordered {
  public:
    virtual ~Ordered(){}
	virtual KeyType	key() const						    =0;
	virtual bool	operator <  (const KeyType&) const  =0;
	virtual bool 	operator == (const KeyType&) const  =0;
};
#endif
