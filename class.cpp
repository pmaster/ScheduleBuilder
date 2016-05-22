// implements class Class
// Peter Master, 5/21

#include <iostream>
#include <vector>

enum DayOfTheWeek {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

struct Lecture {
	Event lecture;
	std::vector<event> sections;
};

struct Event {
	unsigned start, end; // format: military time
	DayOfTheWeek day;

};

class MinClass
{
public:

//units, lecture time, quarters/sessions offered, prerequisites, location, final

private:
	int units, unitsMin, unitsMax; // not just "units" because some classes have unit ranges
	int sectionCode;
	std::string dept, deptID, title, fullTitle; //ex.: CS, 56, ADV APP PROGRAM, Advanced Applications Programming
	std::vector<Lecture> lectures;
	Event final;
}

/*
class FullClass : public MClass
{
	//add pre-/co-requisites, locations of lectures, final
	//int units, unitsMin, unitsMax; // not just "units" because some classes have unit ranges
}
*/