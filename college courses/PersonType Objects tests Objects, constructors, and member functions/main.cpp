#include <iostream>
#include <personType.h>

/*
 * @author Ben Jenkins
 * Section B Question 2
 *
 * Tests knowledge of creating objects, constructors, and member functions.
 */

using namespace std;

int main()
{
    // Default constructor test
    personType def;
    cout << "Default constructor: ";
    def.printName();
    cout << endl;

    // Dual string constructor test
    personType dual("Ben", "Jenkins");
    cout << "Dual string constructor: ";
    dual.printName();
    cout << endl;

    // Set Name test.
    string first = "Bjarne";
    string last = "Stoustrup";
    personType bjarne;
    bjarne.setName(first, last);
    cout << "Set Name: ";
    bjarne.printName();
    cout << endl;

    // Get method test. Resets string variables to prove the get works.
    first = "";
    last = "";
    bjarne.getName(first, last);
    cout << "Get Name: " << first << ", " << last << endl;

    return 0;
}
