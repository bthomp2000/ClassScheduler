#include "Time.hpp"
/*
 * ======================================================
 * Object Creation
 * ======================================================
 */
Section::Week::Time::Time(int hour, int minute){
	if(not Time::validHour(hour) or not Time::validMinute(minute)){
		this->_hour = 0;
		this->_minute = 0;
	}
	else{
		this->_hour = hour;
		this->_minute = minute;
	}

}
Section::Week::Time::Time(const Time& copy){
	this->_hour = copy._hour;
	this->_minute = copy._minute;
}
Section::Week::Time::~Time(){
	return;
}
Section::Week::Time& Section::Week::Time::operator=(const Time& copy){
	this->_hour = copy._hour;
	this->_minute = copy._minute;
	return *this;
}


/*
 * ======================================================
 * Getters and Setters
 * ======================================================
 */
int Section::Week::Time::getHour() const {
	return _hour;
}
int Section::Week::Time::getMinute() const {
	return _minute;
}
bool Section::Week::Time::setHour(int hour){
	if(not Time::validHour(hour)){
		return false;
	}
	this->_hour = hour;
	return true;
}
bool Section::Week::Time::setMinute(int minute){
	if(not Time::validMinute(minute)){
		return false;
	}
	this->_minute = minute;
	return true;
}

/*
 * ======================================================
 * Static functions
 * ======================================================
 */
bool Section::Week::Time::before(const Time* first, const Time* second){
	if(first->getHour() > second->getHour()){
		return false;
	}
	else if(first->getHour() < second->getHour()){
		return true;
	}
	else if(first->getMinute() >= second->getMinute()){
		return false;
	}
	return true;
}
bool Section::Week::Time::validHour(int hour){
	return (hour <= 23) and (hour >= 0);
}
bool Section::Week::Time::validMinute(int minute){
	return (minute <= 59) and (minute >= 0);
}
/*
 * ======================================================
 * Additional Functionality
 * ======================================================
 */
Section::Week::Time Section::Week::Time::operator+(const Time& second) const{
	Time t;
	bool minOverflow = false;
	if(this->_minute + second._minute> 59){
		minOverflow = true;	
		t._minute = (this->_minute + second._minute)%60;
	}
	t._hour = (this->_hour + second._hour)%24;
	if(minOverflow){
		t._hour++;
	}
	return t;
}
std::ostream& operator<<(std::ostream& os, const Section::Week::Time& time){
	
	std::string min = std::to_string(time._minute);
	std::string hour = std::to_string(time._hour);

	if(time._hour <10){
		hour = "0"+std::to_string(time._hour);
	}

	if(time._minute < 10){
		min = "0"+std::to_string(time._minute);
	}

	os<<hour<<":"<<min;
	return os;
}
