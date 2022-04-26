#include "DisjSet.h"

template <typename Comparable>
DisjSet<Comparable>::DisjSet(Comparable n)
{
    rank = new Comparable[n];
    parent = new Comparable[n];
    this->n = n;
    for (Comparable i = 0; i < n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

template <typename Comparable>
void DisjSet<Comparable>::makeSet(Comparable i)
{
    parent[i] = i;
}

// Finds set of given item x using path compression
template <typename Comparable>
Comparable DisjSet<Comparable>::find(Comparable x)
{
}

// Do union of two sets represented by x and y using union by rank
template <typename Comparable>
bool DisjSet<Comparable>::Union(Comparable x, Comparable y)
{
    Comparable xRoot = find(x);
    Comparable yRoot = find(y);
    if (xRoot == yRoot)
        return false;
    if (rank[xRoot] < rank[yRoot])
    {
        parent[xRoot] = yRoot;
    }
    else if (rank[xRoot] > rank[yRoot])
    {
        parent[yRoot] = xRoot;
    }
    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
    return true;
}