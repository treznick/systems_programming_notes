//                    -*- mode:c++; tab-width:4 -*-
// modified September 2011, April 2013
// file: tools.hpp ----------------------------------------------------------- 
// header file for the tools library.                                          
// --------------------------------------------------------------------------- 
// Local definitions and portability code.                                     
// Please enter your own system, name, class, and printer stream name.         
// --------------------------------------------------------------------------- 
#pragma once
#define NAME    "Tom Reznick"
#define CLASS   "CS 647"
#define UNIX

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include <cstdio>      // for NULL      
#include <cstdlib>     // for malloc() and calloc()     
#include <cstring>
#include <cmath>      
#include <ctime>        
#include <cctype>      // for isspace() and isdigit()  
#include <cstdarg>     // for functions with variable # of arguments 

#if  defined UNIX
    #include <unistd.h>
#else 
    #include "windows.hpp"
#endif
using namespace std;

// --------------------------------------------------------------------------- 
// Macros for debugging.                                                       
// --------------------------------------------------------------------------- 
#define DUMPp(p) "\n" <<"    " #p " @ " <<&p <<"    value = " <<p <<"    " #p " --> " <<*p 
#define DUMPv(k) "\n" <<"    " #k " @ " <<&k <<"    value = " <<k 

// --------------------------------------------------------------------------- 
// I/O Extension. ------------------------------------------------------------ 
// --------------------------------------------------------------------------- 
istream& cleanline( istream& is );     // discards remainder of line
istream& flush( istream& is );         // Use: cin >> x >> flush;
ostream& general( ostream& os );       // Use: cout <<fixed <<x <<general <<y;

// --------------------------------------------------------------------------- 
// Routine screen and process management.------------------------------------- 
// --------------------------------------------------------------------------- 
void     fbanner( ostream& fout );
void     banner();
void     bye( void );                                    
void     hold( void );                                    
void	 delay( int seconds );
void     say( const char* format, ... );

// --------------------------------------------------------------------------- 
// Error handling. ----------------------------------------------------------- 
// --------------------------------------------------------------------------- 
void    fatal( const char* format, ... );

// --------------------------------------------------------------------------- 
// time and date. -------------------------------------------------------------
// --------------------------------------------------------------------------- 
void   when( char* date, char* hour );
char*  today( char* date );
char*  oclock( char* hour );

// --------------------------------------------------------------------------- 
// Menu handling.                           
// --------------------------------------------------------------------------- 
int    menu( char* title, int n, const char* menu[] );                                                      
char   menu_c( char* title, int n, const char* menu[], char* valid );
