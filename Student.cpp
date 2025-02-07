#include "Student.h"
#include "Course.h"
#include <iostream>

Student::Student(int studentId, const std::string& studentName) : id(studentId), name(studentName) {}

int Student::getId() const{ return id;}
std::string Student::getName() const{ return name;}
const std::vector<const Course*>& Student::getEnrolledCourses() const{ return enrolledCourses;}

bool Student::takesCourse(const Course& course) const{
    for(const Course* enrolledCourse : enrolledCourses){ if(enrolledCourse->getId() == course.getId()){ return true;}}
    return false;
}

bool Student::takeCourse(const Course& course) {
    if(takesCourse(course)){ std::cout << "Student " << id << " is already enrolled in course " << course.getId() << std::endl; return false;}
    int ttl = 0;
    for(const Course* ii : enrolledCourses){ ttl += ii->getCredits();}
    if(ttl+course.getCredits() > MAX_ALLOWED_CREDITS){ std::cout << "Student " << id << " cannot enroll in course " << course.getId() << " (credit limit exceeded)" << std::endl; return false;} 
    enrolledCourses.push_back(&course); return true;
}

bool Student::dropCourse(const Course& course){
    for(auto ii = enrolledCourses.begin(); ii != enrolledCourses.end(); ii++){ if((*ii)->getId() == course.getId()){ enrolledCourses.erase(ii); return true;}}
    return false;
}

void Student::printDetails() const{
    std::cout << "Student ID: " << id << ", Name: " << name << std::endl << "Enrolled Courses:" << std::endl;
    for(const Course* course : enrolledCourses){ std::cout << course->getId() << std::endl;}
}
