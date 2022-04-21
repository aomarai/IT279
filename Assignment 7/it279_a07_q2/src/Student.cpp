#include "Student.h"

template <typename Comparable>
Student<Comparable>::Student()
{
    fname = "";
    lname = "";
    department = "";
    gpa = "";
}

template <typename Comparable>
string Student<Comparable>::getFirstName()
{
    return fname;
}

template <typename Comparable>
string Student<Comparable>::getLastName()
{
    return lname;
}

template <typename Comparable>
string Student<Comparable>::getDepartment()
{
    return department;
}

template <typename Comparable>
string Student<Comparable>::getGPA()
{
    return gpa;
}

template <typename Comparable>
void Student<Comparable>::setFirstName(Comparable name)
{
    fname = name;
}

template <typename Comparable>
void Student<Comparable>::setLastName(Comparable name)
{
    lname = name;
}
template <typename Comparable>
void Student<Comparable>::setDepartment(Comparable dept)
{
    department = dept;
}

template <typename Comparable>
void Student<Comparable>::setGPA(Comparable gpa)
{
    this->gpa = gpa;
}

template <typename Comparable>
int Student<Comparable>::getId()
{
    return id;
}

template <typename Comparable>
void Student<Comparable>::setId(int id)
{
    this->id = id;
}