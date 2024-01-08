#include "Student.h"

//Part D1: Create student class and initialize all given variables (student ID, first name,last name, email address, age, array of number of days to complete each course, degree program)
//Part D2 Create each of the following functions in the Student class:
//a.an accessor(i.e., getter) for each instance variable from part D1
//b.a mutator(i.e., setter) for each instance variable from part D1
//c.All external accessand changes to any instance variables of the Student class must be done using accessorand mutator functions.
//d.constructor using all of the input parameters provided in the table
//e.print() to print specific student data







//cunstructor with no parameters
Student::Student()
{
    this->Student_ID = "";
    this->First_Name = "";
    this->Last_Name =  "";
    this->Email  =     "";
    this->Age = 0;
    for (int i = 0; i < days; i++) this->Total_Days[i] = 0;
    this->degreevalue = DegreeValue::NETWORK;
}

//constructor with parameters
Student::Student(string Student_ID, string First_Name, string Last_Name, string Email, int Age, int Total_Days[], DegreeValue degreevalue)
{
    
    this->Student_ID = Student_ID;
    this->First_Name = First_Name;
    this->Last_Name = Last_Name;
    this->Email = Email;
    this->Age = Age;
    for (int i = 0; i < days; i++) this->Total_Days[i] = Total_Days[i];
    this->degreevalue = degreevalue;
}

Student::~Student() {}


//getter with associated setter
string Student::getStudent_ID()       {return this->Student_ID;}
  void Student::setStudent_ID(string Student_ID) {this->Student_ID = Student_ID;}

string Student::getFirst_Name()       {return this->First_Name;}
  void Student::setFirst_Name(string First_Name) {this->First_Name = First_Name;}

string Student::getLast_Name()        {return this->Last_Name;}
  void Student::setLast_Name(string Last_Name) {this->Last_Name = Last_Name;}

string Student::getEmail()            {return this->Email;}
  void Student::setEmail(string Email) {this->Email = Email;}

 int Student::getAge()                 {return this->Age;}
void Student::setAge(int Age) { this->Age = Age; }

int* Student::getTotal_Days()         {return this->Total_Days;}
void Student::setTotal_Days(int Total_Days[]) {for (int i = 0; i < days; i++) this->Total_Days[i] = Total_Days[i];}

DegreeValue Student::getDegreeValue() {return this->degreevalue;}
void Student::setDegreeValue(DegreeValue dv) {this->degreevalue = dv;}



//print section
void Student::printTitle()
{
    cout << "ID" << '\t'
         << "First Name" << '\t' 
         << "Last Name" << '\t'
         << "Email Address" << '\t'
         << "Age" << '\t' 
         << "Days to Complete" << '\t' 
         << "Degree" << std::endl;
}

void Student::print()
{

    string Degree_Value;
    if (degreevalue == DegreeValue::SECURITY) {Degree_Value = "SECURITY";}
    else if (degreevalue == DegreeValue::NETWORK)  {Degree_Value = "NETWORK";}
    else if (degreevalue == DegreeValue::SOFTWARE) {Degree_Value = "SOFTWARE";}
    cout << this->getStudent_ID() << '\t';
    cout << this->getFirst_Name() << '\t';
    cout << this->getLast_Name() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getTotal_Days()[0] << ',';
    cout << this->getTotal_Days()[1] << ',';
    cout << this->getTotal_Days()[2] << '\t';
    cout << Degree_Value << '\n';
}
