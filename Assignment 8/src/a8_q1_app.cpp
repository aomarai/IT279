#include "Student.h"
#include "Student.cpp"
#include "DisjSet.h"
#include "DisjSet.cpp"

#include "DoubleHash.h"
#include "DoubleHash.cpp"
//#include "Utilities.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

//#include "MergeSort.h"
//#include "QuickSort.h"
//#include "ShellSort.h"

using namespace std;

void printStudent(int i, Student<string> student)
{
    string lineStr;
    if (i < 10)
        lineStr = " ----------------> ";
    else
        lineStr = " ---------------> ";

    cout << i << lineStr << to_string(student.getId()) << "   " << student.getFirstName()
         << " " << student.getLastName() << "   " << student.getDepartment() << "   "
         << student.getGPA() << endl;
}

// Test program
int main()
{
    string strline2 = "--------------------------------------------------------------------";
    cout << strline2 << endl;
    cout << "Assignment 08, Question 01 (Ashkan Omaraie):" << endl;

    string id, firstName, lastName, department, gpa;
    string line;

    // Read in the file
    ifstream inFile;
    string filename = "enroll_assg.txt";
    inFile.open(filename);

    //Count the number of lines in the file and reset the file pointer back to the beginning of the file
    int numLines = 0;
    while (getline(inFile, line))
        numLines++;
    inFile.clear();
    inFile.seekg(0, ios::beg);

    cout << "Number of lines in the file: " << numLines << endl;

    // Initialize a hash table
    DoubleHash<Student<string>> hashTable(numLines);

    // Read the file line by line. The first word is the id, second word is firstName, third word is lastname, fourth word is department, fifth word is gpa
    if (inFile.is_open())
    {
        string intermediate;

        while (getline(inFile, line))
        {
            stringstream ss(line);
            getline(ss, id, ' ');
            getline(ss, firstName, ' ');
            getline(ss, lastName, ' ');
            getline(ss, department, ' ');
            getline(ss, gpa);

            // Print out what is being read in
            //cout << "Reading in: " << id << " " << firstName << " " << lastName << " " << department << " " << gpa << endl;

            // Create a student object and set the values of the student object
            Student<string> tempStudent;

            tempStudent.setId(stoi(id));
            tempStudent.setFirstName(firstName);
            tempStudent.setLastName(lastName);
            tempStudent.setDepartment(department);
            tempStudent.setGPA(gpa);

            // Insert the student object to the heap
            hashTable.insertHash(tempStudent);
        }

        //cout << "Finished reading in the file" << endl;
    }
    else
    {
        cout << "Unable to open enroll_assg.txt" << endl;
        return (1);
    }

    inFile.close();
    
    // Print out the hash table
    hashTable.displayHash();
    

    return 0;
}