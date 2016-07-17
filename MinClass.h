// MinClass.h
// Peter Master, 5/21

// some assumptions:
// classes may be fully online or have one or more lectures,
// if the classes have lectures, then each lecture will
// occur at the same time on one or more days. Each lecture
// of a class will have its own list of sections (with the
// expectation that students will only enroll in only one)
// and each section will meet at the same time for every day
// that it meets

#ifndef MINCLASS_H
#define MINCLASS_H

#include <iostream>
#include <vector>
#include <algorithm> //find
#include <string> //to_string
#include <sstream> //stringstream

enum DayOfTheWeek {invalid = -1, ONLINE, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday,
                    inv = -1, online, M, T, W, R, F, S, N};
class Event
{
public:
    Event(std::vector<DayOfTheWeek> days = std::vector<DayOfTheWeek>( ), int start = -1,
                int end = -1, std::vector<int> dates = std::vector<int>( ));
    Event(int date, std::vector<DayOfTheWeek> days = std::vector<DayOfTheWeek>( ),
                int start = -1, int end = -1);

    int get_startTime( ) const;
    void set_startTime(int time);
    int get_endTime( ) const;
    void set_endTime(int time);
    int get_date( ) const;
    void set_date(int date);
    std::vector<DayOfTheWeek> get_days( ) const;
    void set_days(std::vector<DayOfTheWeek> days);

private:
    std::vector<DayOfTheWeek> days;
    int start, end; // format: military time
    std::vector<int> dates; //format MMDD
};
bool operator==(const Event &lhs, const Event &rhs);
std::istream& operator>>(std::istream& os, Event& obj);
std::ostream& operator<<(std::ostream& os, const Event& obj);

class Lecture
{
public:
    Lecture(Event lecture = Event( ), std::vector<Event> sections = std::vector<Event>( ),
                Event final = Event( ));

    Event get_lecture( ) const;
    void set_lecture(Event lecture);
    Event get_final( ) const;
    void set_final(Event final);
    std::vector<Event> get_sections( ) const;
    void set_sections(std::vector<Event> sections);

private:
    Event lecture, final;
    std::vector<Event> sections;
};
bool operator==(const Lecture &lhs, const Lecture &rhs);
std::istream& operator>>(std::istream& os, Lecture& obj);
std::ostream& operator<<(std::ostream& os, const Lecture& obj);

class MinClass
{
public:
	MinClass(std::string courseID);
	MinClass(std::vector<Lecture> lectures);
	MinClass(std::string courseID, std::vector<Lecture> lectures);
	//MinClass(std::string goldFullLine);
	//MinClass(std::string goldFullLine, std::vector<Lecture> lectures);

	std::string get_courseID( ) const;
	void set_courseID(std::string courseID);
	std::string get_courseTitle( ) const;
	void set_courseTitle(std::string courseTitle);
	std::string get_courseTitleFull( ) const;
	void set_courseTitleFull(std::string courseTitleFull);
	//Event get_detailsFinal( ) const;
	//void set_detailsFinal(Event final);
	std::vector<Lecture> get_lectures( ) const;
	void set_lectures(std::vector<Lecture> lectures);
	// needed: some member functions to handle 'lectures' vector

private:
	std::string courseID, courseTitle, courseTitleFull; //ex.: CMPSC 56, ADV APP PROGRAM, Advanced Applications Programming
	std::vector<Lecture> lectures;
};
bool operator==(const MinClass &lhs, const MinClass &rhs);
std::istream& operator>>(std::istream& os, MinClass& obj);
std::ostream& operator<<(std::ostream& os, const MinClass& obj);

class Schedule //REWRITE TO HAVE SEPARATE STRING/EVENT VECTORS
{
public:
    Schedule(std::vector<std::pair<std::string,Event> > data =
                std::vector<std::pair<std::string,Event> >( ));

    int size( ) const;
    std::vector<std::pair<std::string,Event> > get_data( ) const;
    void set_data(std::vector<std::pair<std::string,Event> > newData);
    void add(std::string text, Event event);
    void add(std::pair<std::string,Event> event);
    bool remove(Event event);
    // void display( );
private:
    std::vector<std::pair<std::string,Event> > data;
};
bool operator==(const Schedule &lhs, const Schedule &rhs);

class ScheduleSet
{
public:
    ScheduleSet(std::vector<MinClass> classes = std::vector<MinClass>( ),
                std::vector<Event> reservedSpots = std::vector<Event>( ));

    int get_earliest( ) const;
    void set_earliest(int earliestTime);
    int get_latest( ) const;
    void set_latest(int latestTime);

    std::vector<Event> get_reservedSpots( ) const;
    void set_reservedSpots(std::vector<Event> spaces);
    void addSpace(Event newSpace);
    bool removeSpace(Event oldSpace);
    std::vector<MinClass> get_classes( ) const;
    void set_classes(std::vector<MinClass> newClasses);
    void addClass(MinClass newClass);
    bool removeClass(MinClass oldClass);

    std::vector<Schedule> generateSchedules( ) const;

private:
    int earliest, latest;
    // bool breaks;
    std::vector<Event> reservedSpots;
    std::vector<MinClass> classes;

    void schedGenHelper(std::vector<Schedule> &schedules, int counter) const;
    bool isUnconflicted(std::vector<Schedule> &schedules, const Event &event) const;
};
bool operator==(const ScheduleSet &lhs, const ScheduleSet &rhs);

std::string DOTW_to_day_char(DayOfTheWeek d);
std::string military_to_12hour(int time);
int twelve_to_twentyfour(std::string);
std::vector<DayOfTheWeek> vecDays(DayOfTheWeek a = invalid, DayOfTheWeek b = invalid,
                                  DayOfTheWeek c = invalid, DayOfTheWeek d = invalid,
                                  DayOfTheWeek e = invalid, DayOfTheWeek f = invalid,
                                  DayOfTheWeek g = invalid);

/*
class FullClass : public MClass
{
	//add pre-/co-requisites, locations of lectures, final, quarters offered, teachers
	//int units, unitsMin, unitsMax; // not just "units" because some classes have unit ranges
}
*/

#endif
