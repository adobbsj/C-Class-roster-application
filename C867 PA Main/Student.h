#ifndef Student_hpp
#define Student_hpp
#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "Degree.h"
using namespace std;

//Part D1: Create student class and initialize all given variables (student ID, first name,last name, email address, age, array of number of days to complete each course, degree program)
//Part D2 Create each of the following functions in the Student class:
//a.an accessor(i.e., getter) for each instance variable from part D1
//b.a mutator(i.e., setter) for each instance variable from part D1
//c.All external accessand changes to any instance variables of the Student class must be done using accessorand mutator functions.
//d.constructor using all of the input parameters provided in the table
//e.print() to print specific student data



class Student
{
public:
    const static int days= 3;

private:
    string Student_ID;
    string First_Name;
    string Last_Name;
    string Email;
    int    Age;
    int    Total_Days[days];
    DegreeValue degreevalue;

public:
    Student();

    Student(string Student_ID, string First_Name, string Last_Name, 
            string Email, int Age, int Total_Days[], DegreeValue degreevalue);


    //getter section
    string getStudent_ID();
    string getFirst_Name();
    string getLast_Name();
    string getEmail();
    int    getAge();
    int*   getTotal_Days();
    DegreeValue getDegreeValue();

    //setter section
    void setStudent_ID(string studentID);
    void setFirst_Name (string FName);
    void setLast_Name  (string LName);
    void setEmail      (string email);
    void setAge        (int age);
    void setTotal_Days (int Total_Days[]);
    void setDegreeValue(DegreeValue dv);
    
    //print section
    static void printTitle();
    void print();


    ~Student();
};



#endif 

