#include <memory>

#include "../headers/Student.hpp"

int main()
{
    // Student instance on the Stack (auto deleted)
    Student pedro("Pedro Frohmut");
    pedro.print_name();

    // Student on the heap (manual deleted)
    Student * camila = new Student("Camila Pitanga");
    camila->print_name();

    // Student with smart pointer
    std::unique_ptr<Student> daiane(new Student("Daiane dos Santos"));
    daiane->print_name();

    // Clean Up: First manual (camila), Second unique_ptr (daiane)
    // and last auto on the stack (pedro)
    delete camila;

    return 0;
}
