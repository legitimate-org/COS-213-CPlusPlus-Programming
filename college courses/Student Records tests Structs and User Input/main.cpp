#include <iostream>
#include <string>

/*
 * @author Ben Jenkins
 *
 * This assignment tests my knowledge of using structs and user input.
 */
using namespace std;

void strToCharArray(const string&, char*);

struct StudentRecord{
    char name[20];
    int id;
    float gpa;
};

int main()
{
    // Init record1
    StudentRecord TESCStudent;
    strToCharArray("SuperProgrammer", TESCStudent.name);
    TESCStudent.id = 1234;
    TESCStudent.gpa = 4.0f;

    // Print record1
    cout << TESCStudent.name << " with an identification number of "
    << TESCStudent.id << " has a " << TESCStudent.gpa << " GPA." << endl;

    // Init Record2
    StudentRecord TESCStudent2;

    // Get Name
    cout << "Enter student name: ";
    string name;
    getline(cin, name);
    strToCharArray(name, TESCStudent2.name);

    // Get ID
    cout << "Enter ID: ";
    cin >> TESCStudent2.id;

    // Get GPA
    cout << "Enter GPA: ";
    cin >> TESCStudent2.gpa;

    // Print record2
    cout << TESCStudent2.name << " with an identification number of "
    << TESCStudent2.id << " has a " << TESCStudent2.gpa << " GPA." << endl;

    return 0;
}

// Assignment required name to be char array, getline wanted a string, so I have a conversion.
void strToCharArray(const string &str, char* phrase)
{
    // Copies the contents of a string into the char array.
    unsigned int i;
    for(i = 0; i < 20; ++i)
    {
        if(i < str.length())
        {
            phrase[i] = str[i];
        }
    }
}
