#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
using namespace std;

template <typename Comparable>
class Student
{
public:
    Student();
    string getFirstName();
    string getLastName();
    string getDepartment();
    string getGPA();
    int getId();
    
    void setFirstName(Comparable name);
    void setLastName(Comparable name);
    void setDepartment(Comparable dept);
    void setGPA(Comparable gpa);
    void setId(int id);

private:
    string fname, lname, department;
    string gpa;
    int id;
};
#endif