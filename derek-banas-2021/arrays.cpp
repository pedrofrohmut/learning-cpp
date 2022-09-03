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
    int nums1[10] = {1};
    int nums2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int nums3[] = { 8, 9 };
    std::cout << "1st Value: " << nums3[0] << std::endl;
    nums3[0] = 7;
    std::cout << "1st Value: " << nums3[0] << std::endl;
    int nums4[2][2][2] = { 
        { 
            {1, 2}, 
            {3, 4} 
        }, {
            {5, 6}, 
            {7, 8}
        }
    };
    // Get 5 from nums4
    std::cout << nums4[1][0][0] << std::endl;
    return 0;
}
