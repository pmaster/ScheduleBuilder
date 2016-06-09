// MinClass.cpp, implements MinClass.h
// Peter Master, 5/21

#include "MinClass.h"

Event::Event(std::vector<DayOfTheWeek> days, int start,
            int end, std::vector<int> dates) : days(days),
            start(start), end(end), dates(dates) { }

Event::Event(int date, std::vector<DayOfTheWeek> days, int start, int end) : days(days),
            start(start), end(end), dates(std::vector<int>( )) { dates.push_back(date); }

int Event::get_startTime( ) const {
    return start;
}

void Event::set_startTime(int time) {
    start = time;
}

int Event::get_endTime( ) const {
    return end;
}
void Event::set_endTime(int time) {
    end = time;
}

int Event::get_date( ) const {
    if (dates.empty( ))
        return -1;
    return dates.front( );
}

void Event::set_date(int date) {
    dates.clear( );
    dates.push_back(date);
}

std::vector<DayOfTheWeek> Event::get_days( ) const {
    return days;
}

void Event::set_days(std::vector<DayOfTheWeek> days) {
        this->days = days;
}
Lecture::Lecture(Event lecture, std::vector<Event> sections, Event final)
            : lecture(lecture), final(final), sections(sections) { }

Event Lecture::get_lecture( ) const {
    return lecture;
}

void Lecture::set_lecture(Event lecture) {
    this->lecture = lecture;
}

Event Lecture::get_final( ) const {
    return final;
}

void Lecture::set_final(Event final) {
    this->final = final;
}

std::vector<Event> Lecture::get_sections( ) const {
    return sections;
}

void Lecture::set_sections(std::vector<Event> sections) {
    this->sections = sections;
}


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

std::string MinClass::get_courseID( ) const {
	return courseID;
}

void MinClass::set_courseID(std::string courseID) {
	this->courseID = courseID;
}

std::string MinClass::get_courseTitle( ) const {
	return courseTitle;
}

void MinClass::set_courseTitle(std::string courseTitle) {
	this->courseTitle = courseTitle;
}

std::string MinClass::get_courseTitleFull( ) const {
	return courseTitleFull;
}

void MinClass::set_courseTitleFull(std::string courseTitleFull) {
	this->courseTitleFull = courseTitleFull;
}

/*
Event MinClass::get_detailsFinal( ) const {
	return final;
}

void MinClass::set_detailsFinal(Event final) {

}
*/

std::vector<Lecture> MinClass::get_lectures( ) const {
	return lectures;
}

void MinClass::set_lectures(std::vector<Lecture> lectures) {
	this->lectures = lectures;
}

std::ostream& operator<<(std::ostream& os, const MinClass& obj) {
    std::vector<Lecture> lectures = obj.get_lectures( );

    os << std::endl << obj.get_courseID( );
    if (obj.get_courseTitle( ) != "")
        os << " -- " << obj.get_courseTitle( );
    os << std::endl;
    if (obj.get_courseTitleFull( ) != "")
        os << obj.get_courseTitleFull( ) << std::endl;
    os << std::endl;
    for (unsigned i = 0; i < lectures.size( ); i++)
        os << lectures[i];

    // print details about final here

    return os;
}

std::ostream& operator<<(std::ostream& os, const Lecture& obj) {
    os << obj.get_lecture( ) << std::endl;
    for (unsigned i = 0; i < obj.get_sections( ).size( ); i++) {
        for (int j = 7 - (obj.get_sections( )[i].get_days( ).size( )>2?obj.get_sections( )[i].get_days( ).size( ):2); j > 0; j--)
            os << " ";
        os << obj.get_sections( )[i] << std::endl;
    }
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Event& obj) {
    if (obj.get_days( ).size( )) {
        if (obj.get_days( )[0] == ONLINE)
            os << "ONLINE" << " ";
        else {
            for (unsigned i = 0; i < obj.get_days( ).size( ); i++)
                os << DOTW_to_day_char(obj.get_days( )[i]);
            for (int i = 4 - (obj.get_days( ).size( )>2?2:obj.get_days( ).size( )); i > 0; i--)
                os << " ";
        }
            os << military_to_12hour(obj.get_startTime( )) << " - " << military_to_12hour(obj.get_endTime( ));
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
    int hours = time < 1300 ? time / 100 : (time - 1200) / 100, minutes = time % 100;
    std::stringstream ssHours, ssMinutes;
    ssHours << hours;
    ssMinutes << minutes;
    std::string sHours = ssHours.str( ), sMinutes = ssMinutes.str( );
    std::string result;
    if (sHours == "0")
        sHours = "00";
    if (sHours.length( ) == 1)
        sHours = "0" + sHours;
    if (sMinutes == "0")
        sMinutes = "00";
    /*
    if (time < 100)
        return std::string("12:") + std::to_string(time % 100) + std::string(" AM");
    if (time < 1200)
        return std::to_string((time / 100)) + std::string(":") + std::to_string(time % 100) + std::string(" AM");
    return std::to_string((time - 1200) / 100) + std::string(":") + std::to_string(time % 100) + std::string(" PM");
    }
    */
    if (time < 100)
        return std::string("12:") + sMinutes + std::string("AM");
    if (time < 1200)
        return sHours + std::string(":") + sMinutes + std::string("AM");
    if (time < 1300)
        return std::string("12:") + sMinutes + std::string("PM");
    if (time == 2400)
        return std::string("12:00 AM");
    return sHours + std::string(":") + sMinutes + std::string("PM");
}
