#ifndef STACK_H
#define STACK_H
//****************************************************************************
// Stack base class
// This defines all that must be included in a stack.
// This version defines a stack that doesn't have any actual private member
// variables. There are also no implementation details otherwise.
//****************************************************************************

#include <string>
using namespace std;

class Stack {
public:
	void clear();				// Clears the stack

	bool push(const string&);	// Push an element onto the stack
								// Return true if successful, false otherwise

	bool pop(string&);			// Pop an element from the stack
								// Return true if successful, false otherwise

	bool topValue(string&);		// Read (but don't pop) the top of the stack
								// Return true if successful, false otherwise

	int length();				// Return the current no. elts in the stack
};
#endif
