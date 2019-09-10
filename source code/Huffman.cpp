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
//  Code file for Huffman class.                                    Huffman.hpp
//  The implementation part of the class
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
// -----------------------------------------------------------------------------

#include "Huffman.hpp"

// -----------------------------------------------------------------------------
Huffman::Huffman(){	
	// To clear the counter:
	//for(int k=0;k<256;k++)  counter[k]=0;
	memset(counter, 0, 256);
}
// -----------------------------------------------------------------------------
// To count the frequency of the input letters:
void Huffman::tally(){	
	// To count the frequencies:
	for(int k=0 ; k<message.nItems() ; k++ )
		counter[message[k]-'0']++;

	// To add the non-zero frequency to the heap:
	for(int k=0 ; k<256 ; k++ ){
		if( counter[k]>0 )	heap.add(Freq(k+'0', counter[k]));
	}
}
// -----------------------------------------------------------------------------
// Phase 1 of the Huffman code:
void Huffman::phase1(const char* filename){
	cout << "\n\n<<< Phase1  >>>";
	cout << "\n---------------\n";
	char ch;
	fin.open(filename);
	if( !fin ) fatal("ERROR: Can not open the input file ...");
	
	for(;;){
		ch = fin.get();
		if( fin.eof() )  break;
		message.append(ch);
	}
	fin.close();
	// Printing the letters from the input file:
	message.print(cout);
}
// -----------------------------------------------------------------------------
// Phase 2 of the Huffman code:
void Huffman::phase2(){
	cout << "\n\n<<< Phase2 >>>";
	cout << "\n---------------";
	tally();
	// Printing the heap contents:
	cout << heap;
}
// -----------------------------------------------------------------------------
// Phase 3 of the Huffman code:
void Huffman::phase3(){
	cout << "\n\n<<< Phase3 >>>";
	cout << "\n---------------";
	int loc = 0;     // Location for dynamically Temp Freq object during the
	                 // delete-delete-build-insert process
	int total = heap.getCount() *2;  // By 2, because of the binary tree of Huffman
	storage = new Freq[total];
		
	// Loop for the actual size of the heap and not the total size ( nItem() ):
	for( ;heap.getCount() > 1; ){
		cout << "\n(1) Before Removing the left and right nodes from the heap:";
		cout << heap;
		Freq left = heap.remove();   // Get the removed Freq as left
		storage[loc] = left;         // Store the removed node
		Freq right= heap.remove();   // Get the removed Freq as right
		loc++;
		storage[loc] = right;        // Store the removed node
		// Creating Freq object with the removed left and right Freq objects:
		Freq node( &storage[loc-1], &storage[loc] );  		                                              
		cout << "\n(2) After Removing the left and right nodes from the heap:";
		cout << heap;
		heap.add(node);     // Adding the new created Freq object to the heap
		cout << "\n(3) After Adding the node that contains left and right into the heap:";
		cout << heap;
		loc++;
		cout << setw(70) << setfill('-') << ' ' << endl << setfill(' ');
	}
	/*	
	// A test to display the associated memory addresses/links with the nodes in the storage buffers:
	for(int k=0; storage[k].getPercent() ; k++)
		cout << "(Mem Address: " << &storage[k] << ") Freq Content:" << storage[k] << ", Left:" << storage[k].left << ", Right:" << storage[k].right << "\n\n";	
	*/
	// Adding the remaining node in the heap to the tree object, and printing the tree:
	tree.addNode( heap.getTree() );
	tree.print(cout);
}
// -----------------------------------------------------------------------------
// Phase 4 of the Huffman code:
void Huffman::phase4(){
	cout << "\n\n<<< Phase4 >>>";	
	cout << "\n---------------\n";
	string codes;
	fout.open("codes.txt");
	if( !fout ) fatal("ERROR: Can not open the output file ...");
	// Print and get the Huffman codes for each letter:
	cout << "Letter  Code\n";
	cout << "------  ----\n";
	codes = tree.code(cout);
	cout << "\n\n<<< The Huffman code for each letter are written to \"codes.txt\" file >>>\n";
	fout << "The Huffman code for each letter:\n";
	fout << codes;
	fout << "\nDone ...\n";
	fout.close();
}
// -----------------------------------------------------------------------------
// To invoke the above phases:
void Huffman::run(const char* filename){
	phase1(filename);
	phase2();
	phase3();
	phase4();	
}
// -----------------------------------------------------------------------------