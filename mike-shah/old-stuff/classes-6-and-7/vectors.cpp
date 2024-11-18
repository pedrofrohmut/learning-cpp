#include <iostream>

#include "./Vec3f.hpp"

std::ostream& operator << (std::ostream& os, const Vec3f& obj)
{
    os  << "x: " << obj.x << ", y: " << obj.y << ", z: " << obj.z;
    return os;
}

bool operator == (const Vec3f& lhs, const Vec3f& rhs)
{
    return lhs.x == rhs.x &&
           lhs.y == rhs.y &&
           lhs.z == rhs.z;
}

int main()
{
    Vec3f vec(1.0f, 2.0f, 3.0f);
    std::cout << "Vec1: " << vec << '\n';

    Vec3f vec2(3.0f, 2.0f, 1.0f);
    std::cout << "Vec2: " << vec2 << '\n';

    // Operator ==
    std::cout << "Are equal? " << (&vec == &vec2) << '\n';

    // operator '+' add the two vectors
    vec = vec + vec2;
    vec.print_vec3f();

    // operator '++' (prefix) increments the vector fields
    ++vec;
    vec.print_vec3f();

    // operator <<
    std::cout << vec << '\n';

    return 0;
}
