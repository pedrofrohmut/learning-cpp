#include <iostream>

class Vec3f
{
    public:
        float x, y, z;

        Vec3f() { x = 0.0f; y = 0.0f; z = 0.0f; }

        Vec3f(const float a, const float b, const float c) { x = a; y = b; z = c; }

        // rhs - Right Hand Side
        // Mark with const (after parentheses) means x, y and z are not being
        // modified in this function
        Vec3f operator + (const Vec3f& rhs) const
        {
            Vec3f result;
            result.x = x + rhs.x;
            result.y = y + rhs.y;
            result.z = z + rhs.z;
            return result; // Returns a copy
        }

        // To increment the 3 coordinated by 1 with one command
        Vec3f operator ++ ()
        {
            x += 1;
            y += 1;
            z += 1;
            return * this;
        }

};

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

void print_vec3f(const Vec3f& vec)
{
    std::cout << "x: " << vec.x << ", y: " << vec.y << ", z: " << vec.y << '\n';
}

int main()
{
    Vec3f vec;
    vec.x = 1.f;
    vec.y = 2.f;
    vec.z = 3.f;

    Vec3f vec2;
    vec2.x = 3.f;
    vec2.y = 2.f;
    vec2.z = 1.f;

    // Operator ==
    std::cout << "Are equal? " << (&vec == &vec2) << '\n';

    // operator '+' add the two vectors
    vec = vec + vec2;
    print_vec3f(vec);

    // operator '++' (prefix) increments the vector fields
    ++vec;
    print_vec3f(vec);

    // operator <<
    std::cout << vec << '\n';

    return 0;
}
