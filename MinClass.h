// MinClass.h
// Peter Master, 5/21

#ifndef MINCLASS_H
#define MINCLASS_H

#include <iostream>
#include <vector>

enum DayOfTheWeek {invalid = -1, ONLINE, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday,
                    inv = -1, online, M, T, W, R, F, S, N};

class MinClass
{
public:
	struct Event {
	    Event(std::vector<DayOfTheWeek> days = std::vector<DayOfTheWeek>(0), int start = -1,
           int end = -1) : days(days), start(start), end(end) { }
		std::vector<DayOfTheWeek> days;
		int start, end; // format: military time
	};

	struct Lecture {
	    Lecture(Event lecture = Event( ), std::vector<Event> sections = std::vector<Event>( ))
        : lecture(lecture), sections(sections) { }
		Event lecture;
		std::vector<Event> sections;
	};

	MinClass(std::string courseID);
	MinClass(std::vector<Lecture> lectures);
	MinClass(std::string courseID, std::vector<Lecture> lectures);
	//MinClass(std::string goldFullLine);
	//MinClass(std::string goldFullLine, std::vector<Lecture> lectures);

	void set_courseID(std::string courseID);
	std::string get_courseID( ) const;
	void set_courseTitle(std::string courseTitle);
	std::string get_courseTitle( );
	void set_courseTitleFull(std::string courseTitleFull);
	std::string get_courseTitleFull( );
	void set_detailsFinal(Event final);
	Event get_detailsFinal( );
	void set_lectures(std::vector<Lecture> lectures);
	std::vector<Lecture> get_lectures( );
	// needed: some member functions to handle 'lectures' vector

private:
	std::string courseID, courseTitle, courseTitleFull; //ex.: CMPSC 56, ADV APP PROGRAM, Advanced Applications Programming
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

#endif
