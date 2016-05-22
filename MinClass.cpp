// MinClass.cpp, implements MinClass.h
// Peter Master, 5/21

#include "MinClass.h"

MinClass::MinClass(std::string courseID) : courseID(courseID) {
	courseTitle = "";
	courseTitleFull = "";
}

MinClass::MinClass(std::vector<Lecture> lectures) : lectures(lectures) {
	courseID = "";
	courseTitle = "";
	courseTitleFull = "";
}

MinClass::MinClass(std::string courseID, std::vector<Lecture> lectures)
	 : courseID(courseID), lectures(lectures) {
	 courseTitle = "";
	 courseTitleFull = "";
}

/*
MinClass::MinClass(std::string goldFullLine) {

	// implement an algorithm to break the full line into a string of the course ID
	// followed by the course title
	courseTitleFull = "";
	final.day = invalid;
	lectures.push_back(Event(invalid));
}


MinClass::MinClass(std::string goldFullLine,
			std::vector<Lecture> lectures) {
	// implement an algorithm to break the full line into a string of the course ID
	// followed by the course title
	courseTitleFull = "";
	final.day = invalid;
	lectures.push_back(Event(invalid));
}
*/

void MinClass::set_courseID(std::string courseID) {
	this->courseID = courseID;
}


std::string MinClass::get_courseID( ) const {
	return courseID;
}

void MinClass::set_courseTitle(std::string courseTitle) {
	this->courseTitle = courseTitle;
}

std::string MinClass::get_courseTitle( ) const {
	return courseTitle;
}

void MinClass::set_courseTitleFull(std::string courseTitleFull) {
	this->courseTitleFull = courseTitleFull;
}

std::string MinClass::get_courseTitleFull( ) const {
	return courseTitleFull;
}

void MinClass::set_detailsFinal(Event final) {
	this->final = final;
}

MinClass::Event MinClass::get_detailsFinal( ) const {
	return final;
}

void MinClass::set_lectures(std::vector<Lecture> lectures) {
	this->lectures = lectures;
}

std::vector<MinClass::Lecture> MinClass::get_lectures( ) const {
	return lectures;
}

std::ostream& operator<<(std::ostream& os, const MinClass& obj) {
    std::vector<MinClass::Lecture> lectures = obj.get_lectures( );

    os << std::endl << obj.get_courseID( );
    if (obj.get_courseTitle( ) != "")
        os << " -- " << obj.get_courseTitle( );
    os << std::endl;
    if (obj.get_courseTitleFull( ) != "")
        os << obj.get_courseTitleFull( ) << std::endl;
    os << std::endl;
    for (unsigned i = 0; i < lectures.size( ); i++)
        os << lectures[i] << std::endl;

    // print details about final here

    return os;
}

std::ostream& operator<<(std::ostream& os, const MinClass::Lecture& obj) {
    os << obj.lecture << std::endl;
    for (unsigned i = 0; i < obj.sections.size( ); i++)
        os << "     " << obj.sections[i] << std::endl;
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const MinClass::Event& obj) {
    if (obj.days.size( )) {
        if (obj.days[0] == ONLINE)
            os << "ONLINE";
        else
            for (unsigned i = 0; i < obj.days.size( ); i++)
                os << DOTW_to_day_char(obj.days[i]) << military_to_12hour(obj.start)
                << "-" << military_to_12hour(obj.end);
    }
    return os;
}

std::vector<DayOfTheWeek> vecDays(DayOfTheWeek a, DayOfTheWeek b,
                                  DayOfTheWeek c, DayOfTheWeek d,
                                  DayOfTheWeek e, DayOfTheWeek f,
                                  DayOfTheWeek g) {
    std::vector<DayOfTheWeek> days, daysSorted;
    if (a != invalid) {
        days.push_back(a);
        if (b != invalid) {
            days.push_back(b);
            if (c != invalid) {
                days.push_back(c);
                if (d != invalid) {
                    days.push_back(d);
                    if (e != invalid) {
                        days.push_back(e);
                        if (f != invalid) {
                            days.push_back(f);
                            if (g != invalid)
                                days.push_back(g);}}}}}}
    if (std::find(days.begin( ), days.end( ), online) != days.end( )) {
        days.clear( );
        days.push_back(online);
    }
    for (int d = 1 /*monday*/; d <= 7 /*sunday*/; d++) {
        if (std::find(days.begin( ), days.end( ), d) != days.end( ))
            daysSorted.push_back(DayOfTheWeek(d));
    }
    return daysSorted;
}

std::string DOTW_to_day_char(DayOfTheWeek d) {
    if (d == invalid)
        return "invalid";
    else if (d == online)
        return "ONLINE";
    else if (d == M)
        return "M";
    else if (d == T)
        return "T";
    else if (d == W)
        return "W";
    else if (d == R)
        return "R";
    else if (d == F)
        return "F";
    else if (d == Saturday)
        return "S";
    else if (d == Sunday)
        return "N";
    return "error";
}

std::string military_to_12hour(int time) {
    int hours = time > 1159 ? (time - 1200) / 100 : time / 100, minutes = time % 100;
    std::stringstream ssHours, ssMinutes;
    ssHours << hours;
    ssMinutes << minutes;
    std::string sHours = ssHours.str( ), sMinutes = ssMinutes.str( );
    std::string result;
    /*
    if (time < 100)
        return std::string("12:") + std::to_string(time % 100) + std::string(" AM");
    if (time < 1200)
        return std::to_string((time / 100)) + std::string(":") + std::to_string(time % 100) + std::string(" AM");
    return std::to_string((time - 1200) / 100) + std::string(":") + std::to_string(time % 100) + std::string(" PM");
    }
    */
    if (time < 100)
        return std::string("12:") + sMinutes + std::string(" AM");
    if (time < 1200)
        return sHours + std::string(":") + sMinutes + std::string(" AM");
    if (time == 2400)
        return std::string("12:00 AM");
    return sHours + std::string(":") + sMinutes + std::string(" PM");
}
