struct DSU {
    vector<int> parent, rank, compSize , nextedge , dist , parity;
    int components; // Number of disjoint sets

    // Constructor initializes DSU for 'n' elements.
    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        dist.assign(n + 1, 0);
        parity.assign(n + 1, 0);
        compSize.assign(n + 1, 1);
        nextedge.resize(n + 1);
        components = n;
        for (int i = 0; i <= n; ++i)
            parent[i] = nextedge[i] = i;
    }

    // Find function with path compression.
    int find(int x) {
        if (x == parent[x]) return x;
        int orig_parent = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[orig_parent];  // Update parity along the path
        return parent[x];
    }
    // here the merge range trick
    int find2(int a) {
        if (nextedge[a] != a)
            nextedge[a] = find2(nextedge[a]);
        return nextedge[a];
    }

    // Union by size: merge the sets containing a and b.
    // Returns true if a union was performed, false if already in the same set.

    bool unionSets(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return false;

        // Ensure that a represents the larger set.
        if (compSize[pa] < compSize[pb])
            swap(pa, pb);

        parent[pb] = pa;
        parity[pb] = parity[a] ^ parity[b] ^ 1;
        compSize[pa] += compSize[pb];
        components--;
        return true;
    }
    int dep(int u){
        if(parent[u] == u) return u;
        int p = parent[u];
        parent[u] = dep(p);
        dist[u] += dist[p];
        return parent[u];
    }
    void link(int a, int b) {
        parent[a] = b;
        dist[a] = 1;
    }
    int get_dis_to_boss(int u) {
        dep(u);
        return dist[u];
    }
    // merge range trick
    void unionSets2(int a, int b) {
        nextedge[find2(a)] = find2(b);
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
    // if you need to check that the graph is bipartite you can do it by merge u with v + n and v with u + n and if u and v in the same set so its not (check before merge if you try to find first idx make it non bip)
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