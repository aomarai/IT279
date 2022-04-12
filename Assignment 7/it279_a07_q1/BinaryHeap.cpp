#include "BinaryHeap.h"

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

