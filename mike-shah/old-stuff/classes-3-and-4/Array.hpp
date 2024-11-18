#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <memory>

// The law of 3 says that if you need to override the constructor or destructor or
// the copy constructor you should always override the all 3 of them

// The law of big 2 is the law of 3 but if you use a smart pointer or some kind of
// data structure, like a vector, you dont need to override the destructor

// In this case we would follow the rule of 3 but as we are using std::unique_ptr
// we do not need to override the destructor that results in the rule of the big 2
class Array
{
    private:
        const int SIZE = 10;
        // int * data;
        std::unique_ptr<int[]> data;

    public:
        // 1. Constructor
        Array();

        // 2. Copy Constructor
        Array(const Array& src);

        // 2. Copy Assignment Operator (Operator Overloading)
        Array& operator = (const Array& rhs);

        // 3. Destructor
        ~Array();

        void set_data(const int index, const int value);

        void print_data();
};

#endif
