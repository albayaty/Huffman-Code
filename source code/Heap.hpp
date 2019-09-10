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

//  ----------------------------------------------------------------------------
//  Header file for Heap class.                                        Heap.hpp
//  The declaration part of the class
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
// -----------------------------------------------------------------------------

#pragma once
#include "flexT.hpp"
#include "Freq.hpp"

class Heap{
private:
	//  -----------------------------------------------------------------------
	Flex<Freq> heap, heap_pnt;   // FlexArray of Freq objects to build the heap
	int counter;                 // To count the actual slots in the FlexArray
public:
	// ---------------------------------------------- Constructor and Destructor
	Heap(){ 
		counter = 0;          // Init. the counter
		heap.append(Freq());  // Add a dummy node in slot 0	of the heap (FlexArray)
	}
	~Heap(){}
	// ------------------------------------------------ Functions and Prototypes
	void upHeap( int k );        // To achieve the upHeap algorithm after addition
	void add( Freq x );          // To add Freq object to the heap
	void downHeap( int k );      // To achieve the downHeap algorithm after removing
	Freq remove();               // To remove Freq object from the heap
	ostream& print(ostream& out); // Printing the heap structure
	int getCount() { return counter; }  // To get the actual size of the heap
	Freq* getTree() { return &heap[1];} // To get the last (first) node in the heap
};
// ---------------------------------------------- Extension of global operator<<
inline ostream& operator<< (ostream& out, Heap& hp) { 
	return hp.print(out);
}