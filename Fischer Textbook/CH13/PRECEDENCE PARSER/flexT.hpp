//--------------------------------------------------------------------------
// Template declaration for a flexible array of base type T.                
// A. Fischer, May 14, 2001                                   file: flex.hpp
//
#ifndef FLEXT_H
#define FLEXT_H
#include "tools.hpp"

#define FLEX_START 4   // Default length for initial array.

template <class T>
class FlexArray {
  protected:// ------------------------------------------------------------
    int Max;          // Current allocation size.
    int N;            // Number of array slots that contain data.
    T* Data;          // Pointer to dynamic array of T.

  private: // --------------------------------------------------------------
    void grow();      // Double the allocation length.

  public: // ---------------------------------------------------------------
    FlexArray( int ss = FLEX_START ) : Max(ss), N(0), Data( new T[Max] ) {} 
    ~FlexArray() { if (Data != NULL) delete[] Data; }

    int put( T data ); 
    int flexlen() const { return N; }
	inline T&  operator[]( int k ); 
	T* extract() { T* tmp=Data; Data=NULL; return tmp; }
	ostream& print( ostream& out ) const{
        for (int k=0; k<N; ++k) out << Data[k] << "  ";
		return out;
    }
};

// -------------------------------------------- copy a T into the FlexArray.
template <class T> int 
FlexArray<T>::put( T data ) {
    if ( N == Max ) grow();    // Create more space if necessary.
    Data[N] = data;
	return N++;                // Return subscript at which item was stored.
}

//------------------------------------------- access the kth T in the array.
template <class T> inline T& 
FlexArray<T>::operator[]( int k ) {
    if ( k >= N ) fatal( "Flex_array bounds error." );
    return Data[k];               // Return reference to desired array slot.
}
// ------------------------------------- double the allocation length.
template <class T> void 
FlexArray<T>::grow() {
    T* temp = Data;                     // hang onto old data array.
    Max>0 ? Max*=2 : Max = FLEX_START;
    Data = new T[Max];                  // allocate a bigger one.
    memcpy(Data, temp, N*sizeof(T));    // copy info into new array.
    delete temp;                        // recycle (free) old array.
            // but do not free the things that were contained in it.
}
#endif
