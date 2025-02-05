#include "LMS.h"
#include <iostream>
#include <algorithm>
using namespace std;

LMS::LMS(const string& name) : name(name) {}

void LMS::addStudent(Student student) {
    for(const auto& s : students){ if(s.getId() == student.getId()){ cout << "Student with ID " << student.getId() << " already exists!!!\n"; /*check for dups*/ return;}} students.push_back(student);
}

void LMS::addCourse(Course course) {
    for(const auto& c : courses){ if(c.getId() == course.getId()){ cout << "Course with ID " << course.getId() << " already exists!!!\n"; /*check for dups*/ return;}} courses.push_back(course);
}

void LMS::addStudentToCourse(int studentId, const string& courseId){
    auto courseIt = find_if(courses.begin(), courses.end(), [&courseId](const Course& c){ return c.getId() == courseId;}); // find crs by id
    if(courseIt == courses.end()){ cout << "Course with ID " << courseId << " not found!!!!\n"; return;}

    auto studentIt = find_if(students.begin(), students.end(), [studentId](const Student& s){ return s.getId() == studentId;}); // find stud by id
    if(studentIt == students.end()){ cout << "Student with ID " << studentId << " not found!!!!\n"; return;}

    if(courseIt->addStudent(*studentIt)){ cout << "Student " << studentIt->getName() << " added to course " << courseIt->getName() << ".\n";} 
	else{ cout << "Student " << studentIt->getName() << " is already enrolled in course " << courseIt->getName() << ".\n";}
}
