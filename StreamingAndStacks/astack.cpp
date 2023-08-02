#include <iostream>
using namespace std;

#include "astack.h";

// Constructor
AStack::AStack()
{
}

// Destructor
AStack::~AStack(){}

// Clear all values from the stack
void AStack::clear()
{
	for (int i = 0; i < top; i++)		// loop until we get to the "top" of the stack
	{
		this->tags[i] = ' ';			// make the value at the index an empty string
	}
}

// Check to see if the stack is empty
bool AStack::isEmpty()
{
	bool isItEmpty;

	return isItEmpty = (top == -1) ? true : false;

}

// Push an item onto the top of the stack
bool AStack::push(const string& theTag)
{
	// Increment Top so as to not overwrite an existing value
	this->top++;

	this->tags[top] = theTag;  // Set stack top to be the tag

	return false;  // Return false for no error
}

// Remove the item at the top of the stack
bool AStack::pop(string& theTag)
{
	if (top == -1)		// Trying to pop a tag that shouldn't be there off of the stack
	{
		return true;	// Will be an error. Can't remove what isn't there
	}
	
	string tagInArray = this->tags[top];

	if (tagInArray == "{" || tagInArray == "[") // Check if either of these are on the top of the stack
	{
		if (theTag == "}" || theTag == "]")		// If one of them is, find the correct one and remove it
		{	
			this->tags[top] = ' ';				// "removing" top
			this->top--;						// decrement top, so we know where the new top is
			
			return false;						// no error
		}
	}
	else if (tagInArray != theTag)
	{
		return true;							// Will return true if the tags do not match. Means an error occurred
	}
	else
	{											// No special cases, just pop the top element off
		this->tags[top] = ' ';					// "removing" top
		this->top--;							// decrement top, so we know where the new top is

		return false;							// Will return false if the tags match
	}
}

// Reads the top of the stack
bool AStack::topValue(string&)
{
	bool valueAtTop = isEmpty();  // Will contain the return value of isEmpty()

	if (valueAtTop)				  // If true, return what it is
	{
		cout << "Top value is : " << tags[top] << endl;
	}
	else
	{
		cout << "There are no items on the stack" << endl; // No items on the stack
	}
	
	return valueAtTop;
}

// Returns the number of elements in the stack
int AStack::length()
{
	int length = top + 1;
	
	return length;
}