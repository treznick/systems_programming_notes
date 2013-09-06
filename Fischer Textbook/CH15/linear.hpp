// --------------------------------------------------------------------------
// Linear Containers              
// A. Fischer June 12, 2001						    	     file: linear.hpp
// --------------------------------------------------------------------------
#ifndef LINEAR_H
#define LINEAR_H
#include "contain.hpp"
#include "cell.hpp"
#include "tools.hpp"

class Linear: public Container {
  protected: // -------------------------------------------------------------
  	Cell* head;		 // This is a dummy header for the list.

  private:   // -------------------------------------------------------------
	Cell* here;    	 // Cursor for traversing the container.
	Cell* prior;   	 // Trailing pointer for traversing the container.

  protected: // -------------------------------------------------------------
  	        Linear(): head(new Cell), here( NULL ), prior( head ) {}
	virtual ~Linear (); 
	        void  reset()	 		{ prior = head; here = head->next; }
  	        bool  end() const 		{ return here == NULL; }
	        void  operator ++(); 

	virtual void  insert( Cell* cp ); 
	virtual void  focus() = 0;		 
			Cell* remove();  	    
		    void  setPrior(Cell* cp){ prior = cp; here = prior->next; }

  public:	// --------------------------------------------------------------	
			void     put(Item * ep)	{ if (ep) insert( new Cell(ep) ); }
			Item*    pop();
  	        Item*    peek() 		{ focus(); return *here; }
	virtual ostream& print( ostream& out );
};
inline ostream& operator<<(ostream& out, Linear& s) {return s.print(out); }
#endif
