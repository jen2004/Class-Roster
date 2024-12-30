


#include "student.h"

/*Parameterless constructor - sets to default values*/

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < courseDaysArraySize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

/*Student constructor*/

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseDaysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;

}

/*deconstructor does nothing - the Student class creates nothing dynamically*/

Student::~Student() {}


string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; } 
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }


void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < courseDaysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }


/*Use to print the header*/

void Student::printHeader()
{
	cout << "Output format: Student ID | First Name |Last Name |Email | Age | Days in Course | Degree\n";
}

/*Use to print Student Data*/

void Student::print()

{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << '\t';
	cout << this->getDaysInCourse()[1] << '\t';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; 
}


