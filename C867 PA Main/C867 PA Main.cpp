#include <iostream>
#include "Roster.h"
using namespace std;

//**CITED WORKS - BEST IMPLEMENTATION PRACTICES HAVE BEEN USED BASED OFF THE COURSE INSTRUCTOR WALKTHROUGH VIDEO SERIES FOR C867 PROVIDED IN THE COURSE TIPS MODULE **



//Part A: add personal information to data table 
//Part B: Create necessary .h and .cpp files
// 
// Part F: funcionality
//Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results :
//1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
//2.  Create an instance of the Roster class called classRoster.
//3.  Add each student to classRoster.
//4.  Convert the following pseudo code to complete the rest of the  main() function :
//	  classRoster.printAll();
//    classRoster.printInvalidEmails();
//loop through classRosterArray and for each element:
//classRoster.printAverageDaysInCourse(/*current_object's student id*/);
//classRoster.printByDegreeProgram(SOFTWARE);
//classRoster.remove("A3");
//classRoster.printAll();
//classRoster.remove("A3");
//expected: the above line should print a message saying such a student with this ID was not found.
//5.  Implement the destructor to release the memory that was allocated dynamically in Roster

int main() {
	cout << "C867 Scripting and Programming:Applications" << endl;
	cout << "Written in C++" << endl;
	cout << "Student ID #: 010111115" << endl;
	cout << "Armondo Dobbs Jr." << endl;

	
const string Data[] =
		{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		  "A5,Armondo,Dobbs Jr.,adobbsj@wgu.edu,23,2,5,3,SOFTWARE"
		};


Roster roster;

//Print all
for (int i = 0; i < Roster::DataTable; i++) roster.parse(Data[i]);
cout << "Displaying all students:" << std::endl;
roster.printAll();
cout << std::endl;

//Print by degree type
cout << "Displaying Students in degree program: SOFTWARE" << std::endl;
roster.printByDegreeValue(DegreeValue:: SOFTWARE);
cout << std::endl;

//print invalid emails
cout << "Displaying invalid emails: " << std::endl;
roster.printInvalidEmails();
cout << std::endl;

//print average days in course
cout << "Displaying average days in course per student:" << std::endl;
for (int i = 0; i < Roster::DataTable; i++)
{
    roster.printAverageDays(roster.classRosterArray[i]->getStudent_ID());
}
cout << std::endl;

//remove student by ID
cout << "Removing A3:" << std::endl;
roster.removeStudentByID("A3");
cout << std::endl;


cout << "Removing A3 again:" << std::endl;
roster.removeStudentByID("A3");
cout << std::endl << std::endl;


}

