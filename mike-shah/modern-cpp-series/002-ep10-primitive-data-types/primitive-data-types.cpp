#include <iostream>
#include <string>

int main(void)
{
    int64_t x = 1234;
    std::cout << "Value of x: " << x << std::endl
              << "Size of int64_t: " << sizeof(x) << std::endl;

    bool b = false;
    std::cout << "Value of b: " << b << std::endl
              << "Size of bool: " << sizeof(b) << std::endl;

    char c = 'a';
    std::cout << "Value of c: " << c << std::endl
              << "Size of char: " << sizeof(c) << std::endl;

    // Strings in the C way
    const char* foo = "bar";

    // Strings in cpp std
    std::string baz = "buz";

    return 0;
}
