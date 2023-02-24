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
        Student();
        Student(string name);

        // Destructor  - If you omit it you get an default
        ~Student();

        string get_name();

        void print_name();
};

#endif
