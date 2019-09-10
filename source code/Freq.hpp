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
//  Header file for Freq class.                                        Freq.hpp
//  The declaration part of the class
//  Created by Ali Al-Bayaty on Fri Sep 30, 2011
// -----------------------------------------------------------------------------

#pragma once
#include "tools.hpp"
class Tree;

class Freq {
	friend class Tree;
private:
    //  -----------------------------------------------------------------------
    char letter;    // The letter content      
	int percent;    // The frequency of the letter
	Freq* left;     // A pointer to the left Freq object
	Freq* right;    // A pointer to the right Freq object
public:    
    // ---------------------------------------------- Constructor and Destructor	
	Freq(char let='\0', int per=0){
		letter = let;
		percent= per;
		left = right = NULL;
	}
	Freq(Freq* l, Freq* r){
		left = l;
		right= r;
		letter = '\0';
		percent = left->getPercent() + right->getPercent();
	}
	~Freq(){}
    // ------------------------------------------------ Functions and Prototypes
	// Print function:
	ostream& print(ostream& out) {
		return out << setw(3) <<" " << letter << setw(3) << percent; 
	}
	// Accessor function to get the letter:
	char getLetter() { return letter; }
	// Accessor function to get the frequency:
	int getPercent() { return percent; }
};
// ---------------------------------------------- Extension of global operator<<
inline ostream& operator<< (ostream& out, Freq& fr) { 
	return fr.print(out);
}
// -----------------------------------------------------------------------------