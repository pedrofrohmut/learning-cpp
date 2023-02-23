#include <iostream>

#include "../headers/Student.hpp"

using std::cout;

Student::Student(string name)
{
    this->name = name;
    cout << "Constructor for " << this->name << "\n";
}

// Destructor
Student::~Student()
{
    cout << "Destructor for " << this->name << "\n";
}

string Student::get_name()
{
    return this->name;
}

void Student::print_name()
{
    cout << "Name: " << this->name << "\n";
}
