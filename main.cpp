#include <iostream>
#include "roster.h"
using namespace std;


int main()
{

    cout << "Course Title: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS" << std::endl;
    cout << "Programming Language Used: C++ " << std::endl;
    cout << "Student ID: 010500487" << std::endl;
    cout << "Student Name: Jessica Nichols" << std::endl;
    cout << "   " << std::endl;
    cout << "   " << std::endl;



    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jessica,Nichols,jnic331@wgu.edu,37,40,45,35,SOFTWARE"
    };


    const int numStudents = 5;
    Roster classRoster; /*This creates the roster using the default parameterless constructor; everything is set to 0*/

    /*This displays all students*/
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    cout << std::endl;


    /*This displays all software students*/
    cout << "Displaying all software students:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    /*This displays all incorrectly formatted email addresses*/
    cout << "Displaying invalid email adresses:" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    /*This displays the average number of days each student spends in 3 courses*/
    cout << "Displaying average days per course: " << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;

    /*This removes sudent A3 and prints all remaining students*/
    cout << "Remove student with ID: A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    classRoster.printAll();
    cout << endl;

    /*This tries to remove sudent A3 again and an error message is produced when A3 is not found*/
    cout << "Remove student with ID: A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;

}

