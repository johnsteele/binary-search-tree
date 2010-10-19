#include <iostream>
#include <fstream>
#include "BSTree.h"
using namespace std;


//-------------------------- buildTree --------------------------------------
// Builds a BSTree of characters by reading them from a file stream
// Preconditions:   infile has been successfully initialized
// Postconditions:  T stores the characters (and number of occurrences)
//                   of the unprocessed characters remaining in infile, 
//                   (in addition to whatever was previously stored in T)

void buildTree(ifstream &infile, BSTree &T) {
   char ch;

   for (;;) {
      ch = infile.get();                   // gets each and every character
      if (infile.eof()) break;             // no more data

      Object* ptr = new Object(ch);
      bool success = T.insert(ptr); 
      if (!success) {                      // must be repeat character
         delete ptr;                       // deallocate if not inserted 
      }
   }
}



//-------------------------- main -------------------------------------------
// Tests the BSTree class by reading data from "test.txt" and playing with it
// Preconditions:   None (although it won't test anything if "test.txt"
//					 doesn't exist.)
// Postconditions:  All of the basic operations of the BSTree class are used. 
//                  Should compile, run to completion, and output correct 
//                  answers if BSTree is implemented correctly.

int main() {
   // create file object and open the datafile
   ifstream infile("HW2.txt");
   if (!infile) {
      cerr << "File could not be opened." << endl;
      return 1;
   }
/*
	BSTree tree;
	tree.insert (new Object ('b')); 
	tree.insert (new Object ('a'));
	tree.insert (new Object ('c'));
	tree.insert (new Object ('d'));
	tree.insert (new Object ('e'));
	cout << "depth of a : " << tree.depth ('a') << endl;
	cout << "depth of b : " << tree.depth ('b') << endl;
	cout << "depth of c : " << tree.depth ('c') << endl;
	cout << "depth of d : " << tree.depth ('d') << endl;
	cout << "depth of'e': " << tree.depth ('e') << endl; 
	cout << "e descendents: " << tree.descendents ('e') << endl;
	cout << "b descendents: " << tree.descendents ('b') << endl;
	cout << "d descendents: " << tree.descendents ('d') << endl;
	cout << "a descendents: " << tree.descendents ('a') << endl;
	cout << "f descendetns: " << tree.descendents ('f') << endl;*/

   // test copy constructor, operator=, self-assignment
   BSTree T, T2, duplicate;
   buildTree(infile, T);

  cout << "Tree:" << endl << T << endl;
   BSTree first(T);
   duplicate = duplicate = T;
   duplicate.makeEmpty();

   // test operator<<
   cout << "Frequency table:  " << endl;
   cout << T;
   cout << endl;

   // test retrieve
  const Object *p1 = T.retrieve('n');  // need char Object constructor
  cout << "Retrieve 'n':       " << (p1 != NULL ? "found" : "not found") 
       << endl;
  const Object *p2 = T.retrieve('z');  
   cout << "Retrieve 'z':       " << (p2 != NULL ? "found" : "not found") 
      << endl;

   //test operator==, operator!=
   T2 = T;
   cout << "T == T2?            " << (T == T2 ? "equal" : "not equal") << endl;
   cout << "T != T2?            " << (T != T2 ? "not equal" : "equal") << endl;
   BSTree T3 = T2;                        // test copy constructor, too
   T2.makeEmpty();

   Object *newData = new Object('z'); 
   bool success = T3.insert(newData);
   if (!success){cout << "Couldn't insert z" << endl;  delete newData;}
   cout << "T == T3?            " << (T == T3 ? "equal" : "not equal") << endl;
   cout << "T != T3?            " << (T != T3 ? "not equal" : "equal") << endl;

   // test depth and descendents
   // if 'q' is in tree, might want to try another character
   cout << "depth of 'a': " << T.depth('a') << endl;
   cout << "depth of 'q': " << T.depth('q') << endl;
   cout << "descendents of 'a': " << T.descendents('a') << endl;
   cout << "descendents of 'q': " << T.descendents('q') << endl;
   cout << "descendents of 'c': " << T.descendents('c') << endl;

   // test remove
   if (!T.remove('a'))
	   cout << "Node 'a' not found." << endl;
   else
	   cout << "Node 'a' removed." << endl;
   cout << "depth of 'a':       " << T.depth('a') << endl;
   if (!T.remove('q'))
	   cout << "Node 'q' not found." << endl;
   else
	   cout << "Node 'q' removed." << endl;
   cout << "depth of 'q':       " << T.depth('q') << endl;

   // test isEmpty, makeEmpty
   cout << "T empty?            " << (T.isEmpty() ? "empty" : "not empty") << endl;
   cout << "Making T empty. " << endl;
   T.makeEmpty();
   cout << "T empty?            " << (T.isEmpty() ? "empty" : "not empty") << endl;

   return 0;
}

