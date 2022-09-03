#include "../include/Circle.h"

#include <cmath>

Circle::Circle(double width): Shape(width) {}

Circle::~Circle() {}

// 2*PI*r^2
double Circle::Area()
{
    double radius = width / 2;
    // M_PI = cmath PI value
    return M_PI * pow(radius, 2);
}
