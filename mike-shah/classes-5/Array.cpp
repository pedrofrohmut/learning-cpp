#include <iostream>
#include <memory>

#include "Array.hpp"

// private function since there is no reference to it in the header file
int get_random_number(const int min, const int max)
{
    return (rand() % max) + min;
}

Array::Array(const int size)
{
    std::cout << "Constructor called\n";
    if (size < 0) {
        std::cout << "Invalid size\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        const int n = get_random_number(1, 10);
        this->data.push_back(n);
    }
}

Array::~Array() { std::cout << "Destructor called\n"; }

void Array::print_data()
{
    for (int i = 0; i < this->data.size(); i++) {
        std::cout << "[" << i << "] = " << this->data[i] << '\n';
    }
}

void Array::set_data(const int index, const int value)
{
    if (index > this->data.size() && index < 0) return;
    this->data[index] = value;
}

