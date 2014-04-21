#include "personType.h"

personType::personType()
{
    setName("John", "Doe");
}

// Could use default parameters by adding = "John" to the end of firstName, and = "Doe" to the end of lastName
personType::personType(std::string firstName, std::string lastName)
{
    setName(firstName, lastName);
}

// Sets the name using this notation.
void personType::setName(const std::string firstName, const std::string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}

// Gets the name and stores them inside the variables passed in
void personType::getName(std::string& firstName, std::string& lastName)
{
    firstName = this->firstName;
    lastName = this->lastName;
}

// Would print "John, Doe" for default constructor
void personType::printName()
{
    std::cout << firstName << ", " << lastName;
}
