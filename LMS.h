#ifndef LMS_H
#define LMS_H
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"

class LMS{
	private: std::string name; std::vector<Student> students; std::vector<Course> courses;
	public:
		LMS(const std::string& name);
		void addStudent(Student student);
		void addCourse(Course course);
		void addStudentToCourse(int studentId, int courseId); //void addStudentToCourse(Student student, Course course);
		void printDetails() const;
};

#endif
