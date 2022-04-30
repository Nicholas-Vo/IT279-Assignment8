#include "DisjSet.h"

template<typename Comparable>
DisjSet<Comparable>::DisjSet(Comparable comp) {
    rank = new int[n];
    parent = new int[n];
    this->n = comp;
}

template<typename Comparable>
void DisjSet<Comparable>::makeSet(Comparable comp) {
    for (int i = 0; i < n; i++) {
        parent[i] = comp;
    }
}

template<typename Comparable>
Comparable DisjSet<Comparable>::find(Comparable x) {
    Comparable val = parent[x];

    if (parent[x] == val) {
        return parent[x];
    }

    return find(parent[x]);
}

template<typename Comparable>
bool DisjSet<Comparable>::Union(Comparable x, Comparable y) {
    int irep = find(x);
    int jrep = find(y);

    if (irep == jrep) { // same set
        return true;
    }

    int irank = rank[irep];
    int jrank = rank[jrep];

    if (irank < jrank) {
        parent[irep] = jrep;
    } else if (jrank < irank) {
        parent[jrep] = irep;
    } else {
        parent[irep] = jrep;
        rank[jrep]++;
    }

    return true;
}



