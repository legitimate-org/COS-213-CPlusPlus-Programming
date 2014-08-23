#include "list.h"
#include "stdlib.h"
#include <iostream>

list::list()
{
    head = NULL;
    length = 0;
}

void list::insert(int index, void *info)
{
    // Exit if index is out of bound
    if(index < 0 || index > length)
    {
        std::cerr << "Index out of bounds." << std::endl;
        return;
    }

    // Else loop
    int count = 0;
    node* it = head;
    node* prev = NULL;

    // Handle the first addition to assign the head
    if(it == NULL)
    {
        it = new node(info);
        it->put_next(NULL);
        head = it;
        length++;
        return;
    }

    // Loop until at the right index
    while(count != index)
    {
        prev = it;
        it = it->get_next();
        count++;
    }

    // Create a new node
    node* newNode = new node(info);

    // insert it between the previous nodes.
    prev->put_next(newNode);
    newNode->put_next(it);
    length++;
}

void list::append(void *info)
{
    // Insert at the end of the list
    insert(length, info);
}

void list::remove()
{
    unsigned int count = 0;
    node* it = head;

    // If the length is 0, we cannot remove, so we must return
    if(length == 0)
    {
        std::cerr << "List is empty. Cannot remove." << std::endl;
        return;
    }
    else if(length == 1)
    {
        // If the length is 1, the head needs to be set to null
        head = NULL;
    }
    else
    {
        // Else loop to the last node
        while(count != length - 1)
        {
            it = it->get_next();
            count++;
        }

        // Set it to null
        it = NULL;
    }
    // Then shrink the size of the list
    length--;
}

void list::display()
{
    // If the length is 0, there is nothing to be displayed.
    if(length == 0)
    {
        std::cerr << "List is empty. Cannot display." << std::endl;
        return;
    }

    // Go through each index and print it
    unsigned int count = 0;
    node* it = head;

    while(count != length)
    {
        // If the index is NULL, then exit. Or erros will occur.
        if(it == NULL)
        {
            return;
        }

        std::cout << "Index " << count << ": " << *((int *)it->get_info()) << std::endl;
        it = it->get_next();
        count++;
    }
    std::cout << std::endl;
}

void* list::find(int index)
{
    // If index out of bounds, return NULL
    if(index < 0 || index >= length)
    {
        std::cerr << "Index out of bounds." << std::endl;
        return NULL;
    }

    // Return the value at that index otherwise
    int count = 0;
    node* it = head;    

    // Loop
    while(count < length)
    {   
        // Return if current node is the same as the index.
        if(count == index)
        {
            return it->get_info();
        }
        
        // Increment
        it = it->get_next();
        count++;
    }

}