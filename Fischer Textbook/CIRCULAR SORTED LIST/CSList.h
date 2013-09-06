/*
 *  CSList.h
 *  Circular List with a dummy header/trailer, 
 *  sorted in ascending order, with a sentinel at the end.
 */
#ifndef CSLIST
#define CSLIST
#include "tools.hpp"

#include "Person.h"
typedef Person T;   // Type T must support a -0+ compare function.

//------------------------------------------------------------------------
class Node {  friend class CSList;
  protected:
    T* data;
    Node* next;
    
    Node( T* dt, Node* nx): data(dt), next(nx) { }
    Node( T* dt): data(dt), next(this) { }
    ~Node(){ delete data; }
    
    ostream& print( ostream& out ){ return data->print( out ); }    
};

//------------------------------------------------------------------------
class CSList : public Node {
  private:
    Node* scan;             // Used to search the list.
    Node* follow;           // Always 1 node behind scan.
    int count;              // Number of data nodes in the list.
    void find( const T* );  // Position scan and follow.
               
  public:    
    CSList( T* sentinel ) : Node(sentinel), count(0) {}
    ~CSList();
    void insert(  T* );
    ostream& print( ostream& out );
};

#endif