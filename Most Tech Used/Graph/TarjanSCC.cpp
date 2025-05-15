struct TarjanSCC {
    int n;
    vector<vector<int>> adj;
    vector<int> origWeight;
    vector<int> dag_in_degree;
    vector<int> dfn, lowLink, comp;
    vector<bool> inStack;
    stack<int> st;
    int timer;

    vector<vector<int>> components;
    vector<vector<int>> dag;
    vector<int> compWeight;

    // Construct with node count and optional weights
    TarjanSCC(int _n, const vector<int>& weight = {})
        : n(_n), adj(n)
    {
        // initialize weights
        if (weight.empty()) {
            origWeight.assign(n, 1);
        } else {
            if ((int)weight.size() != n)
                throw invalid_argument("Weight array size must match number of nodes");
            origWeight = weight;
        }
        // allocate working arrays
        dag_in_degree.assign(n, 0);
        dfn.assign(n, -1);
        lowLink.assign(n, 0);
        comp.assign(n, -1);
        inStack.assign(n, false);
        timer = 0;
    }

    // add a directed edge u -> v
    void addEdge(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n)
            throw out_of_range("Node index out of range");
        adj[u].push_back(v);
    }

    // run Tarjan to find SCCs and build DAG
    void run() {
        for (int u = 0; u < n; ++u) {
            if (dfn[u] == -1)
                tarjan(u);
        }
        buildDag();
        // compute component weights
        compWeight.assign(components.size(), 0);
        for (int u = 0; u < n; ++u) {
            compWeight[comp[u]] += origWeight[u];
        }
    }

    // Getters
    const vector<vector<int>>& getSCCs() const {
        return components;
    }
    const vector<vector<int>>& getDAG() const {
        return dag;
    }
    const vector<int>& getComponentWeights() const {
        return compWeight;
    }
    const vector<int>& getInDegree() const {
        return dag_in_degree;
    }
    // Get component ID of a specific node
    int getComponentID(int u) const {
        if (u < 0 || u >= n)
            throw out_of_range("Node index out of range");
        return comp[u];
    }
    // Or get entire compID vector
    const vector<int>& getCompID() const {
        return comp;
    }

private:
    void tarjan(int u) {
        dfn[u] = lowLink[u] = timer++;
        inStack[u] = true;
        st.push(u);

        for (int v : adj[u]) {
            if (dfn[v] == -1) {
                tarjan(v);
                lowLink[u] = min(lowLink[u], lowLink[v]);
            } else if (inStack[v]) {
                lowLink[u] = min(lowLink[u], dfn[v]);
            }
        }

        if (lowLink[u] == dfn[u]) {
            components.emplace_back();
            while (true) {
                int x = st.top(); st.pop();
                inStack[x] = false;
                comp[x] = (int)components.size() - 1;
                components.back().push_back(x);
                if (x == u) break;
            }
        }
    }

    void buildDag() {
        int csz = components.size();
        dag.assign(csz, {});
        dag_in_degree.assign(csz, 0);
        vector<int> lastSeen(csz, -1);

        for (int u = 0; u < n; ++u) {
            int cu = comp[u];
            for (int v : adj[u]) {
                int cv = comp[v];
                if (cu != cv && lastSeen[cv] != cu) {
                    dag[cu].push_back(cv);
                    dag_in_degree[cv]++;
                    lastSeen[cv] = cu;
                }
            }
        }
    }
};