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
//  Main program for Huffman Algorithm in C++                          main.cpp
//  Created by Ali Al-Bayaty on Tue Dec 13, 2011
//  ----------------------------------------------------------------------------

#include "Huffman.hpp"

int main( void ) {
	
	// Information message:
	banner();
	
	// Creating Huffman object:	
	Huffman obj;
	
	// Implementing Huffman algorithm with run():
	obj.run();
	
    bye();
	return 0;
}
//  ----------------------------------------------------------------------------