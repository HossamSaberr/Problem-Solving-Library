struct Fenwick {
    int N;     // size of the array
    int* F;    // internal 1‑based tree array

    // construct size n (all zeros)
    Fenwick(int n) : N(n) {
        F = new int[N + 1]();  // value‑init to zero
    }

    // clean up
    ~Fenwick() {
        delete[] F;
    }

    // point‑add: A[idx] += v
    // idx is 0‑based
    inline void update(int idx, int v) {
        assert(idx >= 0 && idx < N);
        for (int i = idx + 1; i <= N; i += i & -i)
            F[i] += v;
    }

    // prefix sum: returns sum A[0] + … + A[idx]
    inline int query(int idx) const {
        assert(idx >= 0 && idx < N);
        int s = 0;
        for (int i = idx + 1; i > 0; i -= i & -i)
            s += F[i];
        return s;
    }

    // range sum [l..r], both inclusive
    inline int range(int l, int r) const {
        assert(0 <= l && l <= r && r < N);
        return query(r) - (l ? query(l - 1) : 0);
    }

    // find smallest index such that prefix sum > target
    // returns N if no such index exists
    inline int lower_bound(int target) const {
        int pos = 0;
        int bitMask = 1 << (31 - __builtin_clz(N));
        for (; bitMask; bitMask >>= 1) {
            int nxt = pos + bitMask;
            if (nxt <= N && F[nxt] <= target) {
                target -= F[nxt];
                pos = nxt;
            }
        }
        // pos is number of elements whose prefix sum ≤ original target
        // so the first index with prefix sum > target is pos (0‑based)
        return pos;
    }
};