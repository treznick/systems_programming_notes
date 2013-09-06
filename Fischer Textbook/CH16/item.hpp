//--------------------------------------------------------------------------
// Class declaration for data items.                
// A. Fischer, May 29, 2001                      		     file: item.hpp
//
#ifndef ITEM_H
#define ITEM_H
#include <limits.h>

typedef int KeyType;
#include "exam.hpp"
#include "ordered.hpp"
//--------------------------------------------------------------------------
class Item : public Exam, public Ordered {
  public:
	static const KeyType max_sentinel = KeyType(INT_MAX);
	static const KeyType min_sentinel = KeyType(INT_MIN);

	Item(const char* init, int sc): Exam(init, sc){}
	~Item() { cerr <<"Deleting Item " << key() <<"\n"; }

	KeyType	key() const					    { return Score; }
	bool operator==(const KeyType& k) const { return key() == k; }
	bool operator< (const KeyType& k) const { return key() < k; }
	bool operator< (const Item& s)    const { return key() < s.key(); }
};
#endif
