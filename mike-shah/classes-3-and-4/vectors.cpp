#include <iostream>
#include <string>

class Vector3
{
    public:
        float x, y, z;

        Vector3()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        void print(std::string name)
        {
            std::cout << name    << ": x: " << this->x << ", y: "
                      << this->y << ", z: " << this->z << std::endl;
        }
};

int main()
{
    Vector3 vec1;
    vec1.x = 1.0f; vec1.y = 2.0f; vec1.z = 3.0f;
    vec1.print("Vec1");

    Vector3 vec2 = vec1;
    vec2.print("Vec2");

    return 0;
}
