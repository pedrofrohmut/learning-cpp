#include <iostream>
#include <vector>

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!" << std::endl;

    int a = 30;
    int b = 12;
    std::cout << a << " + " << b << " = " << a + b << std::endl;

    int age = 42;
    std::string first = "Pedro";
    std::string last  = "Frohmut";
    std::string name = first + " " + last;

    std::cout << "My name is " << name << " and my age is " << age << std::endl;

    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(10);

    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;

    for (size_t i = 0; i < vec.size(); i++) {
	std::cout << vec[i] << std::endl;
    }

    // If you do not use a reference here it will copy the values
    for (auto& x : vec) {
	std::cout << x << std::endl;
    }

    return 0;
}
