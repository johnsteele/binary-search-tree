

#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object {

	friend ostream& operator<< (ostream &, const Object &);
	friend istream& operator>> (isteram &, Object &);
public:

	Object ();

private:
	
	char my_char;      // The character this object holds.
	int  my_occurance; // The occurances of the character.
}; 
#endif /* _OBJECT_H_ */

