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

std::string MinClass::get_courseTitle( ) {
	return courseTitle;
}

void MinClass::set_courseTitleFull(std::string courseTitleFull) {
	this->courseTitleFull = courseTitleFull;
}

std::string MinClass::get_courseTitleFull( ) {
	return courseTitleFull;
}

void MinClass::set_detailsFinal(Event final) {
	this->final = final;
}

MinClass::Event MinClass::get_detailsFinal( ) {
	return final;
}

void MinClass::set_lectures(std::vector<Lecture> lectures) {
	this->lectures = lectures;
}

std::vector<MinClass::Lecture> MinClass::get_lectures( ) {
	return lectures;
}
