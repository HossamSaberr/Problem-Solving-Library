struct FloydWarshall {
    int n;
    vector<vector<long long>> dist;
    vector<vector<bool>> neg;  // neg[i][j] = true if i→j can go through a neg-cycle
 
    FloydWarshall(int _n)
            : n(_n),
              dist(n, vector<long long>(n, 1e18)),
              neg(n, vector<bool>(n, false))
    {
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;
    }
 
    void add_edge(int u, int v, long long w) {
        dist[u][v] = min(dist[u][v], w);
    }
 
    void run() {
        // 1) Standard Floyd–Warshall
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == 1e18) continue;
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == 1e18) continue;
                    long long via = dist[i][k] + dist[k][j];
                    if (via < dist[i][j]) {
                        dist[i][j] = via;
                    }
                }
            }
        }
 
        // 2) Negative‐cycle detection & propagation
        //    If dist[k][k] < 0, node k lies on a neg-cycle.
        //    Then any i→k and k→j path means i→j can be made arbitrarily small.
        for (int k = 0; k < n; ++k) {
            if (dist[k][k] < 0) {
                for (int i = 0; i < n; ++i) {
                    if (dist[i][k] == 1e18) continue;
                    for (int j = 0; j < n; ++j) {
                        if (dist[k][j] == 1e18) continue;
                        neg[i][j] = true;
                    }
                }
            }
        }
    }
 
    // Returns true if there is a path from u to v that goes through a negative cycle
    bool has_neg_cycle(int u, int v) const {
        return neg[u][v];
    }
 
    // Returns INF if no path, otherwise the shortest distance (possibly negative).
    long long get_distance(int u, int v) const {
        return dist[u][v];
    }
};
