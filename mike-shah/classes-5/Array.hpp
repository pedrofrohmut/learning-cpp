#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>

// Using the keyword '=delete' on the Copy constructor and the Copy Assignment
// Operator you define that no copies can be made and it will generate compiler
// errors if someone is tring to

class Array
{
    private:
        std::vector<int> data;

    public:
        // Constructor
        Array(const int size);

        // Destructor
        ~Array();

        // Copy Constructor
        Array(const Array& src)=delete;

        // Copy Assignment Operator (Operator Overloading)
        Array& operator = (const Array& src)=delete;

        void print_data();

        void set_data(const int index, const int value);
};

#endif
