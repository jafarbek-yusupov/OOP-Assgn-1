#include "LMS.h"
#include "Course.cpp"
#include <iostream>
#include <algorithm>

LMS::LMS(const std::string& name) : name(name){}

void LMS::addStudent(Student student){
    for(const auto& s : students){ if(s.getId() == student.getId()){ std::cout << "Student with ID " << student.getId() << " xst" << std::endl; /*check for dups*/ return;}} students.push_back(student);
}

void LMS::addCourse(Course course){
    for(const auto& c : courses){ if(c.getId() == course.getId()){ std::cout << "Course with ID " << course.getId() << " xst" << std::endl; /*check for dups*/ return;}}  courses.push_back(course);
}

void LMS::addStudentToCourse(int studentId, int courseId){
    auto courseIt = std::find_if(courses.begin(), courses.end(), [&](const Course& c) { return c.getId() == courseId; }); // find crs by id
    if(courseIt == courses.end()){ std::cout << "Course with ID " << courseId << " not found" << std::endl; return;}

    auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student& s) { return s.getId() == studentId; }); // find stud by id
    if(studentIt == students.end()){ std::cout << "Student with ID " << studentId << " not found" << std::endl; return;}
//cout << "Student " << studentIt->getName() << " added to course " << courseIt->getName() << ".\n";
    if(!(courseIt->addStudent(*studentIt))){ std::cout << "Student " << studentIt->getName() << " is already enrolled in course " << courseIt->getName() << std::endl;} 
}

void LMS::printDetails() const{
    std::cout << "LMS Name: " << name << std::endl << "Students:" << std::endl; for(Student s: students){ s.printDetails();}
  	std::cout << "Courses:" << std::endl; for(Course i: courses){ i.printDetails();}
}
