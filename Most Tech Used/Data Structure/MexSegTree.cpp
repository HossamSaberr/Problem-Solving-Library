struct MexSegTree {
    int n0, N;
    vector<int> tmin, tmax;
    static constexpr int INF = 0x3f3f3f3f;

    MexSegTree(int _N = 0) {
        N = _N;
        n0 = 1;
        while (n0 < N) n0 <<= 1;
        tmin.assign(2*n0, +INF);
        tmax.assign(2*n0, -INF);
    }

    // Build in O(n) from pos[1..N]
    void build(const vector<int>& pos) {
        for (int x = 1; x <= N; x++) {
            int leaf = n0 + (x-1);
            tmin[leaf] = tmax[leaf] = pos[x];
        }
        for (int i = n0-1; i >= 1; i--) {
            tmin[i] = min(tmin[2*i],   tmin[2*i+1]);
            tmax[i] = max(tmax[2*i],   tmax[2*i+1]);
        }
    }

    // Point-update: set
    void update(int idx , int val) {
        int i = n0 + (val-1);
        tmin[i] = tmax[i] = idx;
        for (i >>= 1; i; i >>= 1) {
            tmin[i] = min(tmin[2*i],   tmin[2*i+1]);
            tmax[i] = max(tmax[2*i],   tmax[2*i+1]);
        }
    }

    // Internal DFS-style search for smallest x whose pos[x] ∉ [L..R]
    int find_first_out(int node, int l, int r, int L, int R) {
        if (tmin[node] >= L && tmax[node] <= R) return INF;
        if (l == r) return l + 1;  // leaf → value = l+1
        int mid = (l + r) >> 1;
        int res = find_first_out(2*node,   l,   mid, L, R);
        if (res != INF) return res;
        return find_first_out(2*node+1, mid+1, r, L, R);
    }

    // Public mex query on [L..R]
    // Returns smallest x∈[1..N] with pos[x] ∉ [L..R], or N+1 if none
    int mex(int L, int R) {
        int x = find_first_out(1, 0, n0-1, L, R);
        return (x == INF || x > N) ? (N + 1) : x;
    }
};