#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

// following several lines for unit testing purposes
#include "Observer.h"
#include "RecursionCounter.h"
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
std::set<void*> Observer::allocatedCourses;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

// the format for the data file is:
// <Course Number> , <Name> , <Credits>, <Grade>
//
// for example, the following would add four courses to the
// Linked List:
//
//	1400,Introduction to Programming,4,3.6
//	1410,C++ Programming,4,2.6
//	2420,Introduction to Data Structures,4,3.2
//	2810,Computer Architecture,3,3.8

int main()
{
	// specify the input data file (MUST BE HERE. Don't change this location or the grader will have problems!!!!)
	const char dataFileName[] = "data.txt";

	// I've got the file name, now try to open the file for reading
	ifstream fileData;
	fileData.open(dataFileName);
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << dataFileName << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
		return -1;
	}

	// I've got the data file open.
	// read and use the data
	{
		LinkedList courses;
		//		/*********************************
		//		Psuedo Code (students must implement this)
		//		(hint: this is a comma-separated-file)
		//		1. while NOT end-of-file
		//		2.		read in from data file the course number
		//		3.		read in from data file the course name
		//		4.		read in from data file the course cedit hours
		//		5.		read in from data file the course grade
		//		6.		with this data, create a new Course
		//		7.		insert new Course into the LinkedList
		//		*********************************/
		string courseNumber;
		string courseName;
		string credits;
		string grade;

		while (!fileData.eof()) {
			getline(fileData, courseNumber, ',');
			getline(fileData, courseName, ',');
			getline(fileData, credits, ',');
			getline(fileData, grade);

			Course* newCourse = new Course(stoi(courseNumber), courseName, stoul(credits), stod(grade));
			courses.Insert(newCourse);
		}

		fileData.close();

		// display the ordered list of courses
		courses.PrintList();

		double gpa = courses.CalculateGPA();
		cout.precision(4);
		cout << "Cumulative GPA: " << gpa << endl;
	}
	return 0;
}
