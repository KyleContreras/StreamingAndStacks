#include <iostream>
#include <fstream>
#include "stack.h"
#include "astack.h"
using namespace std;

int main(int argc, char* argv[])
{
    string inFile = argv[1];    // The file that we are checking the syntax of
    string token;               // The current item in the stream
    AStack stack;               // Create an instance of AStack
    bool isError = false;       // Keep track of whether there is a syntax error
    bool topNumber;             // Last check to top, to make sure that all tags are accounted for

    string line;                // Contain the line from getline()
    int lineCount = 0;          // Keep track of what line the loop is on
    int wordLineCount = 0;      // Keep track of the lines that have no tags but aren't empty
    int emptyLineCount = 0;     // Keep track of the empty lines
    int onlyClosingTag = 0;     // Keep track of lines with only closing tags
    int currentLine = 0;        // Line count after removing the elements that inStream misses


    // Open inStream to get line count of argv txt file
    ifstream inStream;
    inStream.open(inFile, ios::in);


    // Using peek to be able to read and keep track of empty lines.
    // Will keep track of the lines with just a sentence or lines with just a closing tag
    while (inStream.peek() != EOF)
    {
        getline(inStream, line);
        lineCount++;              // Will contain the number of lines in the file

        if (isalpha(line[0]))     // Check to see if line starts with a letter
        {
            //cout << "it is a letter" << endl;
            wordLineCount++;
        }
        else if (line.empty())    // Checking to see if the current line is an empty line
        {
            //cout << "This is an empty line" << endl;
            emptyLineCount++;
        }
        else if (line[1] == '/')  // Checking to see if the line only contains a closing tag
        {
            //cout << "this is a line with only a closing tag" << endl;
            onlyClosingTag++;
        }
    }

    // We will decrement currentLine when checking for syntax
    currentLine = lineCount;
    currentLine = currentLine - (wordLineCount + emptyLineCount + onlyClosingTag);

    // "Refresh" the stream by closing and re-opening it.
    inStream.close();
    inStream.open(inFile, ios::in);

    while (inStream >> token)
    {
        int tagEnd;                 // Will hold the index value of the string, before the '>'

        if (token[0] == '<')
        {
            string tag;             // The tag without '<' and '>'

            if (token[1] == '/')    // Will be a closing tag
            {
                tagEnd = (token.size() - 3);
                tag = token.substr(2, tagEnd);
                isError = stack.pop(tag);
            }
            else if (token == "<>") // Add and immediately remove, instead of breaking up and looping again
            {
                stack.push(token);
                isError = stack.pop(token); // Will be true if an error occurs
            }
            else                    // Assume correct opening tag
            {
                tagEnd = (token.size() - 2);
                tag = token.substr(1, tagEnd);
                stack.push(tag);

                currentLine--;
            }
        }
        else if (token[0] == '{' || token[0] == '[') // Add to stack
        {
            stack.push(token);
        }
        else if (token[0] == '}' || token[0] == ']') // Pop off the opening tag
        {
            isError = stack.pop(token);
        }
        else if (token == "()")  // Add and immediately remove, instead of breaking up and looping again
        {
            stack.push(token);
            isError = stack.pop(token); // Will be true if an error occurs
        }

        // If TRUE, throw error with the line number in which error occurs
        if (isError)
        {
            lineCount = lineCount - currentLine;

            cout << "Error on line: " << lineCount << endl;
            return 0;
        }
    }

    // Retrieve the value of top after the looping is done
    topNumber = stack.isEmpty();

    // Get the correct line where the error occurs at or before (if the end of file)
    lineCount = lineCount - currentLine;

    // The after loop check of the stack, to ensure that all tags are accounted for
    if (topNumber)
    {
        cout << "The file has correct syntax." << endl;
    }
    else
    {
        cout << "Syntax error on line: " << lineCount << endl;
    }
}