#include "DoubleHash.h"

template <typename HashedObj>
DoubleHash<HashedObj>::DoubleHash(int size)
{
    // Initialize hashtable
    tableSize = size;
    hashTable = new Student<string>[tableSize];
    curr_size = 0;
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::isFull()
{
    return curr_size == tableSize;
}

template <typename HashedObj>
int DoubleHash<HashedObj>::hash1(HashedObj key)
{
    // Calculate the first hash
    return key % tableSize;
}

template <typename HashedObj>
int DoubleHash<HashedObj>::hash2(HashedObj key)
{
    int PRIME = prePrime(tableSize / 2);

    // Calculate the second hash
    return PRIME - (key % PRIME);
}

//Store the student object in the hash table using the ID as the key
template <typename HashedObj>
void DoubleHash<HashedObj>::insertHash(Student<string> &val)
{
    int key = val.getId();

    // if hash table is full
    if (isFull())
        return;

    // get index from first hash
    int index = hash1(key);

    // if collision occurs
    if (hashTable[index] != -1)
    {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1)
        {
            // get newIndex
            int newIndex = (index + i * index2) % tableSize;

            // if no collision occurs, store the student object in the hash table
            if (hashTable[newIndex] == -1)
            {
                hashTable[newIndex] = val;
                break;
            }
            i++;
        }
    }
    else // if no collision occurs
        hashTable[index] = val;
    curr_size++;
}

// Searches by taking the key and the bucket id
template <typename HashedObj>
bool DoubleHash<HashedObj>::search(HashedObj key, HashedObj &bucketId, Student<string> &val)
{
    // get index from first hash
    int index = hash1(key);

    // if no collision occurs
    if (hashTable[index] == key)
    {
        bucketId = index;
        val = hashTable[index];
        return true;
    }
    else
    {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1)
        {
            // get newIndex
            int newIndex = (index + i * index2) % tableSize;

            // if no collision occurs, store the key
            if (hashTable[newIndex] == key)
            {
                bucketId = newIndex;
                val = hashTable[newIndex];
                return true;
            }
            i++;
        }
    }
    return false;
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::search(HashedObj bucketId, Student<string> &val)
{
    // if no collision occurs
    if (hashTable[bucketId] != -1)
    {
        val = hashTable[bucketId];
        return true;
    }
    return false;
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::update(Student<string> &val)
{
    int key = val.getId();

    // get index from first hash
    int index = hash1(key);

    // if no collision occurs
    if (hashTable[index] == key)
    {
        hashTable[index] = val;
        return true;
    }
    else
    {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1)
        {
            // get newIndex
            int newIndex = (index + i * index2) % tableSize;

            // if no collision occurs, store the key
            if (hashTable[newIndex] == key)
            {
                hashTable[newIndex] = val;
                return true;
            }
            i++;
        }
    }
    return false;
}

template <typename HashedObj>
void DoubleHash<HashedObj>::displayHash()
{
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i] != -1)
            cout << i << ": " << hashTable[i] << endl;
    }
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::isSameDept(Student<string> stu1, Student<string> stu2)
{
    return stu1.getDept() == stu2.getDept();
}


template <typename HashedObj>
Student<string> DoubleHash<HashedObj>::getStudent(HashedObj bucketID)
{
    return hashTable[bucketID];
}
