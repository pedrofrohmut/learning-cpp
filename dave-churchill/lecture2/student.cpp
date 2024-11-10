#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string first = "";
    std::string last = "";
    int id = 0;
    float avg = 0.0f;

    public:
    Student () {}

    Student(std::string first, std::string last, int id, float avg)
        : first(first), last(last), id(id), avg(avg) {}

    std::string getFirst() const
    {
        return first;
    }

    std::string getLast() const
    {
        return last;
    }

    float getId() const
    {
        return id;
    }

    int getAvg() const
    {
        return avg;
    }

    // Const at the end means that this function will never change the object that calls it
    void print() const
    {
        std::cout << first << " " << last << " " << id << " " << avg << std::endl;
    }

};

class Course
{
    std::string name = "";
    std::vector<Student> students;

public:
    Course() {}

    Course(const std::string& name) : name(name) {}

    // It will not change the argument
    void addStudent(const Student& student)
    {
        this->students.push_back(student);
    }

    // It will not change the returned value
    const std::vector<Student>& getStudents() const
    {
        return this->students;
    }

    void loadFromFile(const std::string& filename)
    {
        std::ifstream filein(filename);
        std::string first, last;
        int id;
        float avg;

        while (filein >> first) {
            filein >> last >> id >> avg;
            Student student(first, last, id, avg);
            this->addStudent(student);
        }
    }

    void print()
    {
        for (const auto& student : this->students) {
            student.print();
        }
    }
};

int main()
{
    Student s1;
    Student s2("John", "Doe", 1, 3.14);
    // You initialize the student but you never want it to change
    const Student s3("Jane", "Smith", 202200001, 99.9);

    std::printf("\n> Printing student 3\n");
    s3.print();

    Course comp4300("COMP 4300");

    // Manually add students
    comp4300.addStudent(s1);
    comp4300.addStudent(s2);
    comp4300.addStudent(s3);
    comp4300.addStudent(Student("Bob", "Dylan", 202200002, 80.8));

    std::printf("\n> Printing students from course comp4300 added manually\n");
    comp4300.print();

    Course c("COMP 4300");

    // Load student from file
    c.loadFromFile("students.txt");

    std::printf("\n> Printing students from course loaded from file\n");
    c.print();

    return 0;
}
