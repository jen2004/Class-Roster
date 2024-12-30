


#include <string>
#include "roster.h"


/*This parses out each row - one at a time*/

void Roster::parse(string studentdata)
{
	/*student ID*/

	int rhs = studentdata.find(",");/*find the comma, return index*/
	string sID = studentdata.substr(0, rhs);/*extract the string in front of the comma*/

	/*first name*/

	int lhs = rhs + 1;/*move past the previous comma*/
	rhs = studentdata.find(",", lhs);
	string fir = studentdata.substr(lhs, rhs - lhs);

	/*last name*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string las = studentdata.substr(lhs, rhs - lhs);

	/*email*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string ema = studentdata.substr(lhs, rhs - lhs);

	/*age*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int ag = stoi(studentdata.substr(lhs, rhs - lhs)); /* stoi converts string to integer*/

	/*days in course 1*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d1 = stoi(studentdata.substr(lhs, rhs - lhs));

	/*days in course 2*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d2 = stoi(studentdata.substr(lhs, rhs - lhs));

	/*days in course 3*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d3 = stoi(studentdata.substr(lhs, rhs - lhs));

	/*degree*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);

	DegreeProgram dp = SECURITY;

	if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') dp = SECURITY;
	else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') dp = SOFTWARE;
	else if (studentdata.at(lhs) == 'N') dp = NETWORK;

	add(sID, fir, las, ema, ag, d1, d2, d3, dp);
	
}

/*Add method*/

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram dp)


{

	/*Put days back into array for constructor*/

	int daysarr[3] = { days1,days2,days3 };

	/*Make the new Student object*/

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysarr, dp);
}

/*displays all students*/

void Roster::printAll() 
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}
	cout << std::endl;
	return;
}

/*displays students which match given degree program*/

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

/*each email should include an @ sign and period and should not include a space*/



void Roster::printInvalidEmails()
{
	bool found = false; /*assumes no invalid emails are found*/
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = this->classRosterArray[i]->getEmailAddress();
		if (emailAddress.find('@') == string::npos)
		{
			cout << "The email: " << emailAddress << " is invalid." << std::endl;
			cout << "Reason: email is missing an '@' sign." << std::endl;
			found = true;
		}
		else if (emailAddress.find('.') == string::npos)
		{
			cout << "The email: " << emailAddress << " is invalid." << std::endl;
			cout << "Reason: email is missing a '.'" << std::endl;
			found = true;
		}
		else if (emailAddress.find(' ') != string::npos)
		{
			cout << "The email: " << emailAddress << " is invalid." << std::endl;
			cout << "Reason: email should not include a space." << std::endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "No invalid emails found.";
	}

}

/*Print Average Days in Course*/

void Roster::printAverageDaysInCourse(string studentID)

{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)

		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;

		}

	}

}

/*Student to be removed comes in as a parameter*/


void Roster::remove(string studentID)
{
	bool success = false; /*assumes student is not found*/
	for (int i = 0; i <= Roster::lastIndex; i++)

	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;/*found student*/
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];/*swaps place with last student*/
				classRosterArray[i] = classRosterArray[numStudents - 1];/*moves pointer*/
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;/*last student is hidden*/

			/*swaps new last index to maintain student ID order*/
			Student* temp = classRosterArray[Roster::lastIndex];
			classRosterArray[Roster::lastIndex] = classRosterArray[Roster::lastIndex - 1];
			classRosterArray[Roster::lastIndex - 1] = temp;

		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << std::endl << std::endl;
	}
	else cout << studentID << " not found." << std::endl << std::endl;;
}

/*destructor for memory cleanup*/

	Roster::~Roster()

{
	cout << "DESTRUCTOR CALLED" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Deleting student " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}



