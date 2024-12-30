
#ifndef student_h
#define student_h

#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::string;
using std::cout;


class Student {
public:
	const static int courseDaysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[courseDaysArraySize];
	DegreeProgram degreeProgram;

public:
	
	/*parameterless constructor - sets to default values*/
	Student();

	/*full constructor*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

	/*deconstructor*/
	~Student();

	/*getters*/
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	/*setters*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader(); /* displays a header for the data */

	void print(); /* displays student's data */



};


#endif