#include <cstdlib>
#include <iostream> // Read wirete data
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
    // Conditionals Operators > < <= >= == !=
    // Logical Operators && (and) || (or) ! (not)
    string sAge = "";
    cout << "Enter your age: " << endl;
    cin >> sAge;
    int nAge = stoi(sAge);
    if ((nAge >= 1) && (nAge <= 18)) {
        std::cout << "Important birthday" << std::endl;
    } else if ((nAge == 21) || (nAge == 50)) {
        std::cout << "Important birthday" << std::endl;
    } else if (nAge >= 65) {
        std::cout << "Important birthday" << std::endl;
    } else {
        std::cout << "Not an Important birthday" << std::endl;
    }


    int age43 = 43;
    // Ternary Operator
    bool canIVote = (age43 >= 18) ? true : false;
    // Can print true or false instead  of 1 or 0
    cout.setf(ios::boolalpha);
    std::cout << "Can You vote? " << canIVote << std::endl;

    return 0;
}
