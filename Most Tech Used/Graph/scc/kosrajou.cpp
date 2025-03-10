#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin() , v.end()

struct Kosaraju {
    int n;
    vector<vector<int>> adj, adj_rev;
    vector<bool> used;
    vector<int> order, component;
    vector<int> scc_id;
 
    Kosaraju(int n) : n(n), adj(n), adj_rev(n), used(n, false), scc_id(n, -1) {}
 
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
 
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v])
            if (!used[u])
                dfs1(u);
        order.push_back(v);
    }
 
    void dfs2(int v, int scc_idx) {
        used[v] = true;
        component.push_back(v);
        scc_id[v] = scc_idx;
        for (int u : adj_rev[v])
            if (!used[u])
                dfs2(u, scc_idx);
    }
 
    vector<vector<int>> find_sccs() {
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; ++i)
            if (!used[i])
                dfs1(i);
 
        fill(used.begin(), used.end(), false);
        reverse(order.begin(), order.end());
        vector<vector<int>> sccs;
        int scc_idx = 0;
 
        for (int v : order) {
            if (!used[v]) {
                component.clear();
                dfs2(v, scc_idx);
                sccs.push_back(component);
                scc_idx++;
            }
        }
        return sccs;
    }
 
    vector<vector<int>> build_dag() {
        int scc_count = find_sccs().size();
        vector<vector<int>> dag(scc_count);
        set<pair<int, int>> edges;
 
        for (int v = 0; v < n; ++v) {
            for (int u : adj[v]) {
                int scc_v = scc_id[v], scc_u = scc_id[u];
                if (scc_v != scc_u && edges.insert({scc_v, scc_u}).second) {
                    dag[scc_v].push_back(scc_u);
                }
            }
        }
        return dag;
    }
 
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    Kosaraju kos(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        kos.add_edge(a, b);
    }
    vector<vector<int>> sccs = kos.find_sccs();
    vector<vector<int>> dag = kos.build_dag();
    return 0;
}
