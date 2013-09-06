/*  ----------------------------------------------------------------------------
//  Main program for Sorting DataPacks in C++.                         main.cpp
//  Created by Alice Fischer on September 8, 2011.
*/
#include "tools.hpp"
#include "pack.hpp"

void test(){
    cout << "\nTesting constructor and getData.  Use file name 'numbers.txt'\n" 
    << "User should see that 12 items have been read.\n";
    cout << "Enter name of data file: ";
    char filename[80];      // For name of input file 
    cin.getline( filename, 80 );
    DataPack theData(20);
    theData.getData( filename );
    cout <<theData.nItems() <<" items read.\n";       
        
    cout << "\nTesting print. User should see numbered items, not sorted.\n";
    theData.print( cerr );
    
    cout << "\nTesting sort and <<. User should see same items, sorted.\n";
    theData.sort();
    cout << theData;  
}

int main( void ) {
    banner();
    test();  
    bye();
    return 0;
}

/*----------------------------------------------------------------
 Alice Fischer
 CS 620
 Thu Sep  8 2011 12:04:23
 ----------------------------------------------------------------
 
 Testing constructor and getData.  Use file name 'numbers.txt'
 User should see that 11 items have been read.
 Enter name of data file: numbers.txt
 12 items read.
 
 Testing print. User should see 11 items, not sorted.
 0.      30
 1.      43
 2.      67
 3.      45
 4.      -12
 5.      543
 6.      68
 7.      90
 8.      23
 9.      43
 10.     55
 11.     62
 
 Testing sort and <<. User should see same items, sorted.
 0.      -12
 1.      23
 2.      30
 3.      43
 4.      43
 5.      45
 6.      55
 7.      62
 8.      67
 9.      68
 10.     90
 11.     543
 
 Normal termination.
 ---------------------------------------------------------------*/

