/* 
 * File:   stack.cpp
 * Author: Ben Jenkins
 * 
 * Created on May 22, 2014, 11:58 PM
 */

#include "stack.h"
#include <iostream>

stack::stack() 
{
    list();
}

void stack::push(void* info)
{
    // Pushing adds a value to the top of the stack, which I determine to be the end
    append(info);
}

void* stack::pop()
{
    // Popping removes a value from the top of the stack and returns it, which I determine to be the end
    unsigned int count = 0;
    node* it = head;

    // If the length is empty, you cannot pop it.
    if(length <= 0)
    {
        std::cerr << "Stack Underflow. Cannot Pop an empty stack." << std::endl;
        return NULL;
    }
  
    // Loop to the last value
    while(count != length - 1)
    {
        it = it->get_next();
        count++;
    }
    
    // Lessen the length and return it's value.
    length--;
    return it->get_info();
}

int stack::getLength()
{
    return length;
}

bool stack::isEmpty()
{
    return length == 0;
}