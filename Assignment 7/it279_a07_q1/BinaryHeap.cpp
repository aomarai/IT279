#include "BinaryHeap.h"

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
{
    array.reserve(capacity);
    currentSize = 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
    //Expand heap if full
    if (currentSize = array.size() - 1)
    {
        array.resize(array.size() * 2);
    }

    //Percolate up
    int hole = currentSize++;
    Comparable copy = x;

    array[0] = move(copy);
    for (; x < array[hole / 2]; hole /= 2)
    {
        array[hole] = move(array[hole / 2]);
    }
    array[hole] = move(array[0]);
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
void deleteMax()
{
    if (isEmpty())
    {
        throw UnderflowException();
    }
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}

template <typename Comparable>
void deleteMax(Comparable &maxItem)
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
const Comparable &findMax()
{
    if (isEmpty())
    {
        throw UnderflowException();
    }
    return array[1];
}

template <typename Comparable>
void updateVal(int p, Comparable newValue)
{
    if (p < 1 || p > currentSize)
    {
        throw ArrayIndexOutOfBoundsException();
    }
    array[p] = newValue;
    percolateDown(p);
}

template <typename Comparable>
void deleteVal(int p, Comparable &val)
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
void percolateDown(int hole)
{
    int child;
    Comparable tmp = move(array[hole]);

    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] > array[child])
        {
            child++;
        }
        if (array[child] > tmp)
        {
            array[hole] = move(array[child]);
        }
        else
        {
            break;
        }
    }
    array[hole] = move(tmp);
}

template <typename Comparable>
void buildHeap()
{
    for (int i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

template <typename Comparable>
void printHeap()
{
    for (int i = 1; i <= currentSize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

//TODO: Finish this
template <typename Comparable>
vector<Comparable> heapsort()
{
    vector<Comparable> sorted;
    
    //Copy old vector to sorted vector
    for (int i = 1; i <= currentSize; i++)
    {
        sorted.push_back(array[i]);
    }

    //Sort vector with heapsort
    
    return sorted; 
}