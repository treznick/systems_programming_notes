//#include "CSList.h"
#include "CSList.h"

int main ( void ) {
    banner();
    Person* pp = new Person("   ", INT_MAX);    // A sentinel value for the dummy cell.
    CSList cs(pp);
    cs.insert( new Person("ABC", 55) );
    cs.print( cout );
    cs.insert( new Person("FGH", 88) );
    cs.insert( new Person("JKL", 94) );
    cs.print( cout );
    cs.insert( new Person("MNO", 31) );
    cs.insert( new Person("PQR", 79) );
    cs.insert( new Person("STU", 68) );
    cs.print( cout );
    bye();
    return 0;
}
/* -------------------------------------------------------------------
----------------------------------------------------------------
	Alice E. Fischer
	CS 626
	Fri Mar  3 2006	23:01:27
----------------------------------------------------------------
1 node:  ABC 55   
3 nodes: ABC 55   FGH 88   JKL 94   
6 nodes: MNO 31   ABC 55   STU 68   PQR 79   FGH 88   JKL 94   

    Normal termination.
    Deleting Person MNO
    Deleting Person ABC
    Deleting Person STU
    Deleting Person PQR
    Deleting Person FGH
    Deleting Person JKL
    Deleting Person     

    CSList has exited with status 0.
------------------------------------------------------------------- */
