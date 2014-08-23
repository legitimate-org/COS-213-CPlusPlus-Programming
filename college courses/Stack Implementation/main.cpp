/* 
 * File:   main.cpp
 * Author: Ben Jenkins
 * Final Programming Project Problem 2
 *
 * Created on May 22, 2014, 11:49 PM
 */

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    
    // Test pushing 5 values into the stack
    cout << "Pushing..." << endl;
    stack myStack;
    for(int i = 1; i <= 5; ++i)
    {
        int* num = new int;
        *num = i;
        myStack.push(num);
        cout << *num << endl;
    }

    // Test popping values from the stack until the stack is empty
    cout << endl << "Popping..." << endl;
    while(!myStack.isEmpty())
    {
        int* val = (int*)myStack.pop();
        cout << *val << endl;
    }
    return 0;
}

