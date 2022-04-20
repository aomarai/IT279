#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <array>
#include <cassert>
#include <random>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "flags.h"
using namespace std;

// Test program
int main()
{
    cout << "\nAssignment 07, Question 01 (Ashkan Omaraie): " << endl;
    BinaryHeap<int> h;

    if (TEST0)
    {
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "Test0:" << endl;
        std::vector<int> temp{68, 40, 60, 86, 45, 26, 99, 54, 3};
        for (size_t i = 0; i < temp.size(); i++)
        {
            h.insert(temp.at(i));
        }

        cout << "Unsorted vector: ";
        for (auto num : temp)
            cout << num << " ";

        cout << "\nThe built binary heap: ";
        h.printHeap();

        vector<int> sortResult = h.heapsort();
        cout << "Sorted array in descending order: ";
        for (size_t i = 0; i < sortResult.size(); i++)
        {
            cout << sortResult.at(i) << " ";
        }
        cout << "\nThe built binary heap: ";
        h.printHeap();

        int maxItem;
        h.deleteMax(maxItem);
        cout << "The maximum value of the binary heap: " << maxItem << " was deleted" << endl;
        cout << "The updated binary heap: ";
        h.printHeap();

        int val, index = 3;
        h.deleteVal(index, val);
        cout << "\nThe deleted value from heap is: " << val;
        cout << "\nThe updated binary heap after " << val << " is deleted: ";
        h.printHeap();

        val = 100, index = 4;
        h.updateVal(index, val);
        cout << "The updated binary heap after replacing element with index 4 with value 100:" << endl;
        h.printHeap();

        sortResult = h.heapsort();
        cout << "Sorted array in descending order: ";
        for (auto num : sortResult)
            cout << num << " ";

        cout << "\nThe built binary heap: ";
        h.printHeap();

        val = 120, index = 9;
        h.updateVal(index, val);
        cout << "\nThe updated binary heap after replacing element with index 9 with value 120:" << endl;
        h.printHeap();
        cout << "\n-----------------------------------------------------------------" << endl;
    }
    if (TEST1)
    {
        std::vector<int> temp;
        int tmpVal;
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "Test1:" << endl;

        if (h.isEmpty())
        {
            cout << "The binary heap is empty" << endl;
        }
        else
            cout << "The binary heap is not empty" << endl;

        // randomly generated data
        std::random_device random_device;
        std::mt19937 mt(random_device());
        std::uniform_int_distribution<int> distribution(0, 100);
        std::array<int, 1> vector_sizes = {{12}};
        for (auto size : vector_sizes)
        {
            for (int i = 0; i < size; ++i)
            {
                tmpVal = distribution(mt);
                temp.push_back(tmpVal);
                h.insert(tmpVal);
            }
        }
        cout << "Unsorted vector: ";
        for (auto num : temp)
            cout << num << " ";

        cout << "\nThe built binary heap: ";
        h.printHeap();

        vector<int> sortResult = h.heapsort();
        cout << "Sorted array in descending order: ";
        for (size_t i = 0; i < sortResult.size(); i++)
        {
            cout << sortResult.at(i) << " ";
        }
        cout << "\nThe built binary heap: ";
        h.printHeap();

        int maxItem;
        h.deleteMax(maxItem);
        cout << "The maximum value of the binary heap: " << maxItem << " was deleted" << endl;
        cout << "The updated binary heap: ";
        h.printHeap();

        int val, index = 5;
        h.deleteVal(index, val);
        cout << "\nThe deleted value from heap is: " << val;
        cout << "\nThe updated binary heap after " << val << " is deleted: ";
        h.printHeap();

        val = 50, index = 8;
        h.updateVal(index, val);
        cout << "The updated binary heap after replacing element with index 8 with value 50:" << endl;
        h.printHeap();

        sortResult = h.heapsort();
        cout << "Sorted array in descending order: ";
        for (auto num : sortResult)
            cout << num << " ";

        cout << "\nThe built binary heap: ";
        h.printHeap();

        index = 11;
        h.deleteVal(index, val);
        cout << "\nThe deleted value from heap is: " << val;
        cout << "\nThe updated binary heap after " << val << " is deleted: ";
        h.printHeap();
        cout << "\n-----------------------------------------------------------------" << endl;
    }
    return 0;
}