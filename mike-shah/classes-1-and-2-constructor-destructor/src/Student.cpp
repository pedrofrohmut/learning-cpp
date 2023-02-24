#include <iostream>

#include "../headers/Student.hpp"

const string UNKNOWN = "Unknown";

using std::cout;

Student::Student()
{
    this->name = UNKNOWN;
    cout << "Constructor for " << this->name << "\n";
}

Student::Student(string name)
{
    this->name = name;
    cout << "Constructor for " << this->name << "\n";
}

// Destructor - If you omit it you get an default
Student::~Student()
{
    string name = this->name.empty() ? UNKNOWN : this->name;
    cout << "Destructor for " << name << "\n";
}

string Student::get_name()
{
    return this->name;
}

void Student::print_name()
{
    cout << "Name: " << this->name << "\n";
}
