#include <stdio.h>
#include <iostream>

/*Array that stores elements in the heap */ 
int array[100], n = 0;

/* A fucntion to insert elements into the heap */
void insert(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
        parentnode =(location - 1)/2;
        if (num >= array[parentnode])
        {
            array[location] = num;
            return;
        }
        array[location] = array[parentnode];
        location = parentnode;
    }/*End of while*/
    array[0] = num; /*assign number to the root node */
}/*End of insert()*/
 
/* A function to display the elements inserted into the heap */ 
void display()
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty \n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}/*End of display()*/
 
int main() {
    int i, no_of_elements, number;

    /* Prompt for the number of elements */
    printf("Enter the number of elements: ");
    /* Read in the number of elements */
    no_of_elements = 10;

    printf("Enter the %d elements: ",no_of_elements);
    /* Read elements one after the other and insert
        them into the heap */
    for(i=1;i<=no_of_elements;i++) {
        std::cout << "Element " << i << ":";
        scanf("%d",&number);
        insert(number, n);
        n++;
   }
   printf("The elements in the heap are: ");
   /* Display the elements inserted into the heap */
   display();

   return 0;
}