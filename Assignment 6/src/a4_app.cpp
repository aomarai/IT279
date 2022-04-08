#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <sstream> // std::stringstream

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

int main()
{
    string id, firstName, lastName, department, gpa;
    cout << "Assignment 06 (Ashkan Omaraie):" << endl;
    
    //Read the text file enroll_test.txt in the data folder
    ifstream file("../data/enroll_test.txt");

    //Create hash table of student objects with 7 buckets
    HashTable<string> ht(7);

    //Read the file line by line. The first word is the id, second word is firstName, third word is lastname, fourth word is department, fifth word is gpa
    while (file >> id >> firstName >> lastName >> department >> gpa)
    {
        //Create a student object with the id, firstName, lastName, department, gpa
        Student<string> tempStudent;
        tempStudent.setFirstName(firstName);
        tempStudent.setLastName(lastName);
        tempStudent.setDepartment(department);
        tempStudent.setGPA(gpa);

        //Insert the student object to the hash table using the id as the key
        ht.insert(id, tempStudent);
    }

    //Print out all the buckets in the hash table
    ht.displayHash();
}