#ifndef DOUBLEHASH_H_
#define DOUBLEHASH_H_

// CPP program to implement double hashing
#include <iostream>
#include <math.h>
#include "Student.h"
using namespace std;

template <typename HashedObj>
class DoubleHash
{
public:
    DoubleHash(int size);

    // function to check if hash table is full
    bool isFull();

    // function to calculate first hash
    int hash1(HashedObj key);

    // function to calculate second hash
    int hash2(HashedObj key);

    // function to insert key into hash table
    void insertHash(Student<string> &val);

    // function to search the student information who id is key
    // If search is successful, return ture, otherwise, return false
    // bucketId: bucket id in hash table
    // val: student object
    bool search(HashedObj key, HashedObj &bucketId, Student<string> &val);

    // Input bucket index to find student stored in the index, which is stored in val,
    // return ture. Otherwise, no student stored in the index, return false
    bool search(HashedObj bucketId, Student<string> &val);

    // function to update the student information who id is key
    // If update is successful, return ture, otherwise, return false
    bool update(Student<string> &val);

    // function to display the hash table
    void displayHash();

    // If the two students are in the same department, return true
    // Otherwise, return false
    bool isSameDept(Student<string> std1, Student<string> std2);

    // Get the student stored at bucketId in the hash table
    Student<string> getStudent(HashedObj bucketId);

    /**
     * Internal method to test if a positive number is prime.
     * Not an efficient algorithm.
     */
    bool isPrime(int n)
    {
        if (n == 2 || n == 3)
            return true;

        if (n == 1 || n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;

        return true;
    }

    /**
     * Internal method to return a prime number at least as large as n.
     * Assumes n > 0.
     */
    int nextPrime(int n)
    {
        if (n % 2 == 0)
            ++n;

        for (; !isPrime(n); n += 2)
            ;

        return n;
    }

    // Function to return nearest prime number
    int prePrime(int n)
    {

        // All prime numbers are odd except two
        if (n & 1)
            n -= 2;
        else
            n--;

        int i, j;
        for (i = n; i >= 2; i -= 2)
        {
            if (i % 2 == 0)
                continue;
            for (j = 3; j <= sqrt(i); j += 2)
            {
                if (i % j == 0)
                    break;
            }
            if (j > sqrt(i))
                return i;
        }

        // It will only be executed when n is 3
        return 2;
    }

private:
    int tableSize;

    // Pointer to an array containing buckets
    HashedObj *hashTable;
    Student<string> *student;
    int curr_size;
};
#endif