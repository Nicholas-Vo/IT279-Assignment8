// C++ implementation of disjoint set
#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

#include <iostream>
#include <string>
#include <vector>

template<typename Comparable>
class DisjSet {
    Comparable *rank, *parent, n;

public:
    // Constructor to create and initialize sets of n items
    explicit DisjSet(Comparable n);

    // Creates n single item sets
    void makeSet(Comparable i);

    // Finds set of given item x
    Comparable find(Comparable x);

    // Do union of two sets represented by x and y.
    bool Union(Comparable x, Comparable y);
};

#endif