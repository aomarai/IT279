#include "BinaryHeap.h"
#include "dsexceptions.h"

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity) : array(capacity + 1), currentSize(0)
{
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
void BinaryHeap<Comparable>::deleteMax(Comparable &maxItem)
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
const Comparable BinaryHeap<Comparable>::*findMax()
{
    if (isEmpty())
    {
        throw UnderflowException();
    }
    return array[1];
}

template <typename Comparable>
void BinaryHeap<Comparable>::updateVal(int p, Comparable newValue)
{
    if (p < 1 || p > currentSize)
    {
        throw ArrayIndexOutOfBoundsException();
    }
    array[p] = newValue;
    percolateDown(p);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteVal(int p, Comparable &val)
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
vector<Comparable> BinaryHeap<Comparable>::heapsort()
{
    vector<Comparable> sorted;

    int currentSize = array[0];
    
    //Copy old vector to sorted vector
    for (int i = 1; i <= currentSize; i++)
    {
        sorted.push_back(array[i]);
    }

    //Sort vector with heapsort
    for (int i = currentSize; i > 0; i--)
    {
        sorted[i] = move(array[1]);
        array[1] = move(array[i]);
        percolateDown(1);
    }
    
    return sorted; 
}