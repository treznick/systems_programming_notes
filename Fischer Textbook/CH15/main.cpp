// ------------------------------------------------------------------------
// Demonstration of derived classes with virtual functions.
// A. Fischer  June 15, 1998                                 file: main.cpp
// ------------------------------------------------------------------------
#include "tools.hpp"
#include "exam.hpp"		// Must precede #include for item.hpp.
#include "item.hpp"		// Abstract base type for stacks and queues.
#include "stack.hpp"	// Base type is Item == Exam.
#include "queue.hpp"	// Base type is Item == Exam.
// ------------------------------------------------------------------------
int main( void ) {
    Stack S;
    Queue Q;

    cerr << "\nPutting 3 items on the Stack S: 99, 88, 77.\n" ;
    S.put( new Exam("Ned", 99) );       //cerr << S << endl;
    S.put( new Exam("Max", 88) );       //cerr << S << endl;
    cerr << "  Peeking after second insertion: " <<*S.peek() <<"\n";
    S.put( new Exam("Leo",77) );          cerr << S << endl;

    cerr << "Putting 3 items on the Queue Q: 11, 22, 33.\n";
    Q.put( new Exam("Ali",11) );        //cerr << Q << endl;
    Q.put( new Exam("Bea",22) );        //cerr << Q << endl;
    cerr << "  Peeking after second insertion: " <<*Q.peek() <<"\n";
    Q.put( new Exam("Cil",33) );          cerr << Q << endl;

    cerr << "Pop two Exams from Q, put on S. \n";
    S.put(Q.pop()); S.put(Q.pop());       cerr <<"\n" <<S << endl;

    cerr << "Put another Exam onto Q: 44.\n";
    Q.put( new Exam("Dan",44) );          cerr << Q << endl;

    cerr << "Pop two Exams from S and discard.\n";
    delete S.pop(); 
	delete S.pop();                       cerr <<"\n" << S << endl;
    bye();
}
