//====================================================================
// BSTree.h 
// 
// This class represents a Binary Search Tree.  
// 
// Author: John Steele <steelejr@u.washinton.edu> 
// Date  : 2010/10/18
// Class : CSS 343
//====================================================================
// Binary class: 
//   Includes following features:
// Assumptions:
//====================================================================

#ifndef _BSTREE_H_
#define _BSTREE_H_

class BSTree {
	
	//========================Default-Constructor=================
	// Creates a BSTree object with a null root.
	// 
	// Preconditions:  None.	
	//
	// Postconditions: This BSTree object has been instantiated.  		  
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
	// Inserts the given Object into this BSTree.
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

};
#endif /* _BSTREE_H */

