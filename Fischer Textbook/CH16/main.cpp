// ------------------------------------------------------------------------
// Demonstration of derived classes with virtual functionL.			
// A. Fischer  June 15, 1998                                file: main.cpp
// ------------------------------------------------------------------------
#include "tools.hpp"
#include "pqueue.hpp"
#include "list.hpp"
#include "item.hpp"
// ------------------------------------------------------------------------
int main( void ) {
  PQueue P;
  List L;
  cerr << "  Print the empty List L.\n" <<L;
  cerr << "\n  Putting 3 items onto List L: 99, 77, 88.\n" ;
  L.put( new Item("Ned", 29) ); 	//cerr << L << endl;
  L.put( new Item("Leo", 37) ); 	//cerr << L << endl;
  L.put( new Item("Max", 18) ); 	  cerr << L << endl;

  cerr << "  Putting 3 items onto PQueue P: 22, 11, 44.\n" ;
  P.put( new Item("Bea",22) ); 		//cerr << P << endl;
  P.put( new Item("Ali",11) ); 		//cerr << P << endl;
  P.put( new Item("Dan",44) ); 		  cerr << P << endl;


  cerr << "  Remove one item from L and queue on P." ;
  P.put( L.pop()) ; 			 

  cerr << "\n  Dequeue one item from P and push onto L." ;
  L.put( P.pop()) ; 			 

  cerr << "\n  Pushing 33 onto P.\n" ;
  cerr << "\n  Peek at P: " << *P.peek() <<" \n"; 
  cerr <<"\n  The list contains: \n" << L;
  P.put( new Item("Cil",33) );  
  cerr <<"\n  The priority queue contains: \n" << P << endl;
  bye();
}
