#include <iostream>
#include "Polynomial.h"

/*
 * @author Ben Jenkins
 * Written Assignment 4 Section C
 *
 * Original implementation was much cleaner but less efficient and only
 * Took integer values. This can take double values, negative values, and
 * integer values. As many values as you want can be added as I implemented
 * this like an expanding vector.
 *
 * Sorry about how ugly the code started to look. It morphed between v1.0 and v2.0
 * and was hard to salvage.
 */

using namespace std;

int main()
{
    // Test constructor
    Polynomial p1;

    // Test set method
    p1.set(3, 4);
    p1.set(5.152, -2.345);
    p1.set(10, 1);
    p1.set(6, 0);

    // Test get method
    cout << "Exponent 2 has coefficient " << p1.get(2) << endl;

    // Test visual display.
    p1.print();

    // Creating a second polynomial to test + and - overloads.
    Polynomial p2;
    p2.set(3, 3);
    p2.set(5, 1);
    p2.print();

    // Test + overloaded operator
    Polynomial p3 = p1 + p2;
    p3.print();

    // Test - overloaded operator
    Polynomial p4 = p1 - p2;
    p4.print();

    return 0;
}
