#include "SeparateChain.h"
using namespace std;

template <typename HashedObj>
HashTable<HashedObj>::HashTable(int size) : currentSize{0}
{
    theLists.resize(size);
}

/////////////////////////////////////////////////////////////////////
/**
 * return (input key) % (bucket size)
 */
template <typename HashedObj>
size_t HashTable<HashedObj>::myhash(const HashedObj &x) const
{
    return x % theLists.size();
}

/**
 * A hash routine for ints. Return the key
 */
template <typename HashedObj>
size_t HashTable<HashedObj>::hash(const HashedObj &key) const
{
    return key % theLists.size();
}

/**
 * Insert a node whose id == x (all student information stored
 * in s): if the node is found, do nothing and return false
 * Otherwise, insert the node to the BST tree (including student information
 * stored in s), and return true
 */
template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x, Student<string> &s)
{
    size_t currentPos = hash(x);
    if (theLists[currentPos].find(x))
    {
        return false;
    }
    else
    {
        theLists[currentPos].insert(x, s);
        currentSize++;
        return true;
    }
}

/**
 * Find whether id == x is in the database, if found, update the student information
 * and return true. Otherwise, return false
 */
template <typename HashedObj>
bool HashTable<HashedObj>::update(const HashedObj &x, Student<string> &s)
{
    size_t currentPos = hash(x);
    if (theLists[currentPos].find(x))
    {
        theLists[currentPos].update(x, s);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Find whether id == x is in the database, if found, remove the node and return true
 * Otherwise, return false
 */
template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x)
{
    size_t currentPos = hash(x);
    if (theLists[currentPos].find(x))
    {
        theLists[currentPos].remove(x);
        currentSize--;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * If x (student id) is found, print out student information whose id == x
 * and return true.
 * Otherwise, print out "x was not found" and return false
 * You should use bool printNodeInfo(const Comparable &x)
 * in BinarySearchTree class
 */
template <typename HashedObj>
bool HashTable<HashedObj>::printNodeInfo(const HashedObj &x)
{
    size_t currentPos = hash(x);
    if (theLists[currentPos].find(x))
    {
        theLists[currentPos].printNodeInfo(x);
        return true;
    }
    else
    {
        cout << x << " was not found" << endl;
        return false;
    }
}

/**
 * Display the content of the hash table
 */
template <typename HashedObj>
void HashTable<HashedObj>::displayHash()
{
    for (int i = 0; i < theLists.size(); i++)
    {
        cout << i << " -> ";
        theLists[i].printTree();
    }
}

/**
 * Make the hash table empty
 */
template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    for (int i = 0; i < theLists.size(); i++)
    {
        theLists[i].makeEmpty();
    }
    currentSize = 0;
}