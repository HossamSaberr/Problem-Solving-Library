struct Fenwick2D {
    vector<vector<int>> tree;
    int n , m;
    Fenwick2D(int _n , int _m): n(_n) , m(_m), tree(n+1,vector<int>(m + 1 , 0)) {}
    void update(int x, int y, int val) {
        for (int i = x + 1; i <= n; i += (i & (-i))) {
            for (int j = y + 1; j <= m; j += (j & (-j))) {
                tree[i - 1][j - 1] += val;
            }
        }
    }
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x + 1; i; i -= (i & (-i))) {
            for (int j = y + 1; j; j -= (j & (-j))) {
                ret += tree[i - 1][j - 1];
            }
        }
        return ret;
    }
    int query(int sx, int sy, int ex, int ey) { return sum(ex, ey) - sum(ex, sy - 1) - sum(sx - 1, ey) + sum(sx - 1, sy - 1); }
    int query(int x , int y){ return query(x , y , x , y); }
};