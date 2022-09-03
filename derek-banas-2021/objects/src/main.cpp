#include <cstdlib>
#include <iostream> // Read write data
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

#include "../include/Shape.h"
#include "../include/Circle.h"

using namespace std;

void ShowArea(Shape& shape);

int main (int argc, char** argv)
{
    Shape rectangle(10, 5);
    ShowArea(rectangle);
    Circle circle(10);
    ShowArea(circle);

    return 0;
}

void ShowArea(Shape& shape)
{
    std::cout << "Area: " << shape.Area() << std::endl;
}
