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
    // Use vectors when you don't know the size you want your array to be
    // They have variable size
    vector<int> vNums(2);
    vNums[0] = 1;
    vNums[1] = 2;
    vNums.push_back(3);
    std::cout << "Vector size: " << vNums.size() << std::endl;
    return 0;
}
