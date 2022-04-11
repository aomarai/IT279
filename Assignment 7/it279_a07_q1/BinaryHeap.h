#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>
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

    // Find the largest item in the binary heap.
    // Return the largest item, or throw Underflow if empty.
    const Comparable &findMax() const;    
    // Remove the maximum item.
    // Throws UnderflowException if empty.
    void deleteMax();
    // Remove the maximum item and place it in maxItem.
    // Throws Underflow if empty.
    void deleteMax(Comparable &maxItem);

    // Insert item x, allowing duplicates.
    void insert(const Comparable &x);

    // Update the current value of binary heap at index position p with newValue.
    // Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
    void updateVal(int p, Comparable newValue);

    // Delete the current value at from binary heap at position p,
    // and place it in val.
    // Throws UnderflowException if empty.
    // Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
    void deleteVal(int p, Comparable &val);

    // Will return a sorted vector/array of the built heap in descending order
    // But will not change the original heap
    vector<Comparable> heapsort();
	
    // Print out each element of the binary heap
    void printHeap();

private:
    int currentSize;          // Number of elements in heap
    vector<Comparable> array; // The heap array

    // Internal method to percolate down in the heap.
    // hole is the index at which the percolate begins.
    void percolateDown(int hole);

    // Establish heap order property from an arbitrary
    // arrangement of items. Runs in linear time.
    void buildHeap();      
};
#endif