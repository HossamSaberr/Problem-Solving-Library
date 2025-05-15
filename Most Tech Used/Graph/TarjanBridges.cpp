// Tarjan's algorithm for finding all bridges in an undirected graph
struct TarjanBridges {
    int n , n2;                           // number of vertices
    int timer,timer2 ,ways,ways2 ;                       // discovery time counter
    vector<vector<int>> adj;         // adjacency list
    vector<int> disc,disc2;                // discovery times
    vector<int> low,low2 , bridges2;                 // lowlink values
    vector<pair<int,int>> bridges;   // list of bridges (u, v)
    vector<vector<pair<int,int>>> adj2;

    // Constructor: initialize for a graph with _n vertices
    TarjanBridges(int _n)
            : n(_n), timer(0) , ways(1), adj(_n), disc(_n, -1), low(_n, -1),n2(_n), timer2(0) , ways2(1), adj2(_n), disc2(_n, -1), low2(_n, -1)  {}

    // Add an undirected edge (u <-> v)
    void addEdge(int u, int v) {
        if (u<0 || u>=n || v<0 || v>=n) return;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Reset internal state (clear edges and previous results)
    void reset(int _n) {
        n = _n;
        timer = 0;
        adj.assign(n, {});
        disc.assign(n, -1);
        low.assign(n, -1);
        bridges.clear();
    }

    // Internal DFS to compute discovery and lowlink values
    void dfs(int u, int parent) {
        disc[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.emplace_back(u, v);
                }
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    // Compute and return all bridges in the graph
    vector<pair<int,int>> findBridges() {
        // Clear any previous run
        bridges.clear();
        fill(disc.begin(), disc.end(), -1);
        fill(low.begin(), low.end(), -1);
        timer = 0;
        // Run DFS from each component
        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) {
                dfs(i, -1);
            }
        }
        return bridges;
    }

    // Get number of bridges
    size_t count() const {
        return bridges.size();
    }

    // Check if (u, v) is a bridge (undirected)
    bool isBridge(int u, int v) const {
        auto p1 = make_pair(u, v);
        auto p2 = make_pair(v, u);
        return find(bridges.begin(), bridges.end(), p1) != bridges.end() ||
               find(bridges.begin(), bridges.end(), p2) != bridges.end();
    }

    // Print all bridges to an output stream
    void printBridges(ostream &out = cout) const {
        for (auto &e : bridges) {
            out << e.first << " " << e.second << "\n";
        }
    }

    void addEdge2(int u, int v, int eid) {
        adj2[u].emplace_back(v,eid);
        adj2[v].emplace_back(u,eid);
    }

    void dfs2(int u, int pe) {
        disc2[u] = low2[u] = timer2++;
        for (auto [v,eid] : adj2[u]) {
            if (eid == pe) continue;
            if (disc2[v] == -1) {
                dfs2(v, eid);
                low2[u] = min(low2[u], low2[v]);
                if (low2[v] > disc2[u]) {
                    bridges2.push_back(eid);
                }
            } else {
                low2[u] = min(low2[u], disc2[v]);
            }
        }
    }

    vector<int> findBridges2() {
        bridges2.clear();
        fill(disc2.begin(), disc2.end(), -1);
        fill(low2.begin(),  low2.begin(),  -1);
        timer2 = 0;
        for (int i = 0; i < n2; ++i)
            if (disc2[i] == -1)
                dfs2(i, -1);
        return bridges2;
    }

    // After you call findBridges(), this builds and returns the bridge‑tree.
    // Each node in the returned tree corresponds to one 2‑edge‑connected component.
    // Edges between those nodes correspond exactly to the bridges in the original graph.
    vector<vector<int>> buildBridgeTree() {
        // Ensure bridges[] is populated
        findBridges();

        // comp[u] will hold the component ID of vertex u
        vector<int> comp(n, -1);
        int compCnt = 0;

        // Mark bridges in a set for O(1) lookups
        unordered_set<long long> isBridge;
        for (auto &e : bridges) {
            int u = e.first, v = e.second;
            // encode pair (u,v) into a single long long
            isBridge.insert(((long long)u << 32) | (unsigned long long)v);
            isBridge.insert(((long long)v << 32) | (unsigned long long)u);
        }

        // DFS to label components, never crossing a bridge
        function<void(int)> dfs2 = [&](int u) {
            comp[u] = compCnt;
            for (int v : adj[u]) {
                long long code = ((long long)u << 32) | (unsigned long long)v;
                if (comp[v] == -1 && !isBridge.count(code)) {
                    dfs2(v);
                }
            }
        };

        // Label each component
        for (int i = 0; i < n; ++i) {
            if (comp[i] == -1) {
                dfs2(i);
                ++compCnt;
            }
        }

        // Build the tree: one node per component
        vector<vector<int>> tree(compCnt);
        for (auto &e : bridges) {
            int cu = comp[e.first];
            int cv = comp[e.second];
            tree[cu].push_back(cv);
            tree[cv].push_back(cu);
        }

        return tree;
    }

    // DFS from u, parent = p for **Cactus graph**
    // Cactus graph: each non-bridge edge closes exactly one cycle.
    void dfss(int u, int p) {
        disc[u] = low[u] = ++timer;  // discovery time starts at 1
        for (int v : adj[u]) {
            if (v == p) continue;
            if (!disc[v]) {
                // tree edge
                dfss(v, u);
                low[u] = min(low[u], low[v]);
            } else if (disc[v] < disc[u]) {
                // back-edge closing a cycle of length (disc[u]-disc[v]+1)
                low[u] = min(low[u], disc[v]);
                int cycle_len = (disc[u] - disc[v] + 1);
                ways = (ways * cycle_len) % MOD;
            }
        }
    }

    // Compute number of ways by running DFS on all components
    int countSpanningTrees() {
        // ensure fresh state if dfs called twice
        fill(disc.begin(), disc.end(), 0);
        fill(low.begin(), low.end(), 0);
        ways = 1;
        timer = 0;
        for (int i = 0; i < n; ++i) {
            if (!disc[i]) dfss(i, -1);
        }
        return ways;
    }
};