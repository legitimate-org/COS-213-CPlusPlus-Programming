#ifndef LIST_H
#define LIST_H
#include "node.h"

class list
{
    public:
        list();
        void insert(int index, void *);
        void append(void*);
        void remove();
        void display();
        void* find(int index);
    protected:
        node* head;
        unsigned int length;
    private:
        
};

#endif // LINKEDLIST_H
