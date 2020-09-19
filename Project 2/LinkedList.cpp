#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "Course.h"
using namespace std;

LinkedList::~LinkedList() {
	DestructorHelper(head);
}

// prints the contents of the list of courses to cout
void LinkedList::PrintList() const {
	cout << "Current List: (" << Size() << ")" << endl;
	PrintListHelper(head);
}

// precondition: list is in sorted order
	// postcondition: newCourse is inserted into the list so the list maintains
	//                sorted order. using recursison.
void LinkedList::Insert(Course* newCourse) {
	head = InsertHelper(head, newCourse);
}

// postcondition: size is returned. Must be calculated using recursion.
int LinkedList::Size() const {
	return SizeHelper(head);
}

// calculates the Cumulative GPA of all courses in the list.
	// Cumulative GPA is the sum of all "grade points" divided by the sum of all credits
	// "grade points" is found by multiplying the grade of a course by the number of 
	// credits for that course
	// this must be calculated recursively.
double LinkedList::CalculateGPA() const {
	return CalculateTotalGradePoints(head) / CalculateTotalCredits(head);
}



Course* LinkedList::InsertHelper(Course* head, Course* newCourse)
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here...
	if (head == nullptr) {
		return newCourse;
	}
	else if (newCourse->courseNumber <= head->courseNumber)
	{
		newCourse->next = head;
		return newCourse;
	}
	else
	{
		head->next = InsertHelper(head->next, newCourse);
		return head;
	}
}

int LinkedList::SizeHelper(Course const* cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor == nullptr) {
		return 0;
	}

	else {
		return 1 + SizeHelper(cursor->next);
	}
}

void LinkedList::PrintListHelper(Course const* cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor == nullptr) { //base case-list is empty
		cout << endl;
		return;
	}

	else {
		cout << "cs" << cursor->courseNumber << " " << cursor->courseName << " Grade:" << cursor->grade << " Credit Hours: " << cursor->credits << endl;
		PrintListHelper(cursor->next);
	}
}

void LinkedList::DestructorHelper(Course* cursor)
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor == nullptr) { //base case for recurrsion-list is empty.
		return;
	}
	else {
		DestructorHelper(cursor->next);
		delete cursor;
	}
}

double LinkedList::CalculateTotalGradePoints(Course const* cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	double totalgradepoints = 0;

	if (cursor == nullptr) {
		return 0;
	}

	else {
		totalgradepoints += cursor->grade * cursor->credits;
		return totalgradepoints + CalculateTotalGradePoints(cursor->next);
	}
}

unsigned int LinkedList::CalculateTotalCredits(Course const* cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	int totalcredits = 0;

	if (cursor == nullptr) {
		return 0;
	}

	else {
		totalcredits += cursor->credits;
		return totalcredits + CalculateTotalCredits(cursor->next);
	}
}
