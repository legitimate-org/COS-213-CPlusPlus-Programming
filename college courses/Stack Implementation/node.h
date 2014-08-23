#ifndef NODE_H
#define NODE_H

/*
 * This really feels like it should be done with a struct...
 */
class node
{
public:
    node(void *v)
    {
        info = v;
        next = 0;
    }
    void put_next(node *n)
    {
        next = n;
    }
    node* get_next(){return next;}
    void* get_info(){return info;}
protected:
private:
    void *info;
    node *next;
};

#endif // NODE_H
