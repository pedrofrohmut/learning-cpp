#include <iostream>

#include "Array.hpp"

// The instance will be copied calling the Copy Constructor
// every time this function is called
void print_array_by_copy(Array arr)
{
    arr.print_data();
}

// A reference will be passed and no copies will be made
void print_array_by_reference(Array& arr)
{
    arr.print_data();
}

int main()
{
    Array arr(10);

    for (int i = 0; i < 100; i++) {
        print_array_by_reference(arr);
    }

    return 0;
}
