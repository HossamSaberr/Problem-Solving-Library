const int MOD = 1e9 + 7;
inline long long add(long long a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline long long mul(long long a, long long b) {
    return (a * b) % MOD;
}
struct SegmentTree {
    struct Node {
        long long s1, s2, s3, lz;
        Node(): s1(0), s2(0), s3(0), lz(0) {}
    };
    int n;
    vector<Node> seg;

    SegmentTree(const vector<int> &A): n(A.size()) {
        seg.resize(4*n);
        build(1, 0, n-1, A);
    }

    // Apply “add x” to node idx covering length m
    void apply(int idx, int m, long long x) {
        x %= MOD;
        long long x2 = mul(x, x), x3 = mul(x2, x);
        seg[idx].s3 = add(seg[idx].s3,
                          add(add(mul(3*x % MOD, seg[idx].s2),
                                  mul(3*x2 % MOD, seg[idx].s1)),
                              mul(m, x3)));
        seg[idx].s2 = add(seg[idx].s2,
                          add(mul(2*x % MOD, seg[idx].s1),
                              mul(m, x2)));
        seg[idx].s1 = add(seg[idx].s1, mul(m, x));
        seg[idx].lz = add(seg[idx].lz, x);
    }

    void push(int idx, int l, int r) {
        if (seg[idx].lz && l < r) {
            int mid = (l + r) >> 1;
            apply(idx<<1,     mid - l + 1, seg[idx].lz);
            apply(idx<<1|1, r - (mid+1) + 1, seg[idx].lz);
            seg[idx].lz = 0;
        }
    }

    void pull(int idx) {
        seg[idx].s1 = add(seg[idx<<1].s1, seg[idx<<1|1].s1);
        seg[idx].s2 = add(seg[idx<<1].s2, seg[idx<<1|1].s2);
        seg[idx].s3 = add(seg[idx<<1].s3, seg[idx<<1|1].s3);
    }

    void build(int idx, int l, int r, const vector<int> &A) {
        if (l == r) {
            long long v = A[l] % MOD;
            seg[idx].s1 = v;
            seg[idx].s2 = mul(v, v);
            seg[idx].s3 = mul(seg[idx].s2, v);
        } else {
            int mid = (l + r) >> 1;
            build(idx<<1, l, mid, A);
            build(idx<<1|1, mid+1, r, A);
            pull(idx);
        }
    }

    // public: add x on [ql..qr]
    void update(int ql, int qr, long long x) {
        update(1, 0, n-1, ql, qr, x);
    }
    void update(int idx, int l, int r, int ql, int qr, long long x) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(idx, r-l+1, x);
            return;
        }
        push(idx, l, r);
        int mid = (l + r) >> 1;
        update(idx<<1, l, mid, ql, qr, x);
        update(idx<<1|1, mid+1, r, ql, qr, x);
        pull(idx);
    }

    // public: returns sum of cubes on [ql..qr]
    long long query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr).s3;
    }
    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node();
        if (ql <= l && r <= qr) return seg[idx];
        push(idx, l, r);
        int mid = (l + r) >> 1;
        Node L = query(idx<<1, l, mid, ql, qr);
        Node R = query(idx<<1|1, mid+1, r, ql, qr);
        Node res;
        res.s1 = add(L.s1, R.s1);
        res.s2 = add(L.s2, R.s2);
        res.s3 = add(L.s3, R.s3);
        return res;
    }
};