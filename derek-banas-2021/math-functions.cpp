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
    // There are numerous math functions provided by
    // cmath en.cppreference.com/w/cpp/numeric/math
    // https://cplusplus.com/reference/cmath/
    std::cout << "abs(-10) = " << abs(-10) << std::endl;
    std::cout << "max(5, 4) = " << max(5, 4) << std::endl;
    std::cout << "min(5, 4) = " << min(5, 4) << std::endl;
    std::cout << "fmax(5.3, 4.3.2) = " << fmax(5.3, 4.3) << std::endl;
    std::cout << "fmin(5.3, 4.3) = " << fmin(5.3, 4.3) << std::endl;
    std::cout << "ceil(10.45) = " << ceil(10.45) << std::endl;
    std::cout << "floor(10.45) = " << floor(10.45) << std::endl;
    std::cout << "pow(2, 3) = " << pow(2, 3) << std::endl;
    std::cout << "sqrt(100) = " << sqrt(100) << std::endl;
    std::cout << "cbrt(1000) = " << cbrt(1000) << std::endl;
 
    // e ^ x
    cout << "exp(1) = " << exp(1) << endl;
    // 2 ^ x
    cout << "exp2(1) = " << exp2(1) << endl;
    // e * e * e ~= 20 so log(20.079) ~= 3
    cout << "log(20.079) = " << log(20.079) << endl;
    // 2 * 2 * 2 = 8
    cout << "log2(8) = " << log2(8) << endl;
    // Hypotenuse : SQRT(A^2 + B^2)
    cout << "hypot(2,3) = " << hypot(2,3) << endl;
 
    // Also sin, cos, tan, asin, acos, atan, atan2,
    // sinh, cosh, tanh, asinh, acosh, atanh
 
    return 0;
}
