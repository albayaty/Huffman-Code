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
//  Code file for Heap class.                                          Heap.cpp
//  The declaration part of the class
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
// -----------------------------------------------------------------------------

#include "Heap.hpp"

// -----------------------------------------------------------------------------
// To achieve the upHeap algorithm after addition:
void Heap::upHeap( int k ){
	int parent;   // location of the parent's son
	Freq swap;

	for(; k > 1 ;){       // Checking all the slots except the first one
		parent = k/2;     // The position of the parent of slot k
		if( heap[k].getPercent() < heap[parent].getPercent() ){
			// Swapping the objects:
			swap = heap[parent];
			heap[parent] = heap[k];
			heap[k] = swap;
		}
		k = parent;
	}
}
// -----------------------------------------------------------------------------
// To add Freq object to the heap:
void Heap::add( Freq x ){
	bool addition = false;    // A flag for a normal addition or for 
	                          // delete-delete-build-insert process
	counter++;                // Current slot in the heap 
	// Addition for delete-delete-build-insert process:
	for( int k=1 ; k<heap.nItems() ; k++){
		if( heap[k].getPercent() == 0 ){
			heap[k] = x;
			addition = true;
			break;
		}
	}
	// Normal addition:
	if( !addition )
		heap.append(x);
	// Apply the upHeap algorithm after addition for the current slot:
	upHeap(counter);
}
// -----------------------------------------------------------------------------
// To achieve the downHeap algorithm after removing:
void Heap::downHeap( int k ){
	int left, right, small;   // The positions of the two sons of slot k
	Freq swap;

	for(; k <= counter/2 ;){  // Checking all the slots from the first till the middle		                      
		// Protection Circuits (to prevent the swapping with the empty slots):
		left = right = k;
		if( heap[k*2].getPercent()>0 )    { left = k*2; right = left; }
		if( heap[left+1].getPercent()>0 ) right= left+1;
		// Checking for the smallest son:
		small = left;
		if( heap[left].getPercent() > heap[right].getPercent() )
			small = right;			
		// Swapping the objects:
		if( heap[k].getPercent() > heap[small].getPercent() ){
			swap = heap[k];
			heap[k] = heap[small];
			heap[small] = swap;
			k = small;
		}
		else 
			break;
	}
}
// -----------------------------------------------------------------------------
// To remove Freq object from the heap:
Freq Heap::remove(){
	Freq node = heap[1];      // Saving the removed node from the heap
	heap[1] = heap[counter];  // Swapping
	heap[counter] = Freq();   // Adding dummy node to the swapped object
	counter--;
	// Apply the downHeap algorithm after removing the first slot:
	downHeap(1);
	// Returning the removed node from the heap:
	return node;
}
// -----------------------------------------------------------------------------
// Printing the heap structure:
ostream& Heap::print(ostream& out){	
	out << "\nHeap Slot: ";	
	for( int k=1 ; k<heap.nItems() ; k++ )	out << "  " << k;
	out << "\nLetter:    ";
	for( int k=1 ; k<heap.nItems() ; k++ )	out << "  " << heap[k].getLetter();	
	out << "\nFrequency: ";
	for( int k=1 ; k<heap.nItems() ; k++ )	out << "  " << heap[k].getPercent();
	out << endl;
	return out;
}
// -----------------------------------------------------------------------------
