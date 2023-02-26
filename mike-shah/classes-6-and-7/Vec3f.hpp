#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <iostream>

class Vec3f
{
    public:
        float x, y, z;

        Vec3f();

        Vec3f(float x, float y, float z);

        // rhs - Right Hand Side
        // Mark with const (after parentheses) means x, y and z are not being
        // modified in this function
        Vec3f operator + (const Vec3f& rhs) const;

        // To increment the 3 coordinated by 1 with one command
        Vec3f operator ++ ();

        void print_vec3f() const;
};

#endif
