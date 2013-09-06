// ==========================================================================
// Template class definition for a stack of T objects
// Alice E. Fischer  June 10, 2000                          file: stackT.hpp
//
#ifndef STACKT_H
#define STACKT_H
#include "flexT.hpp"

template <class T>
class Stack : FlexArray<T> {
  public:           //-------------------------------------------------------
    Stack(int sz=4): FlexArray<T>(sz){}
    Stack(const Stack& s){ fatal( "Can't shallow-copy stack %s", s.Name ); }
    ~Stack() {}

    void  push(T& c)     { put( c ); };
    T     pop()          { return empty() ? (T)0 : Data[--N]; }
    T 	  top()    const { return empty() ? T(0) : Data[N-1]; }
    bool  empty()  const { return N == 0; }
    int   depth()  const { return N; }
	void  dump(ostream& out);
    ostream& print(ostream& out) const;
};

template <class T> //--------------------------------------------------------
void
Stack<T>::dump(ostream& out) {
	while (!empty())  out << pop();
}

template <class T> //--------------------------------------------------------
ostream&
Stack<T>::print(ostream& out) const {
    out <<"\nStack has " <<depth() <<" items: bottom<[ ";
    FlexArray<T>::print( out );
    out << "  ]>top\n";
    return out;
}

template <class T> inline //-------------------------------------------------
ostream&
operator<< ( ostream& out, const Stack<T>& s ){ return s.print( out ); }
#endif
