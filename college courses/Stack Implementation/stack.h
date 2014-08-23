/* 
 * File:   stack.h
 * Author: Ben Jenkins
 *
 * Created on May 22, 2014, 11:58 PM
 */

#ifndef STACK_H
#define	STACK_H
#include "list.h"

class stack : public list {
public:
	stack();
void* pop();
int getLength();
bool isEmpty();
void push(void*);
	
private:

};

#endif	/* STACK_H */

