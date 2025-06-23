/**
 * @author      Vaibhav Jindal
 *              B.Tech CSE Core, VIT Bhopal
 * 
 * @details     Modular, templated C++ library for 
 *              educational, research, and production use.
 * 
 * 📦 Namespace: data_structures
 * 📧 Contact  : jindalvaibhav63@gmail.com
 */

#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

namespace data_structures {

/**
 * @brief Disjoint Set (Union-Find) with path compression and union by rank/size.
 */
class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> size;
    int n;

public:
    /**
     * @brief Constructor to initialize n disjoint sets.
     * @param n Number of elements (0 to n-1)
     */
    DisjointSet(int n);

    /**
     * @brief Find the representative (leader) of a set using path compression.
     * @param u Element
     * @return Representative of the set
     */
    int find(int u);

    /**
     * @brief Unions the sets containing u and v using union by rank.
     * @return True if union happened, false if already in same set
     */
    bool unionByRank(int u, int v);

    /**
     * @brief Unions the sets containing u and v using union by size.
     * @return True if union happened, false if already in same set
     */
    bool unionBySize(int u, int v);

    /**
     * @brief Get size of the set containing u.
     */
    int getSetSize(int u);

    /**
     * @brief Check if two elements belong to the same set.
     */
    bool isConnected(int u, int v);

    /**
     * @brief Clear and reset the disjoint set to initial state.
     */
    void reset();
};

// -------- Implementation --------

DisjointSet::DisjointSet(int n) : n(n) {
    parent.resize(n);
    rank.assign(n, 0);
    size.assign(n, 1);
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}

int DisjointSet::find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]); // Path compression
    return parent[u];
}

bool DisjointSet::unionByRank(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return false;

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }

    return true;
}

bool DisjointSet::unionBySize(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return false;

    if (size[pu] < size[pv]) {
        std::swap(pu, pv);
    }

    parent[pv] = pu;
    size[pu] += size[pv];
    return true;
}

int DisjointSet::getSetSize(int u) {
    return size[find(u)];
}

bool DisjointSet::isConnected(int u, int v) {
    return find(u) == find(v);
}

void DisjointSet::reset() {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
}

} // namespace data_structures

#endif // DISJOINTSET_HPP
