#include "Course.h"
#include "Student.cpp"
#include <algorithm>
#include <iostream>
using namespace std;

Course::Course(int id, const string& name, int credits) : id(id), name(name), credits(credits) {}

int Course::getId() const{ return id;}
string Course::getName() const{ return name;}
int Course::getCredits() const{ return credits;}

bool Course::hasStudent(const Student& student) const{ return find(students.begin(), students.end(), student) != students.end();}

bool Course::addStudent(Student& student){ if(hasStudent(student)){ return false;} students.push_back(student); return true;}

void Course::dropStudent(Student& student){ for(auto ii = students.begin(); ii != students.end(); ii++){ if((ii)->getId() == student.getId()){ students.erase(ii); break;}}}

void Course::printDetails() const{
    cout << "Course ID: " << id << ", Name: " << name << ", Credits: " << credits << endl << "Enrolled Students:";
    for(const auto& ss : students){ cout << " " << ss.getId();} cout << endl;
}
