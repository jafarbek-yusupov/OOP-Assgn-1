#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

class Course;

class Student{
private:
    int id; std::string name; std::vector<const Course*> enrolledCourses; static const int MAX_ALLOWED_CREDITS = 18;
public:
    Student(int studentId, const std::string& studentName);
    int getId() const;
    std::string getName() const;
    const std::vector<const Course*>& getEnrolledCourses() const;
    bool takesCourse(const Course& course) const;
    bool takeCourse(const Course& course);
    bool dropCourse(const Course& course);
    void printDetails() const;
    bool operator==(const Student& other) const{ return id == other.id;}
};

#endif
