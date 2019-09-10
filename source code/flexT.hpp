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

// -----------------------------------------------------------------------------
// flexArray class header                                              flex.hpp
// Example of an abstract data type
// Created by A. Fischer and M. Fischer on September, 2011
// -----------------------------------------------------------------------------

// Template for arrays that can grow.  
// The base type is the template parameters.
// This code works properly with primitive types and pointers to class objects.
// If BT is a class, the operators < and << must be defined.  Further, since 
//    malloc (instead of new) is used to create this structure, the destructors  
//    of the BT objects will not be called.  The STL class vector does not have
//    these limitations.
#pragma once
#include "tools.hpp"
#include <algorithm>

template <class BT> 
class Flex {
private:
    unsigned n;         // The number of objects currently stored in the array.
    unsigned  max;      // The number of array slots currently allocated.
    BT* ar;             // A dynamic array of size==max.
    void grow ();
    
public:
	typedef bool (Compare)( const BT&, const BT&);
    Flex ( int initial=4 );    
    ~Flex ();    
    int  nItems () { return n; }		// Get number of items in the array.
    BT&  operator[]( unsigned  n );		// Subscript with a bounds check.
    void append ( BT d );				// Append to end of array.
    void print ( ostream& out );		// Output the whole array
    void sort ();						// Sort elements of the array
	void sort ( Compare );				// Sort elements of the array
    int  search ( BT d, unsigned k=0 ); // Search for d starting at array[k].
};

//==============================================================================
// -----------------------------------------------------------------------------
// flexArray template implementation                                          
// A. Fischer and M. Fischer, September 2011
//------------------------------------------------------------------------------
// Pre:  There is a newly allocated flexArray.
// Post: The flexarray is internally consistent, empty, and ready to use. 
// Error: An allocation failure throws an exception.
//
template <class BT>
Flex<BT>::Flex( int initial ) {    
    n = 0;
    max = initial;
    ar = (BT*)malloc ( max * sizeof(BT) );
    //cerr <<"New flexArray, size = " <<max <<"\n";
}

template <class BT>
Flex<BT>::~Flex( ) {    
    free( ar );
    //cerr <<"\nDeleting the flexArray, size =" <<max <<"\n";
}

//------------------------------------------------------------------------------
// Pre:  FlexArray is full.
// Post: The length of flexarray has been doubled. 
//       An allocation failure throws an exception.
// Being private prevents this function from being called outside the class.
//
template <class BT>
void Flex<BT>::grow ( ){
    max *= 2;
    ar = (BT*)realloc( ar, max * sizeof(BT) );
    //cerr <<"FlexArray grew, size now =" <<max <<"\n";
}

//------------------------------------------------------------------------------
// Pre:   d is a data object ready to put into the array.
// Post:  d is the last object in the array and n has been incremented.
//        An allocation failure throws an exception.
//
template <class BT>
void Flex<BT>::append ( BT d ){
    if (n == max) grow();            // Enlarge array if it is full.
    ar[n++] = d;                     // Normal case: put data into the array.
}

//------------------------------------------------------------------------------
// Pre:   this-> is an initialized FlexArray.
// Post:  Return a reference to the element at subscript n of the array.
// Error: If n is out of range, a 
template <class BT>
BT& Flex<BT>:: operator[]( unsigned n ){
    if (n >= max) fatal( "Subscript out of bounds." );  
    return ar[n];                    
}

//------------------------------------------------------------------------------
// Pre:  Flexarray has been initialized and might contain data.
// Post: A heading and all data in the flexarray has been displayed on screen.
//
template <class BT>
void Flex<BT>::print ( ostream& out ){
    unsigned k;
    out <<"Array size " <<max <<"; length " << n << "; contents:\n";
    for (k=0; k<n; ++k)  out << ar[k];
}

//------------------------------------------------------------------------------
// Pre:  Flexarray has been initialized and might contain data.
// Post: The data in flexArray is sorted according to the rule for type BT.
//
template <class BT>
void Flex<BT>::sort(){
	std::sort(ar, ar+n);	
}

template <class BT>
void Flex<BT>::sort( Compare cmpFunc ){
    std::sort( ar, ar+n, cmpFunc );	
}
//------------------------------------------------------------------------------
// Pre:  Flexarray has been initialized and might contain data.  
// Post: The data in the flexarray is not changed.
// Return value:  the index of d, if d is in the array.  Otherwise, -1.
//
template <class BT>
int Flex<BT>::search( BT d, unsigned k ){
	BT* offboard = ar+n;
	BT* start = ar+k;
	if (start > offboard) return -1;
	//cerr <<"Starting search at " <<k <<endl;
	BT* found = find( ar+k, offboard, d) ;
	return found == offboard ?  // is iterator past end of array?
		-1 :					// If so, search failed.  Return -1.
		found - ar;             // Else calculate, return index of found item.
}
//------------------------------------------------------------------------------