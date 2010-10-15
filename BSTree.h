//====================================================================
// BSTree.h 
//  
// This class represents a node-based binary search tree data 
// structure, which has the following properties: The left subtree 
// of a node contains only nodes with keys less than the node's key; 
// The right subtree of a node contains only nodes with keys greater
// than the node's key; Both the left and right subtrees must also 
// be binary search trees. 
// 
// Author: John Steele <steelejr@u.washington.edu> 
// Date  : 2010/10/19
// Class : CSS 343 - Lab 2
//====================================================================
// Binary class: 
//   Includes following features:
// 	- allows output << of a BSTree. 
//	- allows insterting an Object into the tree.
//	- allows removing an Object from the tree.
//	- allows retrieving an Object from the tree.
//	- allows getting the depth of a node in the tree.
//	- allows checking if the tree is empty.
//	- allows making the tree empty.
//	- allows getting the number of descendents a node has.
// 	- allows for equality and inequality comparisons of 2 BSTrees.
//	- allows for assignment of 2 BSTrees.
// Assumptions:
//====================================================================

#ifndef _BSTREE_H_
#define _BSTREE_H_
#include <iostream>
#include "Object.h"
using namespace std;


class BSTree {

	//============================================================
	// Overloaded  output operator for BSTree class.
	// 
	// Preconditions: the_bstree.my_root must point to the first
	//		  element of the BSTree, or NULL. 		  
	//
	// Postconditions: The elements of the_bstree are sent to 
	//		   the output using iostream using a frequency
	//		   table format. It uses an in-order traversal
	//		   of the tree and orders them accordting to
	//		   ASCII. The stream is then returned.
	//============================================================ 
	friend ostream& operator<< (ostream &, const BSTree &);


public: 
	//========================Default-Constructor=================
	// Creates a BSTree object with a null root.
	// 
	// Preconditions:  None.	
	//
	// Postconditions: This BSTree object has been instantiated,
	//		   and my_root points to NULL.  		  
	//============================================================ 
	BSTree ();


	//========================Copy-Constructor====================
 	// Copies the_other BSTree object into this.
	// 
	// Preconditions:  the_other.my_root points to NULL or the 
	//		   first Object in the_other's BSTree.
	//
	// Postconditions: the_other is copied into *this.
	//============================================================ 
	BSTree (const BSTree &);	


	//========================Destructor==========================
	// Cleans up and deallocates all dynamic memory. 
	// 
	// Preconditions:  my_root points to NULL or the first Object
	// 		   in this BSTree.	
	//
	// Postconditions: This BSTree memory has been deallocated.
	//============================================================ 
	~BSTree ();
	

	//========================retrieve============================ 
	// Finds the provided object in this tree. Returns NULL if the
	// item is not found.
	// 
	// Preconditions: The Object is not NULL and contains a valid
	// 		  ASCII character.
	//		 
	// Postconditions: Returns a pointer to the Object if found,
	//	 	   a NULL pointer is returned otherwise. 		 
	//============================================================ 
	const Object * retrieve (const Object &) const;	


	//========================depth=============================== 
	// Returns the depth of a character in the tree. The depth
	// of root is 0.
	// 
	// Preconditions: The object should contain a valid ASCII 
	//		  character.		 
	//
	// Postconditions: Returns the depth of the character in this
	//		   tree, returns -1 if not found. 	 
	//============================================================ 
	int depth (const Object &) const;	


	//========================descendents=========================
	// Returns the number of descendents of the node storing the
	// character in the BSTree. A leaf has zero descendents.
	// 
	// Preconditions: Overloaded output operator of Object class
	//		  must be overrided to display the character. 		 
	//
	// Postconditions: Returns the number of Node descendents of
	// 		   the Node storing the provided character.
	//		   Retuns -1 if the object is not found. 		 
	//============================================================ 
	int descendents (const Object &) const;	


	//========================isEmpty=============================
	// Returns true if this BSTree contains no data.
	// 
	// Preconditions: my_root points to NULL or the first Object
	// 		  in this BSTree.   		  
	//
	// Postconditions: returns true if this BSTree contains no
	// 		   data, false otherwise.
	//============================================================ 
	bool isEmpty () const;	


	//========================insert==============================
	// Inserts the given Object into this BSTree. If the character
	// in the object is already in the tree its count is 
	// incremented, and this tree does not take responsibility
	// for the memory of the Object. It it isn't in the tree
	// the tree takes responsibility of the memory of the Object.
	// 
	// Preconditions: my_root points to NULL or the first Object 
	// 		  in this BSTree. Additionally, 
	//		  the_item != NULL.  
	//
	// Postconditions: Returns true if the_item is insterted in 
	//		   this BSTree.False is returned if the char-	
	//		   acter is found, the character count is
	//		   just incremented. This BSTree only takes 
	//		   ownership of the Object if the character
	// 		   is not found.
	//============================================================ 
	bool insert (Object *);	


	//========================remove==============================
	// Removes one occurance of a character from this BSTree. If
	// it is the last occurence, the Object is removed. 
	// 
	// Preconditions: the_item is a reference to a non NULL 
	//		  object. 
	//
	// Postconditions: Returns true if the character is found and
	//		   an occurance of it is removed. If it is the
	//		   last occurence the Object is removed. False
	// 		   is returned if the character is not found. 
	//============================================================ 
	bool remove (const Object &);	


	//========================makeEmpty===========================
	// Deallocates all Objects in this BSTree and sets its 
	// root to NULL, isEmpty() would then return true.
	// 
	// Preconditions: my_root points to NULL or the first Object
	// 		  in this BSTree.   		  
	//
	// Postconditions: All memory has been deallocated, 
	//		   root is NULL.
	//============================================================ 
	void makeEmpty ();	


	//========================operator(=)=========================
	// Overloaded assignment operator.
	// 
	// Preconditions: the_other.my_root points to the first Node
	//		  in the tree, or NULL.
	// 		
	// Postconditions: the_other is copied into this.
	//		   this is then returned.		   
	//============================================================ 
	const BSTree& operator=  (const BSTree &);	


	//========================operator(==)========================
	// Determine if two BSTrees are equal. Two trees are equal 
	// if they have the same data, the same structure, and the
	// same number of occurances for each character.
	// 
	// Preconditions: my_root and the_other.my_root point to the
	//		  first Node in the tree, or NULL.		 
	// 		
	// Postconditions: true is returned if the this and the_other
	//		   tree have the same data, the same structure
	//		   and the same number of occurances for each
	//		   character.		  
	//============================================================ 
	bool operator==  (const BSTree &) const;	


	//========================operator(!=)========================
	// Determine if two BSTrees are not equal. Two trees are not
	// equal if they do not have the same data, or same structure,
	// or same number of of occurances for each character. 
	// 
	// Preconditions: my_root and the_other.my root point to the
	//		  first Node their tree or NULL.
	//		  		
	// Postconditions: false is returned if the trees have the 
	// 		   same data, same structure, and same 
	// 		   number of occurances of each character.
	//		   True otherwise.		  		 
	//============================================================ 
	bool operator!= (const BSTree &) const;	


private:

	// The Node structure in the BSTree.
	struct Node {
		Object *item;   // Object data being stored.
		Node *left;     // Left  child subtree.
		Node *right;    // Right child subtree.
		int occurances; // Occurances of the character.
	};
	
	Node *my_root;	        // The root of this BSTree. 
};
#endif /* _BSTREE_H */

