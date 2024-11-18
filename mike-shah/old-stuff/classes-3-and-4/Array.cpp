#include <iostream>

#include <memory>

#include "Array.hpp"

Array::Array()
{
    std::cout << "Constructor\n";
    this->data = std::make_unique<int[]>(SIZE);
    for (int i = 0; i < SIZE; i++) {
        this->data[i] = (i + 1) * (i + 1);
    }
}

Array::Array(const Array& src)
{
    std::cout << "Copy Constructor\n";
    this->data = std::make_unique<int[]>(SIZE);
    for (int i = 0; i < SIZE; i++) {
        this->data[i] = src.data[i];
    }
}

Array& Array::operator = (const Array& src)
{
    std::cout << "Copy Assignment Operator\n";
    bool it_points_itself = &src == this;
    if (it_points_itself) {
        return * this;
    }
    this->data = std::make_unique<int[]>(SIZE);
    for (int i = 0; i < SIZE; i++) {
        this->data[i] = src.data[i];
    }
    return * this;
}

Array::~Array()
{
    std::cout << "Destructor called. Memory freed\n";
}

void Array::set_data(const int index, const int value)
{
    this->data[index] = value;
}

void Array::print_data()
{
    for (int i = 0; i < SIZE; i++) {
        std::cout << this->data[i] << '\n';
    }
}
