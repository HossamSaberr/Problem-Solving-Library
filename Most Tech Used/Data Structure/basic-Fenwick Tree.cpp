struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    void update(int i, int v){ for (++i; i <= n; i += i & -i) f[i] += v; }
    int query(int i){ int s=0; for (++i; i > 0; i -= i & -i) s += f[i]; return s; }
    int rangeQuery(int l, int r){ return query(r) - query(l-1); }
};