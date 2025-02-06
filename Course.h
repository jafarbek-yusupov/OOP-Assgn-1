#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include "Student.h"

class Student;

class Course{
private:
    std::string id; std::string name; int credits; std::vector<Student> students;
public:
    Course(const std::string& id, const std::string& name, int credits);
    std::string getId() const;
    std::string getName() const;
    int getCredits() const;

    bool hasStudent(const Student& student) const;
    bool addStudent(Student& student);
    
    void dropStudent(Student& student);
    void printDetails() const;
};

#endif
