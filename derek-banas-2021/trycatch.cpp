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

int main (int argc, char** argv)
{    
    double x = 12;
    double y = 2;
    try {
        if (y == 0) {
            throw "Division by zero error";
        }
        printf("%.2f / %.2f = %.4f\n", x, y, (x / y));
    } 
    catch (const char* exp) {
        std::cout << "Error: " << exp << std::endl;
    }
    return 0;
}
