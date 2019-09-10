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
//  Header file for Huffman class.                                  Huffman.hpp
//  The declaration part of the class
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
// -----------------------------------------------------------------------------

#pragma once
#include "Freq.hpp"
#include "flexT.hpp"
#include "Tree.hpp"
#include "Heap.hpp"

class Huffman {
private:
	//  -----------------------------------------------------------------------
	Freq* storage;          // Temp Freq object for delete-delete-build-insert
	Flex<char> message;     // To store the characters from the input file
	ifstream fin;           // The input file
	ofstream fout;          // The output file 
	int counter[256];       // To calculate the frequency of each input letter
	Heap heap;              // The heap that construct the Huffman code
	Tree tree;              // The tree that form the Huffman code
	// Private functions:
	void tally();	        // To count the frequency of the input letters
	void phase1(const char* filename); // Phase 1 of the Huffman code algorithm
	void phase2();					   // Phase 2 of the Huffman code algorithm
	void phase3();					   // Phase 3 of the Huffman code algorithm
	void phase4();					   // Phase 4 of the Huffman code algorithm
public:
	// ---------------------------------------------- Constructor and Destructor
	Huffman();
	~Huffman(){ delete[] storage; }
	// ------------------------------------------------ Functions and Prototypes		
	void run(const char* filename = "input.txt");  // To invoke the above phases
};
// -----------------------------------------------------------------------------