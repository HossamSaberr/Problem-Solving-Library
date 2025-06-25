

struct HLD {
    // big[v] will always be stored in adj[v][0]
    // who[x]: node number with id(tin) = x

    vector<int> par, sz, head, tin, tout, who, depth , val;

    int dfs1(int u, vector<vector<pair<int , int>>> &adj) {
        for (auto &[v,w]: adj[u]) {
            if (v == par[u])continue;
            depth[v] = depth[u] + 1;
            par[v] = u;
            val[v] = w;
            sz[u] += dfs1(v, adj);
            if (sz[v] > sz[adj[u][0].first] || adj[u][0].first == par[u])
                swap(v, adj[
                        u][0].first);
        }
        return sz[u];
    }

    void dfs2(int u, int &timer, const vector<vector<pair<int , int>>> &adj) {
        tin[u] = ++timer;
        int heavy = (adj[u].size() && adj[u][0].first != par[u] ? adj[u][0].first : -1);
        if (heavy != -1) {
            head[heavy] = head[u];
            dfs2(heavy, timer, adj);
        }
        for (auto [v,w] : adj[u]) {
            if (v == par[u] || v == heavy) continue;
            head[v] = v;
            dfs2(v, timer, adj);
        }
        tout[u] = timer;
    }

    HLD(vector<vector<pair<int , int>>> adj, int r = 1)
            : par(adj.size(), -1), sz(adj.size(), 1),
              head(adj.size(), r), tin(adj.size()), who(adj.size()),
              tout(adj.size()),
              depth(adj.size()),val(adj.size()) {
        dfs1(r, adj);
        int x = 0;
        dfs2(r, x, adj);
        for (int i = 0; i < adj.size(); ++i)
            who[tin[i]] = i;
    }

    vector<pair<int, int>> path(int u, int v) {
        vector<pair<int, int>> res;
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]])swap(u, v);
            if (head[u] != head[v]) {
                res.emplace_back(tin[head[v]], tin[v]);
            } else {
                if (depth[u] > depth[v])swap(u, v);
                res.emplace_back(tin[u], tin[v]); // if the query in edges you need to skip lca by doing tin[u] + 1
                return res;
            }
        }
    }

    pair<int, int> subtree(int u) {
        return {tin[u], tout[u]};
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int lca(int u, int v) {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]])swap(u, v);
            if (head[u] == head[v]) {
                if (depth[u] > depth[v])swap(u, v);
                return u;
            }
        }
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
};
