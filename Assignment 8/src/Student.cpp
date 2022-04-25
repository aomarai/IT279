#include "Student.h"

template <typename Comparable>
Student<Comparable>::Student()
{
    fname = "";
    lname = "";
    department = "";
    gpa = "";
    id = 0;
    bucketId = 0;
}

// Getters

template <typename Comparable>
Comparable Student<Comparable>::getFirstName()
{
    return fname;
}

template <typename Comparable>
Comparable Student<Comparable>::getLastName()
{
    return lname;
}

template <typename Comparable>
Comparable Student<Comparable>::getDepartment()
{
    return department;
}

template <typename Comparable>
Comparable Student<Comparable>::getGPA()
{
    return gpa;
}

template <typename Comparable>
int Student<Comparable>::getId()
{
    return id;
}

template <typename Comparable>
int Student<Comparable>::getBucketId()
{
    return bucketId;
}

// Setters

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
void Student<Comparable>::setId(int id)
{
    this->id = id;
}

template <typename Comparable>
void Student<Comparable>::setBucketId(int id)
{
    this->bucketId = id;
}