struct SegTree {
    int sz = 1 , neutral = 1;

    vector<long long> t;
    SegTree(int n) {
        while(sz < n) sz += sz;
        t.resize(2 * sz);
    }

    long long merge(long long a, long long b) {
        return (a * b) % MOD;
    }

    void pull(int x) {
        t[x] = merge(t[2 * x], t[2 * x + 1]);
    }

    void update (int x, int lx, int rx, int l, int r, long long val) {
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {
            t[x] += val;
            return;
        }
        int m = (lx + rx) >> 1;
        update(2 * x, lx, m, l, r, val);
        update(2 * x + 1, m + 1, rx, l, r, val);
        pull(x);
    }

    void update(int l, long long val) {
        update(1, 1, sz, l, l, val);
    }

    int query(int x, int lx, int rx, int l, int r) {
        if (lx > r || rx < l) return neutral;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx) >> 1;
        int a = query(2 * x, lx, m, l, r);
        int b = query(2 * x + 1, m + 1, rx, l, r);
        return merge(a, b);
    }

    int query(int l, int r) {
        return query(1, 1, sz, l, r);
    }

};