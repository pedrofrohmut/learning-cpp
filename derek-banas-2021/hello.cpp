#include <cstdlib>
#include <iostream> // Read wirete data
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

using namespace std; // So you dont have to type std everywhere

int imGlobal = 0;
const double PI = 3.14159;

int main(int argc, char** argv) {
    cout << "Hello World" << endl;
    bool isMarried = true;
    char myGrade = 'A';

    cout << endl;

    cout << "Min unsigned short ints " << numeric_limits<unsigned short int>::min() << endl;
    cout << "Max unsigned short ints " << numeric_limits<unsigned short int>::max() << endl;
    cout << "Min short ints " << numeric_limits<short int>::min() << endl;
    cout << "Max short ints " << numeric_limits<short int>::max() << endl;
    cout << "Min ints " << numeric_limits<int>::min() << endl;
    cout << "Max ints " << numeric_limits<int>::max() << endl;
    cout << "Min long " << numeric_limits<long>::min() << endl;
    cout << "Max long " << numeric_limits<long>::max() << endl;

    cout << endl;

    cout << "Min float " << numeric_limits<long>::min() << endl;
    cout << "Max float " << numeric_limits<long>::max() << endl;
    cout << "Min double " << numeric_limits<long>::min() << endl;
    cout << "Max double " << numeric_limits<long>::max() << endl;
    cout << "Min long double " << numeric_limits<long>::min() << endl;
    cout << "Max long double " << numeric_limits<long>::max() << endl;

    // Floats has percission until 6 decimal points
    float f1 = 1.1111111;
    float f2 = 1.1111111;

    printf("Sum = %.7f\n", (f1 + f2));

    // Doubles has 15 points of precisio
    double d1 = 1.111111111111111;
    double d2 = 1.111111111111111;

    printf("Sum = %.16f\n", (d1 + d2));

    // Auto set datatype
    auto whatAmI = true;

    cout << "int: Byte: " << sizeof(int) << endl;

    printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.12345, "HI");

    string q1 = "Enter a Number: ";
    string n1, n2;
    cout << q1;
    cin >> n1;
    cout << "Enter another number: ";
    cin >> n2;
    int nNum1 = stoi(n1); // String To Int
    int nNum2 = stoi(n2); // String To Int

    // Add
    printf("%d  + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    // Subtraction
    printf("%d  - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    // Multiplication
    printf("%d  * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    // Division
    printf("%d  / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    // Rest (MOD)
    printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));

    return 0;
}
