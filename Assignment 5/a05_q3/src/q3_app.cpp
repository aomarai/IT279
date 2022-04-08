#include "SplayTree.h"
#include "flags.h"
#include "SplayTree.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <map>
using namespace std;

// Testing program
int main()
{
    cout << "\nAssignment 03, Question 03 (Ashkan Omaraie): " << endl;
    cout << "Part A:" << endl;

    SplayTree<int> t;
    string line, v;

    ifstream inputFile("enroll.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            t.insert(stoi(line));
        }
        inputFile.close();
    }

    cout << "The built splay tree:" << endl;
    t.printTree();
    cout << endl;

    cout << "The queried students (sorted by number of courses taken in descending order)" << endl;
    ifstream queryFile("query.txt");
    list<pair<int, string>> queries;
    string queryLine;
    if (queryFile.is_open())
    {
        while (getline(queryFile, queryLine))
        {
            if (t.search(stoi(queryLine)))
            {
                
            }
        }
    }


    cout << "The queried students (sorted by student number in ascending order)" << endl;

    cout << "The updated splay tree:" << endl;


    return 0;
}
