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
    Comparable getFirstName();
    Comparable getLastName();
    Comparable getDepartment();
    Comparable getGPA();
    int getId();
    int getBucketId();
    
    void setFirstName(Comparable name);
    void setLastName(Comparable name);
    void setDepartment(Comparable dept);
    void setGPA(Comparable gpa);
    void setId(int id);
    void setBucketId(int id);

private:
    Comparable fname, lname, department;
    Comparable gpa;
    int id;
    int bucketId;
};
#endif