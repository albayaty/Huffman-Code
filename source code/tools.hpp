/* ==============================================
*  Copyright ©  2014  Ali M. Al-Bayaty
*  
*  Huffman Code is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  any later version.
*  
*  Huffman Code is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*  
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/* ==============================================
*  
*  Huffman Code
*  
*  MSEE Student: Ali M. Al-Bayaty
*  Instructor: Dr. Alice Fischer
*  CS 620: Data Structures
*  Personal Website: <http://albayaty.github.io/>
*
*  ==============================================
*/

//					-*- mode:c++; tab-width:4 -*-
// File: tools.hpp - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Header file for the C++ tools library.
// Created by Alice Fischer
// Modified on January, 2009
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef TOOLSPP_H
#define TOOLSPP_H
// -------------------------------------------------------------------
// Local definitions and portability code.
// Please enter your own system, name, class, and printer stream name.
// -------------------------------------------------------------------
//#define UNIX
#define VISUAL
#define NAME    "Instructor: Dr. Alice Fischer, Student: Ali Al-Bayaty"
#define CLASS   "CS 620 (01) Data Structures"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <stdio.h>      // for NULL 
#include <stdlib.h>     // for malloc() and calloc()
#include <string.h>     // for time_t, time() and ctime()
#include <math.h>
#include <time.h>
#include <ctype.h>      // for isspace() and isdigit() 
#include <limits.h>     // for INT_MAX 
#include <float.h>      // for DOUBLE_MAX, etc. 
#include <stdarg.h>     // for functions with variable # of arguments 

using namespace std;

typedef char* cstring;
typedef FILE* cstream;

// -------------------------------------------------------------------
// Macros to make more convenient use of standard library functions.
// -------------------------------------------------------------------
#define DUMPp(p) "\n"<<hex<<"   " #p " @ "<<(unsigned)&p<<"   value = "<<(unsigned)p<<"   " #p " --> "<<dec<<*p
#define DUMPv(k) "\n"<<hex<<"   " #k " @ "<<(unsigned)&k<<"   value = "<<dec<<k

// -------------------------------------------------------------------
// Portable definitions; these require user to #define name of local system.
// -------------------------------------------------------------------
void    clearscreen( void );
void    bye( void );

// -------------------------------------------------------------------
// Routine screen and process management.-----------------------------
// -------------------------------------------------------------------
void     fbanner( ostream& fout );
#define  banner()  fbanner( cout )
void     delay( int );
void     hold( void );
void     say( cstring format, ... );

// -------------------------------------------------------------------
// I/O Extension. ---------------------------------------------------- 
// -------------------------------------------------------------------
istream&  flush( istream& is );   // Used in cin >>x >>flush;

// -------------------------------------------------------------------
// Error handling. ---------------------------------------------------
// -------------------------------------------------------------------
void    fatal( cstring format, ... );

// -------------------------------------------------------------------
// Time and date. ----------------------------------------------------
// -------------------------------------------------------------------
void     when( cstring date, cstring hour );
cstring  today( cstring date );
cstring  oclock( cstring hour );

#endif // ifndef TOOLSPP_h
