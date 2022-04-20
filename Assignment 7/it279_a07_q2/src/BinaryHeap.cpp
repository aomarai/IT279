#include "BinaryHeap.h"
#include "dsexceptions.h"
#include "Student.h"

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity) : currentSize(0), array(capacity + 1)
{
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(Student<string> &stu)
{
    // Expand heap if full
    if (currentSize == (int)array.size() - 1)
    {
        array.resize(array.size() * 2);
    }

    // Percolate up
    int hole = currentSize++;
    Comparable copy = stu;

    array[0] = move(copy);
    for (; stu < array[hole / 2]; hole /= 2)
    {
        array[hole] = move(array[hole / 2]);
    }
    array[hole] = move(array[0]);
}

template <class Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
    currentSize = 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax()
{
    if (isEmpty())
    {
        throw UnderflowException();
    }
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Student<string> &maxItem)
{
    if (isEmpty())
    {
        throw UnderflowException();
    }
    maxItem = move(array[1]);
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}

template <typename Comparable>
const Student<string> &BinaryHeap<Comparable>::findMax() const
{
    if (isEmpty())
    {
        throw UnderflowException();
    }
    return array[1];
}

template <typename Comparable>
void BinaryHeap<Comparable>::updateStudent(int p, Student<string> newValue)
{
    if (p < 1 || p > currentSize)
    {
        throw ArrayIndexOutOfBoundsException();
    }
    array[p] = move(newValue);
    percolateDown(p);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteStudent(int p, Student<string> &val)
{
    if (p < 1 || p > currentSize)
    {
        throw ArrayIndexOutOfBoundsException();
    }
    val = move(array[p]);
    array[p] = move(array[currentSize--]);
    percolateDown(p);
}

template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    Comparable tmp = array[hole];

    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
            child++;
        if (array[child] < tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}

template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for (int i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

template <typename Comparable>
void BinaryHeap<Comparable>::printHeap()
{
    for (int i = 1; i <= currentSize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename Comparable>
vector<Student<string>> BinaryHeap<Comparable>::heapsort()
{
    vector<Student<string>> sortedArray;

    // Copy contents of heap into sortedArray
    for (int i = 1; i <= currentSize; i++)
    {
        sortedArray.push_back(array[i]);
    }

    // Copy the buildheap function's functionality for use on sortedArray
    for (int i = currentSize / 2; i > 0; i--)
    {
        // Copy functionality of percolateDown but for sortedArray instead of array
        int child;
        Comparable tmp = sortedArray[i];

        for (; i * 2 <= currentSize; i = child)
        {
            child = i * 2;
            if (child != currentSize && sortedArray[child + 1] < sortedArray[child])
                child++;
            if (sortedArray[child] < tmp)
                sortedArray[i] = sortedArray[child];
            else
                break;
        }
        sortedArray[i] = tmp;
    }

    //DeleteMax for sortedArray
    for (int j = currentSize; j > 0; j--)
    {
        swap(sortedArray[0], sortedArray[j]);
        // Copy functionality of percolateDown but for sortedArray instead of array
        int child;
        Comparable tmp = sortedArray[j];

        for (; j * 2 <= currentSize; j = child)
        {
            child = j * 2;
            if (child != currentSize && sortedArray[child + 1] < sortedArray[child])
                child++;
            if (sortedArray[child] < tmp)
                sortedArray[j] = sortedArray[child];
            else
                break;
        }
        sortedArray[j] = tmp;
    }

    return sortedArray;
}