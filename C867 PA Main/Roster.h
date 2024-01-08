#pragma once
#include "Student.h"
#ifndef Roster_h
#define Roster_h
#include <stdio.h>


//Part E #1.Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
// #3.  Define the following functions :
//  a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
//  b.  public void remove(string studentID)  that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.
//  c. public void printAll() that prints a complete tab - separated list of student data in the provided format : A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.
//    The printAll() function should loop through all the students in classRosterArrayand call the print() function for each student.
//  d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.
//  e.  public void printInvalidEmails() that verifies student email addressesand displays all invalid email addresses to the user.
//  f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type

class Roster
{
public:
    int index = -1;
    const static int DataTable = 5;
    Student* classRosterArray[DataTable];

public:
    
    void parse(string row);
    void add(string Roster_Student_ID, string Roster_First_Name, string Roster_Last_Name, string Roster_Email, int Roster_Age, int Day_1, int Day_2, int Day_3, DegreeValue dv);
    void printAll();
    void printByDegreeValue(DegreeValue dt);
    void printInvalidEmails();
    void printAverageDays(string studentID);
    bool removeStudentByID(string studentID);

    ~Roster();
};

#endif 
