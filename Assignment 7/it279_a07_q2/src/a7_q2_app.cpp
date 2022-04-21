#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <array>
#include <cassert>
#include <random>
#include <sstream> // std::stringstream
#include <fstream>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "flags.h"
#include "Student.h"

#include "Student.cpp"

using namespace std;

// Test program
int main()
{
    string id, firstName, lastName, department, gpa;
    string line;

    cout << "\nAssignment 07, Question 02 (Ashkan Omaraie): " << endl;
	// Add your code here:

//Read the text file enroll_test.txt in the data folder
    ifstream file("enroll_assg.txt");

    //Create binary heap for students
    BinaryHeap<Student<string>> ht;

    //Read the file line by line. The first word is the id, second word is firstName, third word is lastname, fourth word is department, fifth word is gpa
    if(file.is_open())
    {
        string intermediate;

        while (getline(file, line))
        {
        stringstream ss(line);
        getline(ss, id, ' ');
        getline(ss, firstName, ' ');
        getline(ss, lastName, ' ');
        getline(ss, department, ' ');
        getline(ss, gpa);
        

        //cout << "id: " << id << " firstName: " << firstName << " lastName: " << lastName << " department: " << department << " gpa: " << gpa << endl;

        //Create a student object and set the values of the student object
        Student<string> tempStudent;

        tempStudent.setId(stoi(id));
        tempStudent.setFirstName(firstName);
        tempStudent.setLastName(lastName);
        tempStudent.setDepartment(department);
        tempStudent.setGPA(gpa);

        //Insert the student object to the heap
        ht.insert(tempStudent);
        }
    }
    else
    {
        cout << "Unable to open enroll_assg.txt" << endl;
        return(1);
    }

    file.close();

    //Print out the heap
    printf("The initial heap: \n");
    ht.printHeap();

    //Sort the heap using heapsort
    vector<Student<string>> sortedArray = ht.heapsort();
    //Print out the sorted array
    printf("The sorted heap in descending order:\n");
    for (int i = 0; i < (int) sortedArray.size(); i++)
    {
        cout << i << ": " << sortedArray[i].getId() << " " << sortedArray[i].getFirstName() << " " << sortedArray[i].getLastName() << " " << sortedArray[i].getDepartment() << " " << sortedArray[i].getGPA() << endl;
    }
    cout << endl;

    //Delete student with largest id
    ht.deleteMax();
    printf("Heap after deleting student with largest id:\n");
    ht.printHeap();

    //Update student at index 10 with new values
    Student<string> tempStudent;
    tempStudent.setId(9611215);
    tempStudent.setFirstName("GalaUp");
    tempStudent.setLastName("BakerUp");
    tempStudent.setDepartment("ECE");
    tempStudent.setGPA("4.2");
    ht.updateStudent(10, tempStudent);
    printf("Heap after updating student at index 10:\n");
    ht.printHeap();

    //Delete the student at index 12 and place it in stu
    ht.deleteStudent(12, tempStudent);
    printf("Heap after deleting student at index 12:\n");
    ht.printHeap();

    return 0;
}