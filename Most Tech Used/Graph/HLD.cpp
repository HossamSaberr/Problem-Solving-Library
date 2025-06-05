class heavy_light_decomposition {
    const int n;
    vector<vector<int>> g;
    vector<int> in, out, size, head, par;
    int it;
    void erase_par(int v, int prev) {
        par[v] = prev;
        for (auto& u : g[v]) {
            if (u == g[v].back()) break;
            if (u == prev) swap(u, g[v].back());
            erase_par(u, v);
        }
        g[v].pop_back();
    }
    void dfs1(int v) {
        for (auto& u : g[v]) {
            dfs1(u);
            size[v] += size[u];
            if (size[u] > size[g[v][0]]) swap(u, g[v][0]);
        }
    }
    void dfs2(int v) {
        in[v] = it++;
        for (auto u : g[v]) {
            head[u] = (u == g[v][0] ? head[v] : u);
            dfs2(u);
        }
        out[v] = it;
    }
public:
    heavy_light_decomposition(int n_)
        : n(n_), g(n), in(n, -1), out(n, -1), size(n, 1), head(n), par(n, -1), it(0) {}
    heavy_light_decomposition(const vector<vector<int>>& G)
        : n(G.size()), g(G), in(n, -1), out(n, -1), size(n, 1), head(n), par(n, -1), it(0) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build(int rt = 0) {
        for (auto v : g[rt]) erase_par(v, rt);
        dfs1(rt);
        head[rt] = rt;
        dfs2(rt);
    }
    int get_id(int v) {
        return in[v];
    }
    int get_lca(int u, int v) {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int sub_size(int u){
        return size[u];
    }
    void path_query(int u, int v, function<void(int, int)> f) {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            f(max(in[head[v]], in[u]), in[v] + 1);
            if (head[u] == head[v]) return;
            v = par[head[v]];
        }
    }
    void subtree_query(int v, function<void(int, int)> f) {
        f(in[v], out[v]);
    }
};