#include <cstdlib>
#include <iostream> // Read write data
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

using namespace std;

// In CPP you have to define function prototypes

double AddNumbers(double a, double b);

int AssignAge(int age);

void AssignAgeWithPointer(int* pAge);

void DoubleArray(int* arr, int size);

int main (int argc, char** argv)
{    
    auto result = AddNumbers(3.5, 7.2);
    std::cout << "Result = " << result << std::endl;
    double x = 4.3;
    double y = 2.9;
    printf("%.2f + %.2f = %.2f\n", x, y, AddNumbers(x, y));
//------------------------------------------------------------------------------
    int age43 = 43;
    age43 = AssignAge(age43);
    std::cout << "Age43: " << age43 << std::endl;
//------------------------------------------------------------------------------
    int age34 = 34;
    // Use & to pass the variable reference
    AssignAgeWithPointer(&age34);
    std::cout << "Age34: " << age34 << std::endl;
//------------------------------------------------------------------------------
    int age2 = 2;
    int* pAge2 = NULL;
    pAge2 = &age2;
    std::cout << "pAge2: " << pAge2 << std::endl;
//------------------------------------------------------------------------------
    int intArr[] = { 1, 2, 3, 4, 5 };
    int* pIntArr = intArr;
    std::cout << "1st: " << pIntArr << std::endl;
    pIntArr++;
    std::cout << "2nd: " << pIntArr << std::endl;
    DoubleArray(intArr, 5);
    for(auto n : intArr) {
        std::cout << "Value: " << n << std::endl;
    }
    return 0;
}

// In CPP we can define default values when they are omitted in the call
double AddNumbers(double a = 0, double b = 0) {
    return a + b;
}

// CPP variables declared in a function has the life cycle retricted to the 
// functions scope and get disposed when the function returns or get to end
int AssignAge(int age) {
    int localAge = 16;
    age = 24;
    return age;
}

void AssignAgeWithPointer(int* pAge) {
    *pAge = 22;
}

void DoubleArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}
