// MinClass.h
// Peter Master, 5/21

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

std::string DOTW_to_day_char(DayOfTheWeek d);
std::string military_to_12hour(int time);
int twelve_to_twentyfour(std::string);
std::istream& operator>>(std::istream& os, MinClass& obj);
std::ostream& operator<<(std::ostream& os, const MinClass& obj);
std::istream& operator>>(std::istream& os, Lecture& obj);
std::ostream& operator<<(std::ostream& os, const Lecture& obj);
std::istream& operator>>(std::istream& os, Event& obj);
std::ostream& operator<<(std::ostream& os, const Event& obj);
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
