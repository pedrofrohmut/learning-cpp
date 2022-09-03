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
    int i = 0;
    while (i <= 20) {
        if (i % 2 == 0) {
            std::cout << "i = " << i << std::endl;
            i++;
            // skips from this point to the next loop cycle skips the rest of the block
            continue;
        }
        if (i == 15) {
            // Breaks out of the loop
            break;
        }
        // default increment (Have to or it will be infinite loop)
        i++;
    }
//------------------------------------------------------------------------------
    vector<string> words;
    stringstream ss("Some random words");
    string word;
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
//------------------------------------------------------------------------------
    int arr3[] = { 1, 2, 3 };
    for (auto x : arr3) std::cout << x << std::endl;
//------------------------------------------------------------------------------
    srand(time(NULL));
    // rand 0 to 10
    int secretNum = rand() % 11;
    int guess = 0;
    do {
        std::cout << "Guess the number: ";
        std::cin >> guess;
        if (guess < secretNum) std::cout << "The guess is to small" << std::endl;
        if (guess > secretNum) std::cout << "The guess is to big" << std::endl;
    } while(guess != secretNum);
    std::cout << "You guessed. The number was " << secretNum << std::endl;
    return 0;
}
