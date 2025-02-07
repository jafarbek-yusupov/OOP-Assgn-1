#include "LMS.h"
#include "Course.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

LMS::LMS(const string& name) : name(name){}

void LMS::addStudent(Student student){
    for(const auto& s : students){ if(s.getId() == student.getId()){ cout << "Student with ID " << student.getId() << " xst" << endl; /*check for dups*/ return;}} students.push_back(student);
}

void LMS::addCourse(Course course){
    for(const auto& c : courses){ if(c.getId() == course.getId()){ cout << "Course with ID " << course.getId() << " xst" << endl; /*check for dups*/ return;}}  courses.push_back(course);
}

void LMS::addStudentToCourse(int studentId, int courseId){
    auto courseIt = std::find_if(courses.begin(), courses.end(), [&](const Course& c) { return c.getId() == courseId; }); // find crs by id
    if(courseIt == courses.end()){ cout << "Course with ID " << courseId << " not found" << endl; return;}

    auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student& s) { return s.getId() == studentId; }); // find stud by id
    if(studentIt == students.end()){ cout << "Student with ID " << studentId << " not found" << endl; return;}
//cout << "Student " << studentIt->getName() << " added to course " << courseIt->getName() << ".\n";
    if(!(courseIt->addStudent(*studentIt))){ cout << "Student " << studentIt->getName() << " is already enrolled in course " << courseIt->getName() << endl;} 
}

void LMS::printDetails() const{
    cout << "LMS Name: " << name << endl << "Students:" << endl; for(Student s: students){ s.printDetails();}
  	cout << "Courses:" << endl; for(Course i: courses){ i.printDetails();}
}
