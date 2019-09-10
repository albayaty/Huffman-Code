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
//  Code file for Tree class.                                          Tree.cpp
//  The implementation part of the class
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
// -----------------------------------------------------------------------------

#include "tree.hpp"
/*
// -----------------------------------------------------------------------------
Tree::~Tree() { deleteRecursive(root); }
// -----------------------------------------------------------------------------
// Recursice delete for the tree's nodes:
void Tree::deleteRecursive( Freq* scan ) {
	if (scan == NULL) return;
	deleteRecursive( scan->left );
	deleteRecursive( scan->right);
	delete scan;
} */
// -----------------------------------------------------------------------------
// Infix traversal printing of the tree:
void Tree::print( ostream& out, Freq* scan ) {	
    if (scan == NULL)  return;
	out <<"(";
    print( out, scan->left );
	out << scan->getLetter() << ":";
	out << scan->getPercent();
    print( out, scan->right );
    out <<")";
}
// -----------------------------------------------------------------------------
// Printing tree structure:
void Tree::print( ostream& out ) {   
    out <<"\n\nInfix traversal printing, tree holds:\n\n";
    print( out, root );
    cerr <<"\n\nDone printing tree\n";
}
// -----------------------------------------------------------------------------
// Depth-first traversal of the tree:
void Tree::codeRecursive( ostream& out, Freq* scan ){
	if ( scan == NULL )	return;
	// Printing the letter with its code:
	if ( scan != NULL && (scan->getLetter() != '\0') ){
		out << "   " << scan->getLetter() << "    " << str << endl;
		codes += scan->getLetter(); codes += ": "; codes += str; codes += '\n';
	}
    str += '0';
    codeRecursive( out, scan->left );
	str.erase(str.end()-1);
	str += '1';
    codeRecursive( out, scan->right );
	str.erase(str.end()-1);
}
// -----------------------------------------------------------------------------
// Sending Huffman code to output file:
string& Tree::code( ostream& out ){
	//out << "\nHuffman Code for the letters: \n";
	//out << "\nDepth-first traversal of the tree: \n";
    codeRecursive( out, root );
    //cerr << "\nDone printing Tree\n";
	return codes;
}
// -----------------------------------------------------------------------------