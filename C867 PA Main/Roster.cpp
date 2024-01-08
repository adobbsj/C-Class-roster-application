#include <string>
#include "Roster.h"

//Part E: Create a Roster class (roster.cpp) by doing the following :
//1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
//2.  Create a student object for each student in the data tableand populate classRosterArray.
//  a.Parse each set of data identified in the “studentData Table.”
//  b.Add each student object to classRosterArray.
//3.  Define the following functions :
//  a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
//  b.  public void remove(string studentID)  that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.
//  c. public void printAll() that prints a complete tab - separated list of student data in the provided format : A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.
//    The printAll() function should loop through all the students in classRosterArrayand call the print() function for each student.
//  d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.
//  e.  public void printInvalidEmails() that verifies student email addressesand displays all invalid email addresses to the user.
//  f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type


//  data parse to organize information
void Roster::parse(string data)

{
    int rhs = data.find(',');
    string Roster_Student_ID = data.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = data.find(',', lhs);
    string Roster_First_Name = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(',', lhs);
    string Roster_Last_Name = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string Roster_Email = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int Roster_Age = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = data.find(",", lhs);
    int Day_1 = stod(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = data.find(",", lhs);
    int Day_2 = stod(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = data.find(",", lhs);
    int Day_3 = stod(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);

    DegreeValue dv = DegreeValue::SECURITY;

    if (data.at(lhs) == 'S' && data.at(lhs + 1) == 'E') dv = DegreeValue::SECURITY;
    else if (data.at(lhs) == 'S' && data.at(lhs + 1) == 'O') dv = DegreeValue::SOFTWARE;
    else if (data.at(lhs) == 'N') dv = DegreeValue::NETWORK;

    //string Degree_Value;
    //if (degreevalue == DegreeValue::SECURITY) { Degree_Value = "SECURITY"; }
    //else if (degreevalue == DegreeValue::NETWORK) { Degree_Value = "NETWORK"; }
    //else if (degreevalue == DegreeValue::SOFTWARE) { Degree_Value = "SOFTWARE"; }

    add(Roster_Student_ID, Roster_First_Name, Roster_Last_Name, Roster_Email, Roster_Age, Day_1, Day_2, Day_3, dv);

}

//add students to roster
void Roster::add(string Student_ID, string First_Name, string Last_Name, string Email, int Age, int Day_1, int Day_2, int Day_3, DegreeValue dv)
{
    
    int Tdays[3] = { Day_1, Day_2, Day_3 };
    
    
    classRosterArray[++index] = new Student(Student_ID, First_Name, Last_Name, Email, Age, Tdays, dv);
}

//print all function
void Roster::printAll()
{
    Student::printTitle();
    for (int i = 0; i <= Roster::index; i++) Roster::classRosterArray[i]->print();
}

//invalid email function
void Roster::printInvalidEmails()
{
    bool Assume = false;
    
    for (int i = 0; i <= Roster::index; i++)
    {
        string Inv_Email = (classRosterArray[i]->getEmail());
        if ((Inv_Email.find("@") == string::npos) || (Inv_Email.find(" ") != string::npos) || (Inv_Email.find(".") == string::npos))
        {
            Assume = true;
            cout << Inv_Email << ":" << classRosterArray[i]->getFirst_Name() << std::endl;
        }
    }
    if (!Assume) cout << "NONE" << std::endl;
}

//Calculate Average days in course function
void Roster::printAverageDays(string Student_ID)
{
    for (int i = 0; i <= Roster::index; i++)
    {
        if (classRosterArray[i]->getStudent_ID() == Student_ID)
        {   
            cout << "Student ID:";
            cout << Student_ID << ", average days in course is: " ;
            cout << (classRosterArray[i]->getTotal_Days()[0] +
                     classRosterArray[i]->getTotal_Days()[1] +
                     classRosterArray[i]->getTotal_Days()[2]) / 3 
                 << std::endl;
        }
    }
}

//students in degree program function
void Roster::printByDegreeValue(DegreeValue dv)
{
    Student::printTitle();
    for (int i = 0; i <= Roster::index; i++) 
    {
        if (Roster::classRosterArray[i]->getDegreeValue() == dv) classRosterArray[i]->print();
    }
    cout << std::endl;
}

//remove student function
bool Roster::removeStudentByID(string Student_ID)
{
    bool Confirm = false; 
    for (int i = 0; i <= Roster::index; i++)
        
    {
        if (classRosterArray[i]->getStudent_ID() == Student_ID)
        {
            Confirm = true;
            if (i < DataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[DataTable - 1];
                classRosterArray[DataTable - 1] = temp;
            }
            Roster::index--;
        }
    }
    if (Confirm)
    {
        cout << Student_ID << " removed from roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << "The student with the ID:" << Student_ID << " not found." << std::endl << std::endl;;
    return 0;
}

//roster destructor
Roster::~Roster()
{
    cout << "Implementing Destructor to release memory" << std::endl << std::endl;
    for (int i = 0; i < DataTable; i++)
    {
        cout << "Removing student A" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
