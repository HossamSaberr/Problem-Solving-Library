struct EulerGraph {
    int nodes;
    int edges;
    vector<set<int>> adj;
    vector<int> degree;
    vector<int> visited;
    EulerGraph(int n, int m) : nodes(n), edges(m), adj(n), degree(n, 0), visited(m, 0) {}
    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u]++;
        degree[v]++;
    }
    vector<int> eulerPath() {
        int oddCount = 0;
        int startNode = -1;
        for (int i = 0; i < nodes; ++i) {
            if (degree[i] % 2 == 1) {
                oddCount++;
                startNode = i;
            }
        }
        if (oddCount != 0 and oddCount != 2)
            return {};
        if (startNode == -1)
            startNode = 0;
        vector<int> path;
        stack<int> stack;
        stack.push(startNode);
        while (!stack.empty()) {
            int u = stack.top();
            if (adj[u].empty()) {
                path.push_back(u);
                stack.pop();
            }
            else {
                int v = *adj[u].begin();
                stack.push(v);
                adj[u].erase(v);
                adj[v].erase(u);
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
