/*
 *  CSList.cpp
 *  CSList
 */
#include "CSList.h"

//------------------------------------------------------ destructor
CSList::~CSList(){
    Node* temp;             
    Node* scan = next;      // Start deleting with first data node.
    while( scan != this ) { // Stop when you reach the tail.
        temp = scan;
        scan = scan->next;
        delete temp;
    }   // Dummy node will be deleted when list is deleted.
}

//------------------------------------------------------------ find
void CSList::find( const T* key) {
    follow = this;
    scan = next;
    while ( 0 < key->compare( scan->data) ){
        follow=scan;        // Move down the list.
        scan=scan->next;    // Stop when you find something >= key.
    }
}

//---------------------------------------------------------- insert
void CSList::insert(  T* newData ){
    find( newData );
    follow->next = new Node( newData, scan );
    ++count;
}

//----------------------------------------------------------- print
ostream& CSList::print( ostream& out ){
    const char* word = (count==1)? " node:  " : " nodes: ";
    out << count << word;
    for (Node* temp = next; temp != this; temp=temp->next ) temp->print( out );
    return out << endl; 
}    



