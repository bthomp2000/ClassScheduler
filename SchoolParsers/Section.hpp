#ifndef SECTION_H 
#define SECTION_H
#include <string>

class Section{
	friend class Course;
	friend class SectionCombo;
	public:
		class Instructor;
		class Semester;
		class Location;
		class Week;
		class SectionBuilder;

		/*
		 * Getters
		 */
		std::string 		getSectionName() const;
		std::string 		getSectionType() const;
		std::string 		getDescription() const;
		std::string 		getCRN() const;


		Instructor*		getInstructor() const;
		Week* 			getWeek() const;
		Semester*		getSemester() const;
		Location* 		getBuilding() const;
		
	private:
			/*
		 * Constructor
		 */
		Section();

		/*
		 * Destructor
		 */
		~Section();

		/*
		 * Copy Constructor
		 */
		Section(const Section& copy);

		/*
		 * Copy Assignment Operator
		 */
		Section& operator=(const Section& copy);

		/*
		 * Setters
		 */
		void setSectionName(std::string sectionName);
		void setSectionType(std::string sectionType);
		void setDescription(std::string description);
		void setCRN(std::string crn);

		void setInstructor(Instructor* instructor);
		void setDaysOfWeek(Week* daysOfWeek);
		void setSemester(Semester* semester);
		void setLocation(Location* building);

		friend std::ostream& operator<<(std::ostream& os, const Section& section);
		/*
		 * Data Members
		 */

		std::string 	_sectionName;		
		std::string 	_sectionType;	
		std::string 	_description;
		std::string 	_crn;

		Instructor*	_instructor; 
		Week* 		_daysOfWeek;
		Semester* 	_dates;
		Location* 	_bulding;

};
#endif
