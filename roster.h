

#pragma once
#include "student.h"
#ifndef roster_h
#define roster_h
#include <stdio.h>


class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	/*The parse method goes through a set of comma-delimited strings and extracts the data of a student*/
	void parse(string row);
	/*All student data is then passed into add method which creates the Student object and places it in the roster*/
	void add(string sID,
		string sfirst,
		string slast,
		string email,
		int age,
		int sdays1,
		int sdays2,
		int sdays3,
		DegreeProgram dp);

	void printAll();/*calls the print() method in Student class for each student*/
	void printByDegreeProgram(DegreeProgram dp);/*degree type is passed in*/
	void printInvalidEmails();/*each email should include an @ sign and period and should not include a space*/
	void printAverageDaysInCourse(string studentID);/*Prints a student's average number of days in the 3 courses.*/
	void remove(string studentID);  /*Find the student with the supplied ID and remove*/
	~Roster();



};



#endif