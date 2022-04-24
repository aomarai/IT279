#ifndef PRIME_H_
#define PRIME_H_

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> // std::stringstream
#include <math.h>
using namespace std;
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
    for (i = n; i >= 2; i -= 2) {
        if (i % 2 == 0)
            continue;
        for (j = 3; j <= sqrt(i); j += 2) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }
 
    // It will only be executed when n is 3
    return 2;
}

int numOfLinesInFile(string file)
{
  int number_of_lines = 0;
    string line;
    ifstream myfile(file);

    while (getline(myfile, line))
        ++number_of_lines;
    // cout << "Number of lines in text file: " << number_of_lines << endl;
    myfile.close();

    return number_of_lines;
}
#endif