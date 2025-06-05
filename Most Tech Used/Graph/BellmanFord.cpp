// A large value used as "infinity"
static const long long INF = 1e18;

// Edge structure for Bellman–Ford
struct Edge {
    int u;          // source vertex
    int v;          // destination vertex
    long long w;    // edge weight

    Edge(int _u, int _v, long long _w)
            : u(_u), v(_v), w(_w) {}
};

// Bellman–Ford implementation with negative‐cycle detection,
// propagation of affected nodes, and path reconstruction.
struct BellmanFord {
    int n;                                 // Number of vertices
    vector<Edge> edges;                    // List of edges
    vector<vector<int>> adj;               // Adjacency list for propagation
    vector<long long> dist;                // Distance from source
    vector<int> parent;                    // Parent in shortest‐path tree
    vector<bool> negAffected;              // Marks nodes affected by any negative cycle

    // Constructor: initializes for 'n' vertices
    BellmanFord(int _n)
            : n(_n),
              adj(_n + 1),
              dist(_n + 1, INF),
              parent(_n + 1, -1),
              negAffected(_n + 1, false)
    {}

    // Add a directed edge (u → v) with weight w
    void addEdge(int u, int v, long long w) {
        edges.emplace_back(u, v, w);
        adj[u].push_back(v);
    }

    // Run Bellman–Ford from source 's'. After calling run(s),
    // - dist[v] will be the shortest distance from s to v (if no negative cycle)
    // - negAffected[v] will be true if v is reachable from some negative cycle
    void run(int s) {
        // Step 1: Initialize
        fill(dist.begin(), dist.end(), INF);
        fill(parent.begin(), parent.end(), -1);
        fill(negAffected.begin(), negAffected.end(), false);

        dist[s] = 0;

        // Step 2: Relax all edges (n-1) times
        for (int iter = 0; iter < n - 1; iter++) {
            bool updated = false;
            for (const Edge &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                    updated = true;
                }
            }
            // Early exit if no update in this iteration
            if (!updated) break;
        }

        // Step 3: Detect nodes on or reachable from negative cycles
        // First, mark all vertices v for which there is an edge u→v that can still be relaxed
        vector<bool> inNegCycle(n, false);
        for (const Edge &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                inNegCycle[e.v] = true;
            }
        }

        // Propagate "negAffected" to all nodes reachable from any inNegCycle node
        // via DFS/BFS on the adjacency list.
        // We use a queue for BFS here.
        queue<int> q;
        vector<bool> visited(n, false);

        // Enqueue initial set of nodes directly in a negative cycle
        for (int v = 0; v < n; v++) {
            if (inNegCycle[v]) {
                negAffected[v] = true;
                visited[v] = true;
                q.push(v);
            }
        }

        // BFS to mark all reachable nodes as affected
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int nxt : adj[u]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    negAffected[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }

    // Run Bellman–Ford from multiple sources in 'sources'.
// After this, dist[v] = min distance from any source ∈ sources,
// negAffected[v] = true if v is in/affected by a negative cycle reachable from at least one source.
    void runMultiSource(const vector<int>& sources) {
        // 1) Initialize distances & parents & negAffected
        fill(dist.begin(), dist.end(), INF);
        fill(parent.begin(), parent.end(), -1);
        fill(negAffected.begin(), negAffected.end(), false);

        // 2) Set all given sources to distance = 0
        for (int s : sources) {
            if (s >= 0 && s < n) {
                dist[s] = 0;
                parent[s] = -1;
            }
        }

        // 3) Relax all edges (n − 1) times
        for (int iter = 0; iter < n - 1; iter++) {
            bool updated = false;
            for (const Edge &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                    updated = true;
                }
            }
            if (!updated) break;  // early exit if no change
        }

        // 4) Detect which vertices are in a negative cycle “frontier”
        vector<bool> inNegCycle(n, false);
        for (const Edge &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                inNegCycle[e.v] = true;
            }
        }

        // 5) Propagate that “negative‐affected” mark through adjacency
        queue<int> q;
        vector<bool> visited(n, false);
        for (int v = 0; v < n; v++) {
            if (inNegCycle[v]) {
                negAffected[v] = true;
                visited[v] = true;
                q.push(v);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int nxt : adj[u]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    negAffected[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }

    // ──────────────────────────────────────────────────────────────────────
    // [NEW] “General” run: no sources specified → treat *all* vertices as if
    // they were distance=0 sources.
    //──────────────────────────────────────────────────────────────────────
    void runNoSource() {
        // Step 0: initialize
        fill(dist.begin(), dist.end(), 0LL);
        fill(parent.begin(), parent.end(), -1);
        fill(negAffected.begin(), negAffected.end(), false);

        // Relax edges (n-1) times, exactly as if every node started at dist=0.
        for (int iter = 0; iter < n - 1; iter++) {
            bool updated = false;
            for (auto &e : edges) {
                // Note: dist[e.u] is never INF, since we set everything to 0 initially.
                if (dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        // Detect “frontier” of negative cycles just like before:
        vector<bool> inNegCycle(n, false);
        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                inNegCycle[e.v] = true;
            }
        }

        // Propagate the negative‐cycle effect through the adjacency list:
        queue<int> q;
        vector<bool> visited(n, false);
        for (int v = 0; v < n; v++) {
            if (inNegCycle[v]) {
                negAffected[v] = true;
                visited[v] = true;
                q.push(v);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int nx : adj[u]) {
                if (!visited[nx]) {
                    visited[nx] = true;
                    negAffected[nx] = true;
                    q.push(nx);
                }
            }
        }
    }

    // Retrieve shortest‐path distance to vertex 'v'.
    // Returns INF if unreachable; if negAffected[v] is true, the distance is undefined.
    long long distanceTo(int v) const {
        return dist[v];
    }

    // Check if vertex 'v' is affected by a negative cycle
    bool isInNegativeCycleComponent(int v) const {
        return negAffected[v];
    }

    // Return a vector of all vertices affected by a negative cycle.
    vector<int> getAllNegAffected() const {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (negAffected[i]) {
                result.push_back(i);
            }
        }
        return result;
    }

    // Reconstruct and return a shortest path from the source to 'v'.
    // If v is unreachable, returns an empty vector.
    // If v is affected by a negative cycle, returns an empty vector (no well‐defined shortest path).
    vector<int> getPath(int v) const {
        vector<int> path;
        if (dist[v] == INF) {
            // v is unreachable
            return path;
        }
        if (negAffected[v]) {
            // v is affected by a negative cycle; no well-defined shortest path
            return path;
        }
        // Walk back through parent pointers
        int cur = v;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        return path;
    }
    // Attempt to find and return one negative cycle (if it exists).
    // Returns true and fills 'cycle' with vertices in order (starting and ending at same node)
    // if there is a negative cycle; otherwise returns false.
    bool getNegativeCyclePath(vector<int> &cycle) {
        // 3) On the n-th pass, see if any edge can still be relaxed.
        //    If so, that v = x is “either on a negative cycle or leads into one.”
        int x = -1;
        for (auto &e : edges) {
            int u = e.u, v = e.v;
            long long w = e.w;
            if (dist[u] + w < dist[v]) {
                x = v;
                break;
            }
        }
        if (x == -1) {
            // No edge relaxed on the n-th pass ⇒ no negative cycle
            return false;
        }

        // 4) To force x *onto* the cycle (and not just “downstream”), walk parent[x] exactly n times.
        //    After n steps, x must lie on the cycle itself.
        for (int i = 0; i < n; i++) {
            x = parent[x];
        }

        // 5) Collect the cycle by following parent[] until we return to x.
        int cur = x;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != x);
        cycle.push_back(x);

        // Reverse, so the output goes from “first visit of x” forward around the cycle, back to x.
        reverse(cycle.begin(), cycle.end());
        return true;
    }
};

// Example usage:
//
// int main() {
//     int n = 6; // number of vertices (0..5)
//     BellmanFord bf(n);
//
//     // Add edges: bf.addEdge(u, v, w);
//     bf.addEdge(0, 1, 5);
//     bf.addEdge(1, 2, 2);
//     bf.addEdge(2, 3, 1);
//     bf.addEdge(3, 1, -7); // creates a negative cycle among 1-2-3
//     bf.addEdge(0, 4, 10);
//     bf.addEdge(4, 5, 3);
//
//     int source = 0;
//     bf.run(source);
//
//     // Print distances or detect negative cycles
//     for (int v = 0; v < n; v++) {
//         if (bf.distanceTo(v) == INF) {
//             cout << "Vertex " << v << ": unreachable\n";
//         } else if (bf.isInNegativeCycleComponent(v)) {
//             cout << "Vertex " << v << ": affected by negative cycle\n";
//         } else {
//             cout << "Vertex " << v << ": dist = " << bf.distanceTo(v) << "\n";
//             vector<int> path = bf.getPath(v);
//             cout << "  Path: ";
//             for (int u : path) {
//                 cout << u << " ";
//             }
//             cout << "\n";
//         }
//     }
//
//     // List all nodes affected by negative cycles
//     vector<int> negNodes = bf.getAllNegAffected();
//     cout << "Nodes affected by negative cycles: ";
//     for (int x : negNodes) cout << x << " ";
//     cout << "\n";
//
//     return 0;
// }
