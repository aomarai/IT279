#include "DisjSet.h"

template <typename Comparable>
DisjSet<Comparable>::DisjSet(Comparable n)
{
    rank = new Comparable[n];
    parent = new Comparable[n];
    this->n = n;
    makeSet(n);
}

template <typename Comparable>
void DisjSet<Comparable>::makeSet(Comparable i)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

// Finds set of given item x using path compression
template <typename Comparable>
Comparable DisjSet<Comparable>::find(Comparable x)
{
    if (x != parent[x])
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Do union of two sets represented by x and y using union by rank
template <typename Comparable>
bool DisjSet<Comparable>::Union(Comparable x, Comparable y)
{
    Comparable xRoot = find(x);
    Comparable yRoot = find(y);
    if (xRoot == yRoot)
    {
        return false;
    }
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