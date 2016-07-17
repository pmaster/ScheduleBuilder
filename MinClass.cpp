// MinClass.cpp, implements MinClass.h
// Peter Master, 5/21

#include "MinClass.h"

Event::Event(std::vector<DayOfTheWeek> days, int start,
            int end, std::vector<int> dates) : days(days),
            start(start), end(end), dates(dates) { }

Event::Event(int date, std::vector<DayOfTheWeek> days,
              int start, int end) : days(days), start(start),
              end(end), dates(std::vector<int>( )) {
    dates.push_back(date);
}

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

bool operator==(const Event &lhs, const Event &rhs) {
    return (lhs.get_startTime( ) == rhs.get_endTime( )) &&
            (lhs.get_days( ) == rhs.get_days( )) &&
            (lhs.get_endTime( ) == rhs.get_endTime( )) &&
            (lhs.get_date( ) == rhs.get_date( ));
}

std::istream& operator>>(std::istream& is, Event& obj) {
    std::vector<DayOfTheWeek> days;
    std::string next;
    int startTime, endTime;
    getline(is, next);
    std::string daysS = next.substr(0, next.length( ) - 17), timesS = next.substr(next.length( ) - 17);
    if (daysS == "ONLINE")
        obj.set_days(vecDays(online));
    else {
        for (unsigned i = 0; i < daysS.length( ); i++) {
            if (daysS[i] == ' ') ;
            else if (daysS[i] == 'M')
                days.push_back(M);
            else if (daysS[i] == 'T')
                days.push_back(T);
            else if (daysS[i] == 'W')
                days.push_back(W);
            else if (daysS[i] == 'R')
                days.push_back(R);
            else if (daysS[i] == 'F')
                days.push_back(F);
            else if (daysS[i] == 'S')
                days.push_back(S);
            else if (daysS[i] == 'N')
                days.push_back(N);
        }
        obj.set_days(days);
    }
    std::string startTimeS = timesS.substr(0, 2) + timesS.substr(3, 2),
                endTimeS = timesS.substr(10, 2) + timesS.substr(13, 2);
    startTime = atoi(startTimeS.c_str( ));
    endTime = atoi(endTimeS.c_str( ));
    if (startTime >= 1200) {
        if (timesS[5] == 'A')
            startTime -= 1200;
        else if (timesS[5] == 'P') ;
    }
    else if (timesS[5] == 'P')
        startTime += 1200;
    obj.set_startTime(startTime);
    if (endTime >= 1200) {
        if (timesS[5] == 'A')
            endTime -= 1200;
        else if (timesS[5] == 'P') ;
    }
    else if (timesS[5] == 'P')
        endTime += 1200;

    obj.set_startTime(startTime);
    obj.set_endTime(endTime);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Event& obj) {
    if (obj.get_days( ).size( )) {
        if (obj.get_days( )[0] == ONLINE)
            os << "ONLINE" << " ";
        else {
            for (unsigned i = 0; i < obj.get_days( ).size( ); i++)
                os << DOTW_to_day_char(obj.get_days( )[i]);
            for (int i = 4 - (obj.get_days( ).size( )>=2?2:1); i > 0; i--)
                os << " ";
        }
            os << military_to_12hour(obj.get_startTime( )) << " - " << military_to_12hour(obj.get_endTime( ));
    }
    return os;
}

std::vector<DayOfTheWeek> days;
    int start, end; // format: military time
    std::vector<int> dates; //format MMDD

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

bool operator==(const Lecture &lhs, const Lecture &rhs) {
    return (lhs.get_lecture( ) == rhs.get_lecture( )) &&
            (lhs.get_sections( ) == rhs.get_sections( )) &&
            (lhs.get_final( ) == rhs.get_final( ));
}

std::istream& operator>>(std::istream& is, Lecture& obj) {
    Event lecture, section;
    std::vector<Event> sections;
    is >> lecture;
    char n = is.get( );
    while (n != '\n') {
        is.putback(n);
        is >> section;
        sections.push_back(section);
        n = is.get( );
    }
    //is.putback(n);

    obj.set_sections(sections);
    obj.set_lecture(lecture);
    return is;
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

bool operator==(const MinClass &lhs, const MinClass &rhs) {
    return (lhs.get_courseID( ) == rhs.get_courseID( )) &&
            (lhs.get_lectures( ) == rhs.get_lectures( )) &&
            (lhs.get_courseTitle( ) == rhs.get_courseTitle( )) &&
            (lhs.get_courseTitleFull( ) == rhs.get_courseTitleFull( ));
}

std::istream& operator>>(std::istream& is, MinClass& obj) {
    std::string courseID, courseTitle = "", courseTitleFull, next;
    getline(is, next);
    std::size_t separate = next.find(" -- ");
    if (separate != std::string::npos) {
        courseTitle = next.substr(separate + 4);
        courseID = next.substr(0, separate);
    }
    getline(is, courseTitleFull);
    if (!(courseTitleFull == ""))
        getline(is, next);

    std::vector<Lecture> lectures;
    Lecture lecture;
    char n = is.get( );
    while (n != '\n') {
        is.putback(n);
        is >> lecture;
        lectures.push_back(lecture);
        n = is.get( );
    }

    obj.set_courseID(courseID);
    obj.set_courseTitle(courseTitle);
    obj.set_courseTitleFull(courseTitleFull);
    obj.set_lectures(lectures);
    return is;
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

Schedule::Schedule(std::vector<std::pair<std::string,Event> > data) : data(data) { }

int Schedule::size( ) const {
    return data.size( );
}

std::vector<std::pair<std::string,Event> > Schedule::get_data( ) const {
    return data;
}

void Schedule::set_data(std::vector<std::pair<std::string,Event> > newData) {
    data = newData;
}

void Schedule::add(std::string text, Event event) {
    this->add(std::pair<std::string,Event>(text,event));
}

void Schedule::add(std::pair<std::string,Event> event) {
    data.push_back(event);
}

bool Schedule::remove(Event event) {
    for (int i = 0; i < data.size( ); i++)
        if (event == data[i].second) {
            data.erase(data.begin( ) + i);
            return true;
        }
    return false;
}

bool operator==(const Schedule &lhs, const Schedule &rhs) {
    if (&lhs == &rhs)
        return true;
    return lhs.get_data( ) == rhs.get_data( );
}

ScheduleSet::ScheduleSet(std::vector<MinClass> classes,
                         std::vector<Event> reservedSpots) :
                         earliest(0), latest(2400),
                         reservedSpots(reservedSpots),
                         classes(classes) { }

int ScheduleSet::get_earliest( ) const {
    return earliest;
}

void ScheduleSet::set_earliest(int earliestTime) {
    earliest = earliestTime;
}

int ScheduleSet::get_latest( ) const {
    return latest;
}

void ScheduleSet::set_latest(int latestTime) {
    latest = latestTime;
}

std::vector<Event> ScheduleSet::get_reservedSpots( ) const {
    return reservedSpots;
}

void ScheduleSet::set_reservedSpots(std::vector<Event> spaces) {
    reservedSpots = spaces;
}

void ScheduleSet::addSpace(Event newSpace) {
    reservedSpots.push_back(newSpace);
}

bool ScheduleSet::removeSpace(Event oldSpace) {
    for (int i = 0; i < reservedSpots.size( ); i++)
        if (oldSpace == reservedSpots[i]) {
            reservedSpots.erase(reservedSpots.begin( ) + i);
            return true;
        }
    return false;
}

std::vector<MinClass> ScheduleSet::get_classes( ) const {
    return classes;
}

void ScheduleSet::set_classes(std::vector<MinClass> newClasses) {
    classes = newClasses;
}

void ScheduleSet::addClass(MinClass newClass) {
    classes.push_back(newClass);
}

bool ScheduleSet::removeClass(MinClass oldClass) {
    for (int i = 0; i < reservedSpots.size( ); i++)
        if (oldClass == classes[i]) {
            classes.erase(classes.begin( ) + i);
            return true;
        }
    return false;
}




std::vector<Schedule> ScheduleSet::generateSchedules( ) const {
    Schedule schedule;
    std::vector<Schedule> schedules;
    for (int i = 0; i < reservedSpots.size( ); i++) {
        if (isUnconflicted(schedule.get_data( ))
    schedGenHelper(schedules, 0)
    return schedules;
}

void ScheduleSet::schedGenHelper(std::vector<Schedule> &schedules, Schedule schedule) const {
    if (schedule.size( ) == reservedSpots.size( ) + classes.size( ))
        schedules.push_back(schedule);
    else {



    }
}

bool ScheduleSet::isUnconflicted(const vector<Event> &events, const Event &event) const {
    for (int i = 0; i < events.size( ); i++) {
        // test if there is any time overlap between event and events[i]
        if (event.get_startTime( ) <= events[i].get_startTime) {
            if (event.get_endTime( ) > events[i].get_startTime)
                // test if there are any common days between event and events[i]
                for (int j = 0; j < event.get_days( ).size( ); j++)
                    for (int k = 0; k < events[i].get_days( ).size( )
                        if (event.get_days( )[j] == events[i].get_days( )[k])
                            return false; // overlap between event and events[i]
        }
        // test if there is any time overlap between event and events[i]
        else if (event.get_startTime( ) < events[i].get_endTime)
            // test if there are any common days between event and events[i]
            for (int j = 0; j < event.get_days( ).size( ); j++)
                for (int k = 0; k < events[i].get_days( ).size( )
                    if (event.get_days( )[j] == events[i].get_days( )[k])
                        return false; // overlap between event and events[i]
    }
    return true; // no overlap between event and any of the events in events
}

bool operator==(const ScheduleSet &lhs, const ScheduleSet &rhs) {
    return (lhs.get_classes( ) == rhs.get_classes( )) &&
            (lhs.get_reservedSpots( ) == rhs.get_reservedSpots( )) &&
            (lhs.get_earliest( ) == rhs.get_earliest( )) &&
            (lhs.get_latest( ) == rhs.get_latest( ));
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

int twelve_to_twentyfour(std::string time) {
    // IMPLEMENT THIS
    return -1;
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
