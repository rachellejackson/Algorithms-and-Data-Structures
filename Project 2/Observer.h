#ifndef __OBSERVER__
#define __OBSERVER__
#include <iostream>
#include <set>
class Observer
{
public:
	Observer(void* course) {
		++numConstructions;
		allocatedCourses.insert(course);
		myCourse = course;
	}
	~Observer() {
		++numDestructions;
		auto found = Observer::allocatedCourses.find(myCourse);
		if (found == Observer::allocatedCourses.end())
			std::cout << "ERROR: Attempting to destruct non-existant course" << std::endl;
		Observer::allocatedCourses.erase(myCourse);
	}
	static int numConstructions;
	static int numDestructions;
	static std::set<void*> allocatedCourses;
private:
	void* myCourse;
};
#endif
