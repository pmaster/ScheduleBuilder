// implements class Class
// Peter Master, 5/21

#include <iostream>
#include <vector>

enum DayOfTheWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

struct Event {
	unsigned start, end; // format: military time
	DayOfTheWeek day;
	// char EnrollCode[5];
};

struct Lecture {
	Event lecture;
	std::vector<Event> sections;
};

class MinClass
{
public:
	MinClass(std::string goldFullLine/*SOC 1  - INTRO TO SOCIOLOGY*/, )
	MinClass(std::string dept, std::string deptID, std::vector<Lecture> lectures) :
		dept(dept), deptID(deptID), lectures(lectures) { }
	MinClass(std::vector<Lecture> lectures) : lectures(lectures) { }

private:
	std::string dept, deptID, title, fullTitle; //ex.: CMPSC, 56, ADV APP PROGRAM, Advanced Applications Programming
	std::vector<Lecture> lectures;
	Event final;
};

/*
class FullClass : public MClass
{
	//add pre-/co-requisites, locations of lectures, final, quarters offered
	//int units, unitsMin, unitsMax; // not just "units" because some classes have unit ranges
}
*/