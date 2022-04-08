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
    string line;
    cout << "Assignment 06 (Ashkan Omaraie):" << endl;
    
    //Read the text file enroll_test.txt in the data folder
    ifstream file("enroll_assg.txt");

    //Create hash table of student objects with 7 buckets
    HashTable<int> ht(7);

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

        tempStudent.setFirstName(firstName);
        tempStudent.setLastName(lastName);
        tempStudent.setDepartment(department);
        tempStudent.setGPA(gpa);

        //Insert the student object to the hash table
        ht.insert(stoi(id), tempStudent);
        }
    }
    else
    {
        cout << "Unable to open enroll_assg.txt" << endl;
        return(1);
    }

    file.close();
    ht.displayHash();

    /*
    Question 2
    */

    cout << "\nQuestion 2: \n" << endl;

    //Read the file search_test1.txt
    ifstream file2("search_assg1.txt");

    cout << "Students whose records were searched: " << endl;

    //Read the file line by line
    if(file2.is_open())
    {
        string intermediate;

        while (getline(file2, line))
        {
            stringstream ss2(line);
            getline(ss2, id, ' ');
            getline(ss2, firstName, ' ');
            getline(ss2, lastName, ' ');
            getline(ss2, department, ' ');
            getline(ss2, gpa);
            
            //Create a student object and set the values of the student object
            Student<string> tempStudent;

            tempStudent.setFirstName(firstName);
            tempStudent.setLastName(lastName);
            tempStudent.setDepartment(department);
            tempStudent.setGPA(gpa);

            //Search the student object in the hash table via id
            if (!ht.printNodeInfo(stoi(id)))
            {
                cout << id << " was not found" << endl;
            }
        }
    }
    else
    {
        cout << "Unable to open search_assg1.txt" << endl;
        return(2);
    }

    file2.close();

    /*
    Question 3
    */
    cout << "\nQuestion 3: \n" << endl;

    //Read the file search_test1.txt
    ifstream file3("search_assg2.txt");

    cout << "Students whose records were searched: " << endl;

    //Read the file line by line
    if(file3.is_open())
    {
        string intermediate;

        while (getline(file3, line))
        {
            stringstream ss3(line);
            getline(ss3, id, ' ');
            getline(ss3, firstName, ' ');
            getline(ss3, lastName, ' ');
            getline(ss3, department, ' ');
            getline(ss3, gpa);
            
            //Create a student object and set the values of the student object
            Student<string> tempStudent;

            tempStudent.setFirstName(firstName);
            tempStudent.setLastName(lastName);
            tempStudent.setDepartment(department);
            tempStudent.setGPA(gpa);

            //Search the student object in the hash table via id
            if (!ht.printNodeInfo(stoi(id)))
            {
                cout << id << " was not found" << endl;
            }
        }
    }
    else
    {
        cout << "Unable to open search_test2.txt" << endl;
        return(3);
    }

    file3.close();

    /*
    Question 4
    */

   cout << "\nQuestion 4: \n" << endl;

    //Read the file update_test.txt
    ifstream file4("update_assg.txt");

    cout << "Students whose records have been updated: " << endl;

    //Read the file line by line
    if(file4.is_open())
    {
        string intermediate;

        while (getline(file4, line))
        {
            stringstream ss4(line);
            getline(ss4, id, ' ');
            getline(ss4, firstName, ' ');
            getline(ss4, lastName, ' ');
            getline(ss4, department, ' ');
            getline(ss4, gpa);
            
            //Create a student object and set the values of the student object
            Student<string> tempStudent;

            tempStudent.setFirstName(firstName);
            tempStudent.setLastName(lastName);
            tempStudent.setDepartment(department);
            tempStudent.setGPA(gpa);

            //Search the student object in the hash table via id and update it if found
            if (!ht.update(stoi(id), tempStudent))
            {
                cout << id << " was not found" << endl;
            }
        }
    }
    else
    {
        cout << "Unable to open update_assg.txt" << endl;
        return(4);
    }

    file4.close();
}