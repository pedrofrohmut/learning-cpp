#include "./Vec3f.hpp"

// Must be in the same order as they are declared
Vec3f::Vec3f() : x(0.0f), y(0.0f), z(0.0f) {}

// Must be in the same order as they are declared
Vec3f::Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}

// rhs - Right Hand Side
// Mark with const (after parentheses) means x, y and z are not being
// modified in this function
Vec3f Vec3f::operator + (const Vec3f& rhs) const
{
    Vec3f result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    result.z = z + rhs.z;
    return result; // Returns a copy
}

// To increment the 3 coordinated by 1 with one command
Vec3f Vec3f::operator ++ ()
{
    x += 1;
    y += 1;
    z += 1;
    return * this;
}

void Vec3f::print_vec3f() const
{
    std::cout << "x: " << x << ", y: " << y << ", z: " << y << '\n';
}
