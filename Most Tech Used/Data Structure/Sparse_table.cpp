struct GcdSparseTable {
    int n, K;
    vector<vector<int>> st;

    // Build from array 'a' in O(n log n)
    GcdSparseTable(const vector<int>& a) {
        n = a.size();
        K = 32 - __builtin_clz(n);           // max power of two ≤ n
        st.assign(K, vector<int>(n));
        st[0] = a;
        for (int j = 1; j < K; ++j) {
            int len = 1 << j;
            for (int i = 0; i + len <= n; ++i) {
                st[j][i] = gcd(st[j-1][i], st[j-1][i + (len >> 1)]);
            }
        }
    }

    // Query gcd over [l..r] in O(1)
    int query(int l, int r) const {
        if (l > r) return 0;
        int len = r - l + 1;
        int j   = __lg(len);
        return gcd(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
struct LcmSparseTable {
    int n, K;
    vector<vector<int>> st;

    LcmSparseTable(const vector<int>& a) {
        n = a.size();
        K = __lg(n) + 1;
        st.assign(K, vector<int>(n));
        st[0] = a;
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[j][i] = computeLcm(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }

    int query(int l, int r) {
        if (l > r) return 0;
        int len = r - l + 1;
        int res = 1;
        for (int j = K - 1; j >= 0; --j) {
            if ((1 << j) <= len) {
                res = computeLcm(res, st[j][l]);
                l += 1 << j;
                len -= 1 << j;
            }
        }
        return res;
    }
};
struct MinSparseTable {
    int n, K;
    vector<vector<int>> st;

    MinSparseTable(const vector<int>& a) {
        n = a.size();
        K = __lg(n) + 1;
        st.assign(K, vector<int>(n));
        st[0] = a;
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i)
                st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
        }
    }

    int query(int l, int r) {
        if (l > r) return 0;
        int j = __lg(r - l + 1);
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

struct MaxSparseTable {
    int n, K;
    vector<vector<int>> st;

    MaxSparseTable(const vector<int>& a) {
        n = a.size();
        K = __lg(n) + 1;
        st.assign(K, vector<int>(n));
        st[0] = a;
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i)
                st[j][i] = max(st[j-1][i], st[j-1][i + (1 << (j-1))]);
        }
    }

    int query(int l, int r) {
        if (l > r) return 0;
        int j = __lg(r - l + 1);
        return max(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
struct SumSparseTable {
    int n, K;
    vector<vector<ll>> st;

    SumSparseTable(const vector<int>& a) {
        n = a.size();
        K = __lg(n) + 1;
        st.assign(K, vector<ll>(n));
        for (int i = 0; i < n; ++i)
            st[0][i] = a[i];

        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i)
                st[j][i] = st[j-1][i] + st[j-1][i + (1 << (j-1))];
        }
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        ll sum = 0;
        for (int j = K - 1; j >= 0; --j) {
            if ((1 << j) <= r - l + 1) {
                sum += st[j][l];
                l += 1 << j;
            }
        }
        return sum;
    }
};