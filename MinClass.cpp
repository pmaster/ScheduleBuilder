// MinClass.cpp, implements MinClass.h
// Peter Master, 5/21



MinClass::MinClass(std::string goldFullLine/*SOC 1  - INTRO TO SOCIOLOGY*/) {
	


}

MinClass::MinClass(std::vector<Lecture> lectures) : lectures(lectures) {


}

MinClass::MinClass(std::string courseID, std::vector<Lecture> lectures)
	 : courseID(courseID), lectures(lectures) { 


}

MinClass::MinClass(std::string goldFullLine/*SOC 1  - INTRO TO SOCIOLOGY*/, 
			std::vector<Lecture> lectures) {


}

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
	return courseTitleFull
}

void MinClass::set_detailsFinal(Event final) {
	this->final = final;
}

Event MinClass::get_detailsFinal( ) {
	return final;
}

void MinClass::set_lectures(std::vector<Lecture> lectures) {
	this->lectures = lectures;
}

std::vector<Lecture> MinClass::get_lectures( ) {
	return lectures;
}