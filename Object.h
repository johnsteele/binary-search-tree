//====================================================================
// Object.h 
//  
// This class represents an Object class that stores a character as 
// its data member. Simple operations can be done with it such as
// output, assignmet, and comparison.
//
// Author: John Steele <steelejr@u.washington.edu> 
// Date  : 2010/10/19
// Class : CSS 343 - Lab 2
//====================================================================
// Object class: 
//   Includes following features:
// 	- allows output << of the Object. 
// 	- allows for assignment of 2 Objects.
//	- allows comparisons (< and >) of an Object.	
//	- allows for equality and inequality comparisons of 2 Objects.
// Assumptions:
//====================================================================

#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <iostream>
using namespace std;

class Object {

	//============================================================
	// Overloaded  output operator for Object class.
	// 
	// Preconditions: none.
	//	
	// Postconditions: my_char is sent to output using iostream.		 			
	//============================================================ 
	friend ostream& operator<< (ostream &, const Object &);

public:

	//========================Constructor=========================
	// Creates an Object with the specified character.
	// 
	// Preconditions:  None.	
	//
	// Postconditions: my_char is set to the_char.
	//============================================================ 
	Object (char);


	//========================Copye-Constructor===================
	// A simple copy constructor.
	// 
	// Preconditions:  None.	
	//
	// Postconditions: my_char is set to the_other.my_char
	//============================================================ 
	Object (const Object &);


	//========================operator(=)=========================
	// Overloaded assignment operator.
	// 
	// Preconditions: 		 
	// 		
	// Postconditions: the_other is copied into this.
	//		   this is then returned.		 
	//============================================================ 
	const Object& operator=  (const Object &);	


	//========================operator(==)========================
	// Determine if two Objects are equal. Two Object are equal
	// if they have the same character.
	// 
	// Preconditions: none. 		 
	// 		
	// Postconditions: true is returned if the this and the_other
	//		   Object have the same character. 
	//		   false otherwise.
	//============================================================ 
	bool operator==  (const Object &) const;	


	//========================operator(!=)========================
	// Determine if two Objects are not equal. Two Objects are 
	// not equal if they d not have the same character. 
	// 
	// Preconditions: none.
	//				  		
	// Postconditions: false is returned if the Objects have the 
	// 		   same character. True otherwise.		  		 
	//============================================================ 
	bool operator!= (const Object &) const;	


	//========================operator(<)========================
	// Overloaded comparison operator. Compares this Object with
	// the_other for less than value. If the value of this 
	// my_char is less than the_other.my_char it returns true.
	// Valus are compared based on their ASCII value. 
	// 
	// Preconditions: none.
	//				  		
	// Postconditions: Returns true if the ASCII value of my_char
	// 		   is less than the ASCII value of the_other.
	//		   my_char. Returns false otherwise. 		 
	//============================================================ 
	bool operator< (const Object &) const;	


	//========================operator(>)========================
	// Overloaded comparison operator. Compares this Object with
	// the_other for greater than value. If the value of this 
	// my_char is greater than the_other.my_char it returns true.
	// Valus are compared based on their ASCII value. 
	// 
	// Preconditions: none.
	//				  		
	// Postconditions: Returns true if the ASCII value of my_char
	// 		   is greater than the ASCII value of
	//		   the_other.my_char. Returns false otherwise. 		 
	//============================================================ 
	bool operator> (const Object &) const;	

private:
	
	char my_char;      // The character this object holds.
}; 
#endif /* _OBJECT_H_ */

