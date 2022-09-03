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
    string str1 = "I'm a string";
    std::cout << "1st: " << str1[0] << std::endl;
    std::cout << "Last: " << str1.back() << std::endl;
    std::cout << "Length: " << str1.length() << std::endl;
//------------------------------------------------------------------------------
    string str2 = str1;
    // Get the string without the first 4 characters (split)
    string str3(str2, 4);
    std::cout << "Str3: " << str3 << std::endl;
    // Append with + sign
    string str4 = str3 + " and your are not";
    std::cout << "Str4: " << str4 << std::endl;
    // Append with function
    str4.append("!");
    std::cout << "Str4: " << str4 << std::endl;
    // erase from start = 12 to end = length - 1
    str4.erase(12, str4.length() - 1);
    std::cout << "Str4: " << str4 << std::endl;
    std::cout << "string::npos: " << string::npos << std::endl;
    // npos returns the greates possible value of a element of type size_t
    if (str4.find("string") != string::npos) {
        std::cout << "String index: " << str4.find("string") << std::endl;
    }
    // Substring (return a copy from a slice of the string)
    std::cout << "Substring: " << str4.substr(6, 6) << std::endl;
//------------------------------------------------------------------------------
    char letterZ = 'z';
    char num5 = '5';
    char aSpace = ' ';
    std::cout << "Is Z a letter or a number " << isalnum(letterZ) << std::endl;
    std::cout << "Is Z a letter" << isalpha(letterZ) << std::endl;
    std::cout << "Is Z a number " << isdigit(letterZ) << std::endl;
    
    return 0;
}
