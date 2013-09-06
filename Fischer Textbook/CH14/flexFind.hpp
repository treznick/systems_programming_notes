//--------------------------------------------------------------------------
// A variant of the FlexArray that supports sequential search.   
// This class relies on an etension of == in class T to compare two T's.             
//--------------------------------------------------------------------------
template <class T> 
class FlexFind : public FlexArray<T> {
  public:
    FlexFind(int ss = FLEX_START): FlexArray<T>(ss){} 

	bool find( const T key ) const{
        int k;
        for (k=0; k<N; ++k) {
            if (Data[k] == key) return true;
        }
        return false;
    }
};

