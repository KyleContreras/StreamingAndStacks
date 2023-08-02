#ifndef ASTACK_H
#define ASTACK_H

#include "stack.h"

class AStack : public Stack
{
public:
	// Constructor
	AStack();

	// Destructor
	~AStack();

	void clear();						// Clears the stack

	bool isEmpty();						// Checks whether the stack is clear
	
	bool push(const string& theTag);   // Push an element onto the stack
										// Return true if successful, false otherwise
	
	bool pop(string& theTag);			// Pop an element from the stack
										// Return true if successful, false otherwise
	
	bool topValue(string&);				// Read (but don't pop) the top of the stack
										// Return true if successful, false otherwise

	int length();						// Return the number of elements in that array

private:
	int top = -1;						//Value representing the top of the stack
	string tags[10];					// An array representing the stack
};
#endif