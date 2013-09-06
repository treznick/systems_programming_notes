// ------------------------------------------------------------------------
// A cell contains an Exam* and a link.  Cells are used to build lists.
// A. Fischer   June 13, 2000        						file: cell.hpp
// ------------------------------------------------------------------------
#ifndef CELL_H
#define CELL_H
#include "item.hpp"
#include <iostream.h>
// ------------------------------------------------------------------------
class Cell {
  friend class Linear;
  friend ostream& operator<<( ostream& out, Cell& c);

  private:	// ------------------------------------------------------------
	Item* data;
   	Cell* next;

	Cell(Item* e = NULL, Cell* p = NULL ): data(e), next(p){ }

	~Cell(){ cerr <<"\n  Deleting Cell 0x" <<this << dec <<"..."; }
	operator Item*() { return data; }  	// Cast Cell to Item*. ------------
	void print(ostream& out) const {    // --------------------------------
		if (data) { 
			out << "Cell 0x" << this; 
			out << " [" << *data << ", " << next << "]\n";
		}
	}
};
inline ostream& operator<<(ostream& out, Cell& c){c.print(out); return out;}
#endif
