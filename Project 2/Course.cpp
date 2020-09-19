#include "Course.h"

Course::Course(int courseNumber, std::string courseName, unsigned int credits, double grade) : tmp(this)
{
	// the initialization of the variable tmp MUST be done as shown above.
	// this is for Unit Testing to work.

	// your code goes here...
	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->credits = credits;
	this->grade = grade;
	next = nullptr;
}
