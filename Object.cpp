//====================================================================
// Object.cpp 
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

#include "Object.h"


//========================Constructor=================================
// Creates an Object with the specified character.
// 
// Preconditions:  None.	
//
// Postconditions: my_char is set to the_char.
//====================================================================
Object::Object (char the_char)
{
	my_char = the_char;
}


//========================Copye-Constructor===========================
// A simple copy constructor.
// 
// Preconditions:  None.	
//
// Postconditions: my_char is set to the_other.my_char
//====================================================================
Object::Object (const Object &the_other)
{
	// Calls our overloaded operator=.
	*this = the_other;
}

//========================operator(=)=================================
// Overloaded assignment operator.
// 
// Preconditions: 		 
// 		
// Postconditions: the_other is copied into this.
//		   this is then returned.		 
//====================================================================
const Object& Object::operator=  (const Object &the_other)	
{
	my_char = the_other.my_char;
	return *this;
}


//========================operator(==)================================
// Determine if two Objects are equal. Two Object are equal if they
// have the same character. 
//
// Preconditions: none. 		 
// 		
// Postconditions: true is returned if the this and the_other Object 
//		   have the same character. false otherwise.
//====================================================================
bool Object::operator==  (const Object &the_other) const	
{
	return (my_char == the_other.my_char);
}


//========================operator(!=)================================
// Determine if two Objects are not equal. Two Objects are not equal 
// if they d not have the same character. 
// 
// Preconditions: none.
//				  		
// Postconditions: false is returned if the Objects have the same
// 		   character. Returns true otherwise.		  		 
//==================================================================== 
bool Object::operator!= (const Object &the_other) const	
{
	return !(*this == the_other);
}


//========================operator(<)=================================
// Overloaded comparison operator. Compares this Object with the_other
// for less than value. If the value of this my_char is less than 
// the_other.my_char it returns true. Valus are compared based on
// their ASCII value. 
// 
// Preconditions: none.
//				  		
// Postconditions: Returns true if the ASCII value of my_char is less
// 		   than the ASCII value of the_other.my_char.
//		   Returns false otherwise. 		 
//====================================================================
bool Object::operator< (const Object &the_other) const
{
	return (my_char < the_other.my_char);
}


//========================operator(>)=================================
// Overloaded comparison operator. Compares this Object with the_other
// for greater than value. If the value of this my_char is greater 
// than the_other.my_char it returns true. Valus are compared based
// on their ASCII value. 
// 
// Preconditions: none.
//				  		
// Postconditions: Returns true if the ASCII value of my_char is 
//		   greater than the ASCII value of the_other.my_char. 
//		   Returns false otherwise. 		 
//==================================================================== 
bool Object::operator> (const Object &the_other) const
{
	return (my_char > the_other.my_char);
}	



//====================================================================
// Overloaded  output operator for Object class.
// 
// Preconditions: none.
//	
// Postconditions: my_char is sent to output using iostream, output
//		   is then returned.		 			
//==================================================================== 
ostream& operator<< (ostream &output, const Object &the_other)
{
	output << the_other.my_char;
	return output;
}

