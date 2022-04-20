#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

// Note, the root index is 1
template <typename Comparable>
class BinaryHeap
{
public:
    // Constructor of the BinaryHeap class with defaulty 
    // capacity 100
    explicit BinaryHeap(int capacity = 100);
    // Check whether the bianry heap is empty
    bool isEmpty() const;
    // Make the binary heap empty
    void makeEmpty();

    // Find the student with the largest id number in the binary heap.
    // Return the student information, or throw Underflow if empty.
    const Student<string> &findMax() const;    
    // Remove the student with the largest id number.
    // Throws UnderflowException if empty.
    void deleteMax();
    // Remove the student with the largest id and place the student information in stuWithMaxId.
    // Throws Underflow if empty.
    void deleteMax(Student<string> &stuWithMaxId);

    // Insert a new student into the heap, allowing duplicates.
    void insert(Student<string> &stu);

    // Update the current student of binary heap at index position p by a new student 
    // information stored in newValue.
    // Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
    void updateStudent(int p, Student<string> newStudent);

    // Delete the current student from binary heap at position p,
    // and place it in stu.
    // Throws UnderflowException if empty.
    // Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
    void deleteStudent(int p, Student<string> &stu);

    // Will return a sorted vector/array of the built heap in descending order
    // But will not change the original heap
    vector<Student<string>> heapsort();

    // Get the current size of the built binary heap
    int getCurrentSize();
	
    // Print out each element of the binary heap
    void printHeap();

private:
    int currentSize;               // Number of elements in heap
    vector<Student<string>> array; // The heap array

    // Internal method to percolate down in the heap.
    // hole is the index at which the percolate begins.
    void percolateDown(int hole);

    // Establish heap order property from an arbitrary
    // arrangement of items. Runs in linear time.
    void buildHeap();      
};
#endif