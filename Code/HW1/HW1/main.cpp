//
//  main.cpp
//  HW1
//
//  Created by Tom Reznick on 9/10/13.
//  Copyright (c) 2013 Tom Reznick. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    ofstream myOut ( "TomP1.txt", ios::out | ios::app ); //outfile stream
    string commandName = argv[0]; //name of command
    
    //first print dashes and command name to file
    
    myOut << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    myOut << "command\t" << commandName << endl;
    cout << "command\t" << commandName << endl;
    
    //then check for switches and write to file accordingly
    for (int j = 1; j < argc; j++) {
        if (strncmp(&argv[j][0],"-",1) == 0) {
            myOut << "switch\t" << argv[j] << endl;
            cout << "switch\t" << argv[j] << endl;
        } else {
            myOut << "argument\t" << argv[j] << endl;
            cout << "argument\t" << argv[j] << endl;
        }
    }
    
    myOut.close();
    
    return 0;
}

/*
 Test e) redirects stdout to a file mytemp.txt, which means that its output will not appear on
 the console, but will appear in mytemp.txt and TomP1.txt
 
 Test f) passes two glob statements *.bak and *.log as arguments to this program, which the shell
 expands, in the case of *.bak to all of the .bak files in the CWD. As there are no .log files in
 the CWD, *.log expands to nothing, which is evidenced in the output to stdout and to TomP1.txt.
*/