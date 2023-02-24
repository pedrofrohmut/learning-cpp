#include <iostream>

#include "Array.hpp"

int main()
{
    // Cpp makes a shallow copy. It copies the pointer not what it points to.

    // When you want to copy the thing pointed you must not use the default
    // copy constructor but override it.

    Array arr;

    arr.set_data(3, 666);
    arr.set_data(4, 777);

    // Array arr2 = arr;
    Array arr2;
    arr2 = arr;

    arr.set_data(2, 555);

    arr.print_data();
    arr2.print_data();

    return 0;
}
