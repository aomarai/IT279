#include "BinaryHeap.h"
#include "dsexceptions.h"
#include "Student.h"

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity) : currentSize(0), array(capacity + 1)
{
}

template <typename Comparable>
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
const Student<string> &BinaryHeap<Comparable>::findMax() const
{
    if (isEmpty())
        throw UnderflowException();
    return array[1];
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax()
{
    if (isEmpty())
        throw UnderflowException();
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}

//Delete the student at array[1] and place it in stuWithMaxId
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Student<string> &stuWithMaxId)
{
    if (isEmpty())
        throw UnderflowException();
    stuWithMaxId = move(array[1]);
    array[1] = move(array[currentSize--]);
    percolateDown(1);   
}

//Inserts the student object into the heap, using the student's ID as the key to compare against. Does not insert into array[0]
template <typename Comparable>
void BinaryHeap<Comparable>::insert(Student<string> &x)
{
    // Expand heap if full
    if (currentSize == (int)array.size() - 1)
    {
        array.resize(array.size() * 2);
    }

    // Percolate down
    int hole = currentSize++;
    Student<string> copy = x;

    array[0] = move(copy);
    //Insert the student object into the heap array
    for (; x.getId() < array[hole / 2].getId(); hole /= 2)
    {
        array[hole] = move(array[hole / 2]);
    }
     array[hole] = move(array[0]);   
}

template <typename Comparable>
void BinaryHeap<Comparable>::updateStudent(int p, Student<string> newStudent)
{
    if (p < 1 || p > currentSize)
        throw ArrayIndexOutOfBoundsException();
    array[p] = move(newStudent);
    percolateDown(p);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteStudent(int p, Student<string> &stuWithMaxId)
{
    if (p < 1 || p > currentSize)
        throw ArrayIndexOutOfBoundsException();
    stuWithMaxId = move(array[p]);
    array[p] = move(array[currentSize--]);
    percolateDown(p);
}

template <typename Comparable>
vector<Student<string>> BinaryHeap<Comparable>::heapsort()
{
    vector<Student<string>> sortedArray;
    
    //Copy contents of heap array into sortedArray
    for (int i = 1; i <= currentSize; i++)
    {
        sortedArray.push_back(array[i]);
    }

    return sortedArray;
}

template <typename Comparable>
int BinaryHeap<Comparable>::getCurrentSize()
{
    return currentSize;
}

template <typename Comparable>
void BinaryHeap<Comparable>::printHeap()
{
    for (int i = 1; i < currentSize; i++)
    {
        // Print out the studen'ts index and all the fields in student
        cout << i+1 << ": " << array[i].getId() << " " << array[i].getFirstName() << " " << array[i].getLastName() << " " << array[i].getDepartment() << " " << array[i].getGPA() << endl;
    }
    cout << endl;
}

// Percolate down using the student object's id as the key
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    Student<string> tmp = array[hole];

    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1].getId() < array[child].getId())
            child++;
        if (array[child].getId() < tmp.getId())
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
        percolateDown(i);
}