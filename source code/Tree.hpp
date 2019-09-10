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
//  Header file for Tree class.                                        Tree.hpp
//  The declaration part of the class
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
// -----------------------------------------------------------------------------

#pragma once
#include "Freq.hpp"

class Tree { 
private:  
	//  -----------------------------------------------------------------------
    Freq* root;	       // The top (first) node in the tree structure
	string str;        // To print the node's letter & frequency on screen
	string codes;      // To send the node's letter & frequency to utput file
	//void deleteRecursive( Freq* scan );  // Recursice delete for the tree's nodes
	void codeRecursive( ostream& out, Freq* scan );  // To save the Huffman code
	void print( ostream& out, Freq* scan );   // Infix traversal printing of the tree

public: 
	// ---------------------------------------------- Constructor and Destructor	
	Tree(){ root = NULL; str.clear(); } 
	~Tree(){}         // No need for recursive deletion for the nodes, because 
	                  // the heap temp storage was already deleted from Heap class
	// ------------------------------------------------ Functions and Prototypes
	void addNode( Freq* node ) { root = node; } // Adding heap's first node to the tree
    void print( ostream& out );                 // Printing tree structure
	string& code( ostream& out );               // Sending Huffman code to output file
};
// -----------------------------------------------------------------------------