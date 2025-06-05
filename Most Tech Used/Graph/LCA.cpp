#include <bits/stdc++.h>
using namespace std;

/*
  LCA with binary‐lifting + “merge on path” (generic).
  - 1‐based indexing for nodes (if you prefer 0‐based, shift inputs accordingly).
  - Supports:
      * build(root)
      * int kthAncestor(int u, int k)
      * int get_lca(int u, int v)
      * treeType query(int u, int v)   // merge of edge‐weights on path u→v
      * WeightType distance(int u, int v)  // weighted distance (sum of weights) from u to v
  - O(N log N) preprocessing, O(log N) per query.
  - You can “reroot” by calling build(new_root) in O(N log N) again.
  
  Template parameters:
    - treeType  : the type in which you want to accumulate your merged result (e.g. long long).
    - graphType : the type of edge‐weights stored in your adjacency list (often int or long long).
  
  Constructor signature:
    LCA(
      int n = 0,
      const vector<vector<pair<int,graphType>>> &G = {},
      function<treeType(treeType,treeType)> op = [](treeType a, treeType b){ return a + b; },
      treeType _neutral = treeType(),
      int root = 1
    );
  
  After constructing (or calling init+addEdge), call build(root) once. That fills:
    anc[u][j]  = 2^j-th ancestor of u.
    cost[u][j] = op( edge‐weights on the path from u up to anc[u][j] ).
    depth[u]   = depth of u from root.
    dist[u]    = sum of weights from root to u (for distance queries).
*/

template<typename treeType = long long, typename graphType = long long>
struct LCA {
    int N, LOG, ROOT;
    vector<vector<pair<int, graphType>>> adj;  // adj[u] = { {v, weight}, ... }
    vector<vector<int>>           anc;         // anc[u][j] = 2^j-th ancestor of u
    vector<vector<treeType>>      cost;        // cost[u][j] = merged edge-weights from u→anc[u][j]
    vector<int>                   depth;       // depth[u]
    vector<graphType>             dist;        // dist[u] = sum of weights from ROOT to u
    function<treeType(treeType, treeType)> operation;
    treeType neutral;

    // Constructor: you can pass `G` (adjacency) directly, or call init+addEdge later.
    LCA(
        int n = 0,
        const vector<vector<pair<int,graphType>>> &G = {},
        function<treeType(treeType, treeType)> op = [](treeType a, treeType b){ return a + b; },
        treeType _neutral = treeType(),
        int root = 1
    ) : N(n), ROOT(root), adj(G), operation(op), neutral(_neutral) 
    {
        // If G is non-empty, copy it into adj[1..N], then build immediately.
        init(N);
        if (!G.empty()) {
            for (int u = 1; u <= N; u++) {
                for (auto &e : G[u]) {
                    // We assume G is already 1-based and undirected. If it isn't,
                    // make sure to call addEdge yourself instead of passing G here.
                    adj[u].push_back(e);
                }
            }
            build(ROOT);
        }
    }

    // (Re)initialize for n nodes. You must call build(root) before querying.
    void init(int n) {
        N = n;
        // Compute LOG = ceil(log2(n+1)) so that (1<<LOG) > N
        LOG = 1;
        while ((1 << LOG) <= N) LOG++;

        adj.assign(N + 1, {});
        anc.assign(N + 1, vector<int>(LOG, -1));
        cost.assign(N + 1, vector<treeType>(LOG, neutral));
        depth.assign(N + 1, 0);
        dist.assign(N + 1, 0);
        ROOT = 1;
    }

    // Add an undirected edge u<->v with weight w.
    // Nodes are assumed to be 1..N. If you use 0-based, shift accordingly.
    void addEdge(int u, int v, graphType w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Build the LCA tables, rooting the tree at `root`.
    // Fills anc[u][*], cost[u][*], depth[u], dist[u].
    // O(N log N).
    void build(int root = 1) {
        ROOT = root;
        // Reset depth, dist, anc, cost
        for (int u = 1; u <= N; u++) {
            depth[u] = 0;
            dist[u]  = 0;
            for (int j = 0; j < LOG; j++) {
                anc[u][j]  = -1;
                cost[u][j] = neutral;
            }
        }
        // Run DFS from root (parent = -1, depth = 0, initial edgeWeight = neutral)
        dfs(ROOT, -1, 0, neutral);

        // Build the upper levels of anc[][] and cost[][]
        for (int j = 1; j < LOG; j++) {
            for (int u = 1; u <= N; u++) {
                int mid = anc[u][j - 1];
                if (mid < 0) {
                    // If there's no 2^(j-1) ancestor, there's no 2^j ancestor either
                    anc[u][j]  = -1;
                    cost[u][j] = cost[u][j - 1];
                } else {
                    anc[u][j]  = anc[mid][j - 1];
                    cost[u][j] = operation(
                        cost[u][j - 1],
                        cost[mid][j - 1]
                    );
                }
            }
        }
    }

    // Return the k-th ancestor of u (or -1 if it doesn't exist). O(log N).
    int kthAncestor(int u, int k) const {
        if (u < 1 || u > N) return -1;
        if (depth[u] < k) return -1;
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                u = anc[u][j];
                if (u < 0) return -1;
            }
        }
        return u;
    }

    // Return the LCA of u and v in O(log N). Returns -1 if invalid.
    int get_lca(int u, int v) const {
        if (u < 1 || u > N || v < 1 || v > N) return -1;
        if (u == v) return u;
        // Ensure u is at least as deep as v
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        // Lift u up to match depth[v]
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = anc[u][j];
                if (u < 0) return -1;
            }
        }
        if (u == v) return u;
        // Lift both until their ancestors diverge
        for (int j = LOG - 1; j >= 0; j--) {
            if (anc[u][j] != anc[v][j]) {
                u = anc[u][j];
                v = anc[v][j];
            }
        }
        // Now their parents are equal
        return anc[u][0];
    }

    // Return weighted distance (sum of weights) between u and v in O(log N).
    // If either is invalid or tree is disconnected, returns -1.
    graphType distance(int u, int v) const {
        int w = get_lca(u, v);
        if (w < 0) return -1;
        return dist[u] + dist[v] - 2 * dist[w];
    }

    // Return the "merge" of edge‐weights on the path from u up exactly k steps.
    // That is, if k = 3, it merges edge(u->anc[u][0]), edge(anc[u][0]->anc[u][1]), edge(anc[u][1]->anc[u][2]).
    // O(log N). Returns `neutral` if depth[u] < k.
    treeType get_cost(int u, int k) const {
        if (u < 1 || u > N) return neutral;
        if (depth[u] < k) return neutral;
        treeType ret = neutral;
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                ret = operation(ret, cost[u][j]);
                u = anc[u][j];
                if (u < 0) break;
            }
        }
        return ret;
    }

    // Query the merged result of edge‐weights on the entire path u→v (commutative op).
    // O(log N).
    treeType query(int u, int v) const {
        int w = get_lca(u, v);
        if (w < 0) return neutral;
        // Merge edges on u→w
        treeType leftMerge  = get_cost(u, depth[u] - depth[w]);
        // Merge edges on v→w
        treeType rightMerge = get_cost(v, depth[v] - depth[w]);
        return operation(leftMerge, rightMerge);
    }

private:
    // DFS to set anc[u][0], cost[u][0], depth[u], dist[u].
    // Parameters:
    //   u         : current node
    //   p         : parent of u (or -1 if u is root)
    //   d         : depth of u
    //   edgeCost  : weight of edge (p->u), or neutral if u is root
    void dfs(int u, int p, int d, treeType edgeCost) {
        anc[u][0]   = p;
        cost[u][0]  = edgeCost;    // this is the “merge value” for the single edge from p->u
        depth[u]    = d;

        // If we want to maintain a separate dist[] for "sum of weights from root",
        // cast edgeCost back to graphType (assuming that's how the user wants).
        if (p < 0) dist[u] = 0;
        else         dist[u] = dist[p] + static_cast<graphType>(edgeCost);

        for (auto &ed : adj[u]) {
            int v      = ed.first;
            graphType w = ed.second;
            if (v == p) continue;
            dfs(v, u, d + 1, static_cast<treeType>(w));
        }
    }
};

/* ================= Example Usage =================

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Suppose you want the sum of edge-weights on path(a,b).
    // So: treeType = long long, graphType = long long, op = sum, neutral = 0.
    auto sum_op = [](long long a, long long b) { return a + b; };
    long long sum_neutral = 0LL;

    LCA<long long,long long> solver;
    solver.init(N);

    // Read N-1 edges (u, v, w).
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        solver.addEdge(u, v, w);
    }

    // Preprocess, rooting at 1
    solver.build(1);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            int a = solver.get_lca(u, v);
            cout << "LCA(" << u << "," << v << ") = " << a << "\n";
        }
        else if (type == 2) {
            int u, v;
            cin >> u >> v;
            long long pathSum = solver.query(u, v);
            cout << "sumWeight(" << u << "," << v << ") = " << pathSum << "\n";
        }
        else if (type == 3) {
            int u, v;
            cin >> u >> v;
            long long d = solver.distance(u, v);
            cout << "dist(" << u << "," << v << ") = " << d << "\n";
        }
        else if (type == 4) {
            int u, k;
            cin >> u >> k;
            int anc = solver.kthAncestor(u, k);
            cout << k << "-th ancestor of " << u << " is " << anc << "\n";
        }
    }

    return 0;
}

======================================================== */

/*
  If you want a different merge (e.g. minimum edge-weight on the path), just set:
    treeType = long long (or int)
    graphType = long long (or int)
    auto min_op = [](long long a, long long b) { return min(a, b); };
    long long min_neutral = (long long)1e18;  // something like INF
    LCA<long long, long long> solver(N, {}, min_op, min_neutral, 1);
    // ... then add edges and build(1). query(u,v) gives the minimum edge on path.
*/
