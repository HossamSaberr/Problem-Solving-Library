#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin() , v.end()

template<typename T>
struct Kosaraju {
    int n;
    vector<vector<T>> adj, adj_rev;
    vector<bool> used;
    vector<T> order, component;

    Kosaraju(int n) : n(n), adj(n), adj_rev(n), used(n, false) {}

    void add_edge(T u, T v) {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    void dfs1(T v) {
        used[v] = true;
        for (auto u : adj[v])
            if (!used[u])
                dfs1(u);
        order.push_back(v);
    }

    void dfs2(T v) {
        used[v] = true;
        component.push_back(v);
        for (auto u : adj_rev[v])
            if (!used[u])
                dfs2(u);
    }

    vector<vector<T>> find_sccs() {
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; ++i) if (!used[i]) {
                dfs1(i);
            }

        fill(used.begin(), used.end(), false);
        reverse(order.begin(), order.end());
        vector<vector<T>> sccs;
        for (auto v : order) if (!used[v]) {
                component.clear();
                dfs2(v);
                sccs.push_back(component);
            }
        return sccs;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Kosaraju<int> kos(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        kos.add_edge(a, b);
    }

    vector<vector<int>> sccs = kos.find_sccs();
    return 0;
}
