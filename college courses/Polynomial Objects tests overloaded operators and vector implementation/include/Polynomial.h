#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>


class Polynomial
{
public:
    Polynomial();
    Polynomial operator+(const Polynomial& p2);
    Polynomial operator-(const Polynomial& p2);
    void set(double coefficient, double exponent);// Sets coefficient of given exponent
    double get(double exponent) const; // Returns coefficient of given exponent
    void print();// Print's the Polynomial, includes a newline.
    virtual ~Polynomial();// Destroys list.
    int findExponent(double) const;// Returns index of exponent
    int size() const;
    struct termT
    {
        double coefficient;
        double exponent;
    };
protected:
private:
    unsigned int currentSize;
    unsigned int allocatedSize;
    bool isSorted();
    void sort();
    void expandList();// Allocates more slots when array fills up
    termT* list;// Contains a list of all terms inside the Polynomial
};

#endif // POLYNOMIAL_H
