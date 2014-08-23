/* 
 * File:   main.cpp
 * Author: Ben Jenkins
 *
 * Section B
 * Created on May 6, 2014, 11:01 PM
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Program specific functions
void init(int letterCount[26], int lineCount, ifstream& infile, ofstream& outfile);
void copyText(int letterCount[26], int lineCount, ifstream& infile, ofstream& outfile);
void counting(char c, int letterCount[26], int lineCount);
void writeText(char c, ofstream& outfile);
void writeTotal(int letterCount[26], int lineCount);
void cleanUp(ifstream& infile, ofstream& outfile);

// Helper functions
char toUpper(char c);
bool isLetter(char c);


int main() 
{
    // Create my variables, doing them locally and passing through functions instead of declaring global
    int letterCount[26];
    int lineCount;
    ifstream infile;
    ofstream outfile;
    
    // Initialize my variables
    init(letterCount, lineCount, infile, outfile);
    
    // Copy my text, print my text, save my text, count letters.
    copyText(letterCount, lineCount, infile, outfile);
    
    // Output letter totals and line count
    writeTotal(letterCount, lineCount);// This feels like it should be named printTotal our outputTotal
    
    // Close file streams
    cleanUp(infile, outfile);
    
    return 0;
}

void init(int letterCount[26], int lineCount, ifstream& infile, ofstream& outfile)
{
    
    // Initializing letterCount
    for(int i = 0; i < 26; ++i)
    {
        letterCount[i] = 0;
    }
    
    // Initializing lineCount
    lineCount = 0;
    
    // Initializing fileStreams
    infile.open("textinput.txt");
    outfile.open("textoutput.txt");
    
    // If either file failed to open error
    if(!(infile.good() && outfile.good()))
    {
        cerr << "Error! Files did not open properly." << endl;
        exit(1);
    }
}

void copyText(int letterCount[26], int lineCount, ifstream& infile, ofstream& outfile)
{
    // Get initial character
    char c = infile.get();
    
    // While not at the end of the file.
    while(c != EOF)
    {
        // Print the char
        cout << c;
        
        // Count the char
        counting(c, letterCount, lineCount);
        
        // Uppercase char
        c = toUpper(c);

        // Write the char
        writeText(c, outfile);
        
        // Get a new char from the input stream
        c = infile.get();
    }
}

void counting(char c, int letterCount[26], int lineCount)
{
    // if the char is a newline, increase the line count.
    if(c == '\n')
    {
        lineCount++;
    }
    // If the char is a letter
    else if(isLetter(c))
    {
        // uppercase the letter
        c = toUpper(c);
        
        // Get the index at the letter minus 'A' or 65
        int index = (int)(c - 'A');
        
        // Increase the letterCount value at the index
        letterCount[index]++;
    }
        
}

void writeText(char c, ofstream& outfile)
{
    // I prefer naming this out, so it can be out.put :D
    outfile.put(c);
}

char toUpper(char letter)
{
    // If the letter is lower case, make it uppercase, otherwise return the original char.
    if(letter >= 'a' && letter <= 'z')
    {
        return letter - 32;
    }
    else
    {
        return letter;
    }
}

bool isLetter(char c)
{
    // Attempt to uppercase the char
    c = toUpper(c);
    
    // Return if the char is an uppercase letter, returns true if the char is a letter
    return (c >= 'A' && c <= 'Z');
}

// Outputs the letter count and line count.
void writeTotal(int letterCount[26], int lineCount)
{
    cout << "Line Count: " << lineCount << endl;
    for(int i = 0; i < 26; ++i)
    {
        char c = 'A' + i;
        cout << c << ": " << letterCount[i] << endl;
    }
}

// Closes the file streams
void cleanUp(ifstream& infile, ofstream& outfile)
{
    cout << "Closing text files." << endl;
    infile.close();
    outfile.close();
}