#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

using std::string;

class Student
{
    private:
        string name;

    public:
        // Constructor
        Student(string name);

        // Destructor
        ~Student();

        string get_name();

        void print_name();
};

#endif
