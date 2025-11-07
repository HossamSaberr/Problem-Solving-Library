vector<string> rotate90(vector<string> &g) {
    int n = g.size(), m = g[0].size();
    vector res(m, string(n, '0'));
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            res[i][j] = g[n - j - 1][i];
    return res;
}