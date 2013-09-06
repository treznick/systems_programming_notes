// -------------------------------------------------------------------------
// Queues: derived from  Container-<--Linear-<--Queue					      
// A. Fischer   June 9, 2001	                             file: queue.hpp
// -------------------------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H
#include "linear.hpp"

// -------------------------------------------------------------------------
class Queue : public Linear {
  private:
  	Cell* 	tail;

  public:          	// -----------------------------------------------------		
	Queue() { tail = head; }
	~Queue(){}

	void  insert( Cell* cp ) { setPrior(tail); Linear::insert(cp); tail=cp;}
	void  focus(){ reset(); }		 
}; 
#endif
