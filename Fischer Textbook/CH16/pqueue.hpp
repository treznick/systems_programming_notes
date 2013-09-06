// ------------------------------------------------------------------------
// Priority queues: derived from  Container-<--Linear-<--PQueue	
// A. Fischer   June 9, 2001	                           file: pqueue.hpp
// ------------------------------------------------------------------------
#ifndef PQUEUE_H
#define PQUEUE_H
#include "linear.hpp"

class PQueue : public Linear {
  public:          // -----------------------------------------------------		
	PQueue(){}
	~PQueue(){}
	void focus(){ reset(); }	// Priority queue deletion is at the head.
		 
	// ------------------------ Insert new Cell in ascending sorted order.
	void PQueue::insert( Cell* cp ) { 
		for (reset(); !end(); ++*this) {	// locate insertion spot.
			if ( !(*this < cp) )break;
		}
		Linear::insert( cp ); 				// do the insertion.
	}
};
#endif
