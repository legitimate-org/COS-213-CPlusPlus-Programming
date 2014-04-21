#include <iostream>
#ifndef PERSONTYPE_H
#define PERSONTYPE_H


class personType
{
    public:
        personType();
        personType(std::string firstName, std::string lastName);
        void setName(const std::string firstName, const std::string lastName);
        void getName(std::string& firstName, std::string& lastName);
        void printName();
    protected:
    private:
        std::string firstName;
        std::string lastName;
};

#endif // PERSONTYPE_H
