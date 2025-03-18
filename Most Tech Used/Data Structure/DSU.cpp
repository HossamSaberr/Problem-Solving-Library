struct DSU {
    vector<int> parent, rank, compSize;
    int components; // Number of disjoint sets

    // Constructor initializes DSU for 'n' elements.
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        compSize.assign(n, 1);
        components = n;
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find function with path compression.
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    // Union by size: merge the sets containing a and b.
    // Returns true if a union was performed, false if already in the same set.

    bool unionSets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;

        // Ensure that a represents the larger set.
        if (compSize[a] < compSize[b])
            swap(a, b);

        parent[b] = a;
        compSize[a] += compSize[b];
        components--;
        return true;
    }

    // Union function with union by rank.
    // Returns true if union was performed; false if a and b were already in the same set.
    bool unionSetsByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false; // Already in the same set

        // Union by rank
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        compSize[a] += compSize[b]; // Update size for the new root
        if (rank[a] == rank[b])
            rank[a]++;

        components--; // Reduce number of disjoint sets
        return true;
    }

    // Check if two elements are in the same set.
    bool sameSet(int a, int b) {
        return find(a) == find(b);
    }

    // Returns the size of the set that contains element 'a'.
    int sizeOf(int a) {
        return compSize[find(a)];
    }

    // Returns the current number of disjoint sets.
    int countComponents() {
        return components;
    }
};