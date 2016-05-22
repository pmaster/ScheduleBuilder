// MinClass.h
// Peter Master, 5/21

#include <iostream>
#include <vector>

enum DayOfTheWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

class MinClass
{
public:
	struct Event {
		unsigned start, end; // format: military time
		DayOfTheWeek day;
		// char EnrollCode[5];
	};

	struct Lecture {
		Event lecture;
		std::vector<Event> sections;
	};

	MinClass(std::string goldFullLine/*SOC 1  - INTRO TO SOCIOLOGY*/);
	MinClass(std::vector<Lecture> lectures);
	MinClass(std::string courseID, std::vector<Lecture> lectures);
	MinClass(std::string goldFullLine/*SOC 1  - INTRO TO SOCIOLOGY*/, 
			std::vector<Lecture> lectures);

	void set_courseID(std::string courseID);
	std::string get_courseID( ) const;
	

private:
	std::string courseID, title, fullTitle; //ex.: CMPSC 56, ADV APP PROGRAM, Advanced Applications Programming
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