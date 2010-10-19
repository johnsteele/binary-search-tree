//====================================================================
// BSTree.cpp 
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
#include "BSTree.h"


//========================Default-Constructor=========================
// Creates a BSTree object with a null root.
// 
// Preconditions:  None.	
//
// Postconditions: This BSTree object has been instantiated, and
//		   my_root points to NULL.  		  
//==================================================================== 
BSTree::BSTree () 
{
	my_root = NULL;
}


//========================Copy-Constructor============================
// Copies the_other BSTree object into this.
// 
// Preconditions:  the_other.my_root points to NULL or the first 
//		   Object in the_other's BSTree.
//
// Postconditions: the_other is copied into *this.
//====================================================================
BSTree::BSTree (const BSTree &the_other)	
{	
	my_root = NULL;
	*this = the_other;
}


//========================Destructor==================================
// Cleans up and deallocates all dynamic memory. 
// 
// Preconditions:  my_root points to NULL or the first Object in
//		   this BSTree.	
//
// Postconditions: This BSTree memory has been deallocated.
//====================================================================
BSTree::~BSTree() 
{
	makeEmpty();
}



//========================retrieve==================================== 
// Finds the provided object in this tree. Returns NULL if the item
// is not found.
// 
// Preconditions: The Object is not NULL and contains a valid 
//		  ASCII character.
//		 
// Postconditions: Returns a pointer to the Object if found,
//	 	   a NULL pointer is returned otherwise. 		 
//==================================================================== 
const Object * BSTree::retrieve (const Object &the_item) const
{
	return retrieveHelper(my_root, the_item);
}	


//========================retrieveHelper==============================
// A helper method for retrieve. It recursively finds the provided
// object in this tree. Returns NULL if the item is not found.
// 
// Preconditions: The Object is not NULL and has operator< 
//  		  implemented correctly to compare values.
//		 
// Postconditions: Returns a pointer to the Object if found,
//	 	   a NULL pointer is returned otherwise. 		 
//====================================================================
const Object * BSTree::retrieveHelper (const Node *root, 
					const Object &the_item) const  
{
	if (root == NULL) return NULL;
	
	else if (the_item == *root->item)	
		return root->item;
	
	else if (the_item < *root->item)
		return retrieveHelper (root->left, the_item);
	
	else 
		return retrieveHelper (root->right, the_item);
}


//========================depth======================================= 
// Returns the depth of a character in the tree. The depth
// of root is 0.
// 
// Preconditions: my_root is not NULL. 
//
// Postconditions: Returns the depth of the character in this tree,
// 		   returns -1 if not found. 	 
//==================================================================== 
int BSTree::depth (const Object &the_item) const
{
	return depthHelper(my_root, the_item);	
}	


//========================depthHelper=================================
// A helper method that recursively calcuates the depth of the 
// provided Object.
//
// Preconditions: The Object is not NULL.
// 		 
// Postconditions: Returns the depth of the given Object. If the 
//		   Returns -1 the Object is not found.		 
//==================================================================== 
int BSTree::depthHelper (Node *root, const Object &the_item) const
{ 
	// Item not found.
	if (root == NULL) return -1;
	// Found it.
	if (*root->item == the_item) return 0;
	
	int subtree = depthHelper (root->left, the_item);

	if (subtree == -1)
		 subtree = depthHelper (root->right, the_item);
	
	if (subtree == -1) return -1;

	else return 1 + subtree;	
}	


//========================descendents=================================
// Returns the number of descendents of the node storing the character 
// in the BSTree. A leaf has zero descendents.
// 
// Preconditions: Overloaded output operator of Object class
//		  must be overrided to display the character. 		 
//
// Postconditions: Returns the number of Node descendents of
// 		   the Node storing the provided character.
//		   Retuns -1 if the object is not found. 		 
//==================================================================== 
int BSTree::descendents (const Object &the_item) const	
{
	int result = descendentsHelper(my_root, the_item);
	return (result == -1 ? -1 : result - 1);
}


//========================descendentsHelper===========================
// A helper method that calculates the descendents of the
// given Object.
//
// Preconditions: The Object is not NULL.
// 		 
// Postconditions: Returns the number of descendents the given
//		   Object has. Returns -1 if the Object is not found.
//====================================================================
int BSTree::descendentsHelper (const Node *root, 
					const Object &the_item) const
{
	if (root == NULL) return -1;	
	
	if (the_item == *root->item) {
		// We found the node, now return the number of nodes
		// in it's left and right subtrees.
		return countNodes (root);
	}	
	if (the_item < *root->item)	
		return descendentsHelper (root->left, the_item);
	else
		return descendentsHelper (root->right, the_item); 

}	


//========================countNodes==================================
// Counts the number of nodes in the given tree.
//
// Preconditions: root is not NULL.
// 		 
// Postconditions: Returns number of nodes in the given tree.
//==================================================================== 
int BSTree::countNodes (const Node *root) const
{
	if (root == NULL) return 0;
	
	return 1 + countNodes (root->left) + countNodes (root->right);	
}	


//========================isEmpty=====================================
// Returns true if this BSTree contains no data.
// 
// Preconditions: my_root points to NULL or the first Object
// 		  in this BSTree.   		  
//
// Postconditions: returns true if this BSTree contains no data,
//		   returns false otherwise.
//==================================================================== 
bool BSTree::isEmpty () const
{
	return (my_root == NULL);
}	


//========================insert======================================
// Inserts the given Object into this BSTree. If the character in the 
// object is already in the tree its count is incremented, and this 
// tree does not take responsibility for the memory of the Object.
// It it isn't in the tree the tree takes responsibility of the 
// memory of the Object.
// 
// Preconditions: my_root points to NULL or the first Object in this
// 		  BSTree. Additionally, the_item != NULL.  
//
// Postconditions: Returns true if the_item is insterted in this
//		   BSTree.False is returned if the character is found,
//		   the character count is just incremented. 
//		   This BSTree only takes ownership of the Object if
//		   the character is not found.
//====================================================================
bool BSTree::insert (Object *the_item)
{
	return insertHelper (my_root, the_item);
}

//========================insertHelper================================
// A helper method for instert that inserts the given Object into
// this tree. Returns true and inserts the Object only if its item 
// does not exist in the tree. Other if found it increments the
// count and returns false, thus ownership of the Object remains
// with the client.
//
// Preconditions: my_root points to NULL or the first Object 
// 		  in this BSTree. 
//
// Postconditions: Returns true if the_item is insterted in 
//		   this BSTree.False is returned if the char-	
//		   acter is found, the character count is
//		   just incremented. This BSTree only takes 
//		   ownership of the Object if the character
// 		   is not found.
//====================================================================
bool BSTree::insertHelper (Node *&the_root, Object *the_item)	
{
	if (the_root == NULL) {
		the_root        = new Node;
		// We're taking ownership of the Object.	
		the_root->item  = the_item;
		the_root->left  = NULL;
		the_root->right = NULL;
		the_root->occurances = 1;
		return true;
	}	

	else if (*the_root->item == *the_item) {
		// Ownership of Object goes back to client.
		the_root->occurances++;
		return false;	
	} 
	
	else if (*the_item < *the_root->item) 
		return insertHelper(the_root->left, the_item);

	 else 
		return insertHelper(the_root->right, the_item);
}


//========================remove======================================
// Removes one occurance of a character from this BSTree. If it is the
// last occurence, the Object is removed. Calls a helper method that
// recursively removes the node.
// 
// Preconditions: the_item is a reference to a non NULL object. 
//
// Postconditions: Returns true if the character is found and an
//		   occurance of it is removed. If it is the last
// 		   occurence the Object is removed. False is returned
//		   if the character is not found. 
//==================================================================== 
bool BSTree::remove (const Object &the_item)
{
	return removeHelper (my_root, the_item);
}	


//========================removeHelper================================
// Removes one occurance of the item from this BSTree. If it is the 
// last occurence, the Object is removed.
// 
// Preconditions: the_item is a reference to a non NULL 
//		  object. 
//
// Postconditions: Returns true if the item is found and an occurance
//		   of it is removed. If it is the last occurence the 
//		   Object is removed. False is returned if the
//		   item is not found. 
//====================================================================
bool BSTree::removeHelper (Node *&root, const Object &the_item)
{
	if (root == NULL) return false;

	else if (the_item == *root->item) {
		// More than one occurance, so decrment one.
		if (root->occurances > 1) 
			root->occurances--;
			
		// Otherwise, there's one occurance, so delete it.
		else 	
			deleteRoot (root);

		// We decremented the occurance or deleted the node.	
		return true; 
	}

	else if (the_item < *root->item) 
		return removeHelper (root->left, the_item);
	else 
		return removeHelper (root->right, the_item);	
}	


//========================deleteRoot==================================
// Deletes the node that the given pointer points to. If left and 
// right pointer of the node is not NULL, then we we delete the item
// in the node and replace it with the most left node in its right
// subtree.
//
// Preconditions: root is not NULL.
// 		 
// Postconditions: the root has been deleted.
//====================================================================
void BSTree::deleteRoot (Node *&root)
{
	// Only node in the tree, or a leaf, so delete it.
	if (root->left == NULL && root->right == NULL) {
		delete root->item;
		delete root;
		root = NULL;	
	}

	else if (root->left == NULL) {
		Node *temp = root;
		root = root->right;
		delete temp->item;
		delete temp; 
	}

	else if (root->right == NULL) {
		Node *temp = root;
		root = root->left;
		delete temp->item;
		delete temp;
	}

	// We have a subtree on both sides, delete the root's item.
	// Replace it with the most left item in the right subtree.
	else {
		delete root->item;
		root->item = findAndDeleteMostLeft(root->right);
	}
}


//========================findAndDeleteMostLeft=======================
// Returns a pointer to the Object item from the node that is located 
// at the most left subtree of the given root. 
//
// Preconditions: root is not NULL.
// 		 
// Postconditions: Returns a pointer to the Object of the most left
//		   node. That node that previously stored the item 
//		   is then deleted.
//====================================================================
Object * BSTree::findAndDeleteMostLeft (Node *&root)
{
	// If we reached the furthest left node.
	if (root->left == NULL) {
		// Get the item to return.
		Object *result = root->item;
		Node *temp     = root;
		root           = root->right;
		delete temp;
		return result;
	}

	else  // Keep going left until we're NULL.
		return findAndDeleteMostLeft (root->left);
}
	

//========================makeEmpty===================================
// Deallocates all Objects in this BSTree and sets its root to NULL, 
// isEmpty() would then return true.
// 
// Preconditions: my_root points to NULL or the first Object in 
// 		  this BSTree.   		  
//
// Postconditions: All memory has been deallocated, root is NULL.
//==================================================================== 
void BSTree::makeEmpty ()	
{
	makeEmptyHelper (my_root);
}


//========================makeEmptyHelper=============================
// Deletes the nodes in the given tree recursively.
//
// Preconditions: root is not NULL.
// 		 
// Postconditions: The tree is empty.
//==================================================================== 
void BSTree::makeEmptyHelper (Node *&root) const
{
	if (root != NULL) {
		makeEmptyHelper (root->left);
		makeEmptyHelper (root->right);
		delete root->item;
		delete root;
		root->item = NULL;				
	}	
	root = NULL;
}


//========================operator(=)=================================
// Overloaded assignment operator.
// 
// Preconditions: the_other.my_root points to the first Node in the 
//		  tree, or NULL.
// 		
// Postconditions: the_other is copied into this.
//		   this is then returned.		   
//==================================================================== 
const BSTree& BSTree::operator=  (const BSTree &the_other)	
{
	// Check for self assignment.
	if (this != &the_other) {
		// Delete our current memory.
		makeEmpty();
		// Now copy the other's tree.
		clone (my_root, the_other.my_root);		
	}
	return *this;
}


//========================clone=======================================
// Clones the given originalTree into the subtree of copy recursively.
//
// Preconditions: originalTree is not NULL. Object has a 
//		  copy constructor.
// 		 
// Postconditions: copy contains its own copy of the originalTree. 
//====================================================================
void BSTree::clone (Node *&copy, const Node *originalTree)
{
	if (originalTree == NULL) {
		copy = NULL; 
	} 
	
	else { 
		// Our new Node.
		copy = new Node; 

		// Link the data into our new Node.
		copy->item       = new Object (*originalTree->item); 
		copy->occurances = originalTree->occurances;
		// Now clone left and right subtrees.	
		clone(copy->left,  originalTree->left);	
		clone(copy->right, originalTree->right); 
	}
}


//========================operator(==)================================
// Determine if two BSTrees are equal. Two trees are equal if they
// have the same data, the same structure, and the same number of 
// occurances for each character.
// 
// Preconditions: my_root and the_other.my_root point to the first 
//		  Node in the tree, or NULL.		 
// 		
// Postconditions: true is returned if the this and the_other tree 
//		   have the same data, the same structure and the
//		   same number of occurances for each character.		  
//==================================================================== 
bool BSTree::operator==  (const BSTree &the_other) const	
{
	return compareHelper (my_root, the_other.my_root);
}


//========================compareHelper===============================
// A recursive method that compares two trees. Returns false
// if they are not the same. 
//
// Preconditions: root and other are not NULL.
//		  		 
// Postconditions: Returns false if the trees are not the 
//		   same. 		  
//==================================================================== 
bool BSTree::compareHelper (const Node *root, const Node *other) const 
{

	// Is one NULL and not the other.
	if (root == NULL && other != NULL || 
		root != NULL && other == NULL) return false;

	// Are they both NULL.
	if (root == NULL && other == NULL) return true;

	// Is one item NULL and not the other.
	if (root->item == NULL && other->item != NULL ||
		root->item != NULL && other->item == NULL) return false;

	// We know that the items of each Object are not NULL,
	// so it's safe to dereference and compare.	
	if (*root->item != *other->item) return false;

	// Same Object, now check occurances.
	if (root->occurances != other->occurances) return false;
	
	// Everything matched.
	// Now lets check the left and right subtree.	
	compareHelper (root->left, other->left);
	compareHelper (root->right, other->right); 
}


//========================operator(!=)================================
// Determine if two BSTrees are not equal. Two trees are not equal if 
// they do not have the same data, or same structure, or same number 
// of of occurances for each character. 
// 
// Preconditions: my_root and the_other.my root point to the first
//		  Node their tree or NULL.
//		  		
// Postconditions: false is returned if the trees have the same data, 
//		   same structure, and same  number of occurances of
//		   each character. Returns True otherwise.		  		 
//====================================================================
bool BSTree::operator!= (const BSTree &the_other) const
{
	return !(*this == the_other);
}	


//====================================================================
// Overloaded  output operator for BSTree class.
// 
// Preconditions: the_bstree.my_root must point to the first element
//		  of the BSTree, or NULL. 		  
//
// Postconditions: The elements of the_bstree are sent to the output
//		   using iostream using a frequency table format.
//		   It uses an in-order traversal of the tree.
//		   The stream is then returned.
//====================================================================
ostream& operator<< (ostream &output, const BSTree &the_other) 
{
	the_other.printHelper(output, the_other.my_root);	
	return output;
}


//========================printHelper=================================
// A helper method that recursively prints the the given	
// tree in-order.
//
// Preconditions: root is not NULL.
// 		 
// Postconditions: The tree is sent to the output.
//==================================================================== 
void BSTree::printHelper (ostream &output, const Node *root) const
{
	if (root != NULL) {
		printHelper (output, root->left);
		output << *root->item 
		       << " "
		       << root->occurances 
	  	       << endl;
		printHelper (output, root->right);
	}
}

