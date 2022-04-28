#include "DoubleHash.h"

template <typename HashedObj>
DoubleHash<HashedObj>::DoubleHash(int size) : tableSize{size}
{
    hashTable = new Student<string>[tableSize];
    curr_size = 0;

    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i].setId(-1);
    }
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::isFull()
{
    return curr_size == tableSize;
}

template <typename HashedObj>
int DoubleHash<HashedObj>::hash1(HashedObj key)
{
    return key.getId() % tableSize;
}

template <typename HashedObj>
int DoubleHash<HashedObj>::hash2(HashedObj key)
{
    int PRIME = prePrime (tableSize);

    return PRIME - (key.getId() % PRIME);
}

template <typename HashedObj>
void DoubleHash<HashedObj>::insertHash(Student<string> &val)
{
    // If the hash table is full, return
    if (isFull())
    {
        //cout << "Hash table is full" << endl;
        return;
    }

    // Calculate the first hash
    int firstHash = hash1(val);

    //If there is a collision
    if (hashTable[firstHash].getId() != -1)
    {
        //cout << "Collision" << endl;
        int secondHash = hash2(val);
        int i = 1;
        while (1)
        {
            //Get new index
            int newIndex = (firstHash + i * secondHash) % tableSize;

            //If the index is empty, set the student's bucket id and insert the student
            if (hashTable[newIndex].getId() == -1)
            {
                val.setBucketId(newIndex);
                hashTable[newIndex] = val;
                curr_size++;
                //cout << "Inserted after " << i << " collisions" << endl;
                break;
            }
            i++;
        }
    }
    else
    // No collision so just insert the student
    {
        //cout << "No collision" << endl;
        val.setBucketId(firstHash);
        hashTable[firstHash] = val;
        curr_size++;
    }
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::search(HashedObj key, HashedObj &bucketId, Student<string> &val)
{
    int firstHash = hash1(key);
    int secondHash = hash2(key);
    int i = 0;

    while (hashTable[(firstHash + i * secondHash) % tableSize].getId() != key.getId())
    {
        if (hashTable[(firstHash + i * secondHash) % tableSize].getId() == -1)
        {
            return false;
        }
        i++;
    }
    // If the student is found, return true
    bucketId = (firstHash + i * secondHash) % tableSize;
    val = hashTable[bucketId];
    return true;
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::search(HashedObj bucketId, Student<string> &val)
{
    if (hashTable[bucketId].getId() == -1)
    {
        return false;
    }
    else
    {
        val = hashTable[bucketId];
        return true;
    }
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::update(Student<string> &val)
{
    //Search for the student
    HashedObj bucketId;
    Student<string> temp;
    if (search(val.getId(), bucketId, temp))
    {
        // If the student is found, update the student
        hashTable[bucketId] = val;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename HashedObj>
void DoubleHash<HashedObj>::displayHash()
{
    cout << "Bucket Index\t\t" << "Student Information" << endl;
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].getId() != -1)
        {
            //Print out all of the students info with spaces between them
         cout << i << " -------> " << hashTable[i].getId() << " ( " << hashTable[i].getFirstName() << " " << hashTable[i].getLastName() << " " << hashTable[i].getDepartment() << " " << hashTable[i].getGPA() << " ) " << endl;
        }
    }
}

template <typename HashedObj>
bool DoubleHash<HashedObj>::isSameDept(Student<string> std1, Student<string> std2)
{
    return std1.getDepartment() == std2.getDepartment();
}

template <typename HashedObj>
Student<string> DoubleHash<HashedObj>::getStudent(HashedObj bucketId)
{
    return hashTable[bucketId];
}