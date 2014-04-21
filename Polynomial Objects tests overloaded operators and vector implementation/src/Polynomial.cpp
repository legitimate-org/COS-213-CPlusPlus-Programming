#include "Polynomial.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

Polynomial::Polynomial()
{
    // Turning this into a vector of terms.
    currentSize = 0;
    allocatedSize = 10;
    list = new termT[allocatedSize];
}

Polynomial::~Polynomial()
{
    delete[] list;
}

Polynomial Polynomial::operator+(const Polynomial& p2)
{
    Polynomial sum; // Create a sum polynomial

    // Fill it with all of the contents of the current list.
    for(unsigned int i = 0; i < currentSize; ++i)
    {
        sum.set(list[i].coefficient, list[i].exponent);
    }

    // Fill it with all of the contents of the passed in list.
    for(int i = 0; i < p2.size(); ++i)
    {
        // Check to see if any exponents in the passed in list polynomial are in the sum polynomial
        int expIndex = sum.findExponent(p2.list[i].exponent);

        // If the exponent is not inside of the sum polynomial
        if(expIndex == -1)
        {
            sum.set(p2.list[i].coefficient, p2.list[i].exponent);// Add it to the sum array
        }
        else
        {
            sum.set(sum.get(p2.list[i].exponent) + p2.list[i].coefficient, p2.list[i].exponent);// Else add it's coefficient to the existing coefficient.
        }
    }

    return sum;// Return the new polynomial.
}

Polynomial Polynomial::operator-(const Polynomial& p2)
{
    Polynomial sum; // Create a sum polynomial

    // Fill it with all of the contents of the current list.
    for(unsigned int i = 0; i < currentSize; ++i)
    {
        sum.set(list[i].coefficient, list[i].exponent);
    }

    // Fill it with all of the contents of the passed in list.
    for(int i = 0; i < p2.size(); ++i)
    {
        // Check to see if any exponents in the passed in list polynomial are in the sum polynomial
        int expIndex = sum.findExponent(p2.list[i].exponent);

        // If the exponent is not inside of the sum polynomial
        if(expIndex == -1)
        {
            sum.set(-p2.list[i].coefficient, p2.list[i].exponent);// Add it to the sum array
        }
        else
        {
            sum.set(sum.get(p2.list[i].exponent) - p2.list[i].coefficient, p2.list[i].exponent);// Else subtract it's coefficient from the existing coefficient.
        }
    }

    return sum;// Return the new polynomial.
}

/**
 * Looks for the exponent passed in and returns it's index if it exists.
 * If it doesn't exist, -1 is returned.
 *
 * @param exponent The exponent you are searching for
 */
int Polynomial::findExponent(double exponent) const
{
    double threshhold = 0.000001;// How big of a difference 2 variables can have and still be "equal"

    for(unsigned int i = 0; i < currentSize; ++i)// For every term
    {
        // Get the difference between the current exponent and the exponent being searched for
        double diff = (list[i].exponent - exponent);
        diff = diff < 0.0 ? diff * -1.0 : diff;// Get the absolute value

        if( diff < threshhold )// If the difference is less than threshold, this is the exponent
        {
            return i;
        }
    }
    return -1;
}

void Polynomial::set(double coefficient, double exponent)
{

    int expIndex = findExponent(exponent);
    if(expIndex != -1)
    {
        // If it exists, set it's coeffecient.
        list[expIndex].coefficient = coefficient;
    }
    else
    {
        if(currentSize == allocatedSize)
        {
            // If the array is full, expand it
            expandList();
        }


        // Set a new location with the current coeffecient and exponent/
        list[currentSize].coefficient = coefficient;
        list[currentSize].exponent = exponent;
        currentSize++;
    }
}

void Polynomial::expandList()
{
    // Allocate twice as much space
    allocatedSize *= 2;
    termT* newList = (termT*) malloc(sizeof(termT) * allocatedSize);

    // Copy the contents of the old array into the new array
    for(unsigned int i = 0; i < currentSize; ++i)
    {
        newList[i] = list[i];
    }

    // Clean up the old array.
    termT* deleteList = list;
    list = newList;
    delete[] deleteList;
}

double Polynomial::get(double exponent) const
{
    int expIndex = findExponent(exponent);
    if(expIndex == -1)
    {
        // If it doesn't exist, return 0 as the coeffecient.
        return 0;
    }
    else
    {
        // Else return the coeffecient
        return list[expIndex].coefficient;
    }
}

void Polynomial::print()
{
    // If it isn't sorted, sort
    if(!isSorted())
    {
        sort();
    }

    // Go through each element.
    for(unsigned int i = 0; i < currentSize; ++i)
    {
        if(list[i].coefficient != 0)// If the coefficient has a value
        {
            // Print the term
            std::cout << list[i].coefficient;
            if(list[i].exponent != 0)// If the exponent isn't 0, print the exponent.
            {
                std::cout << "x^" << list[i].exponent;
            }

            // If it isn't the last term, print a plus sign
            if(i != currentSize - 1)
            {
                std::cout << " + ";
            }
        }
    }
    std::cout << std::endl;
}

bool Polynomial::isSorted()
{
    // Checks to see if each item is sorted in descending order.
    for(unsigned int i = 0; i < currentSize - 1; ++i)
    {
        if(list[i].exponent < list[i + 1].exponent)
        {
            return false;
        }
    }
    return true;
}

void Polynomial::sort()
{
    // Implemented a selection sort.
    for(unsigned int i = 0; i < currentSize; ++i)
    {
        // Find the largest exponent
        int largest = i;
        for(unsigned int j = i; j < currentSize; ++j)
        {
            if(list[largest].exponent < list[j].exponent)
            {
                largest = j;
            }
        }

        // Swap
        double tempExp = list[i].exponent;
        double tempCoe = list[i].coefficient;
        list[i].exponent = list[largest].exponent;
        list[i].coefficient = list[largest].coefficient;
        list[largest].exponent = tempExp;
        list[largest].coefficient = tempCoe;
    }
}

int Polynomial::size() const
{
    return currentSize;
}
