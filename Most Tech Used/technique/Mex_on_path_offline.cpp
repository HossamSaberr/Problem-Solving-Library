#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXA = 1e5 + 5;

int N, Q;
vector<int> adj[MAXN];
int A[MAXN]; // Original values (must be compressed if large)

// Euler Tour
int euler[2 * MAXN], in[MAXN], out[MAXN], timer = 0;
int depth[MAXN], up[17][MAXN];

// For Mo's
int block_size;
struct Query {
    int l, r, lca, idx;
    int u, v;
    bool operator<(const Query &other) const {
        int blk1 = l / block_size, blk2 = other.l / block_size;
        if (blk1 != blk2) return blk1 < blk2;
        return ((blk1 & 1) ? r < other.r : r > other.r);
    }
};

vector<Query> queries;
int freq[MAXA];
int mex_count[MAXA]; // count of how many numbers with given frequency
int cur_mex = 0;
bool vis[MAXN]; // Node visitation status during Mo's add/remove

void dfs(int u, int p) {
    in[u] = timer;
    euler[timer++] = u;

    up[0][u] = p;
    for (int i = 1; i < 17; i++)
        up[i][u] = up[i-1][up[i-1][u]];

    for (int v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }

    out[u] = timer;
    euler[timer++] = u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 16; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v])
            u = up[i][u];
    if (u == v) return u;
    for (int i = 16; i >= 0; i--)
        if (up[i][u] != up[i][v])
            u = up[i][u], v = up[i][v];
    return up[0][u];
}

// MEX structure
void add(int node) {
    int val = A[node];
    freq[val]++;
    while (freq[cur_mex]) cur_mex++;
}

void remove(int node) {
    int val = A[node];
    freq[val]--;
    if (val < cur_mex) return;
    if (freq[val] == 0 && val < cur_mex)
        cur_mex = val;
    else if (val == cur_mex - 1)
        cur_mex = val;
    while (cur_mex > 0 && freq[cur_mex - 1] == 0)
        cur_mex--;
}

void toggle(int node) {
    if (vis[node])
        remove(node);
    else
        add(node);
    vis[node] ^= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. Euler tour
    timer = 0;
    dfs(1, 1);

    // 2. Build queries
    block_size = sqrt(timer);
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v;
        int w = lca(u, v);
        if (in[u] > in[v]) swap(u, v);
        if (w == u) {
            queries.push_back({in[u], in[v], -1, i, u, v});
        } else {
            queries.push_back({out[u], in[v], w, i, u, v});
        }
    }

    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    vector<int> ans(Q);
    for (auto q : queries) {
        while (l > q.l) toggle(euler[--l]);
        while (r < q.r) toggle(euler[++r]);
        while (l < q.l) toggle(euler[l++]);
        while (r > q.r) toggle(euler[r--]);

        if (q.lca != -1) toggle(q.lca);

        ans[q.idx] = cur_mex;

        if (q.lca != -1) toggle(q.lca);
    }

    for (int x : ans) cout << x << "\n";
}



// value on the edges
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

int N, Q;
vector<pair<int,int>> adj[MAXN]; // (neighbor, label attached to that edge but stored only for child)
int A[MAXN]; // A[node] = label of edge (parent,node). root has -1

// Euler Tour
int euler[2 * MAXN], in[MAXN], out[MAXN], timer = 0;
int depthArr[MAXN], up[17][MAXN];

// Mo's
int block_size;
struct Query {
    int l, r, lca, idx;
    int u, v;
    bool operator<(Query const &other) const {
        int b1 = l / block_size, b2 = other.l / block_size;
        if (b1 != b2) return b1 < b2;
        if (b1 & 1) return r < other.r;
        return r > other.r;
    }
};
vector<Query> queries;
int freq[MAXN]; // frequency of each value (0..N). We'll use domain [0..N], ignore -1.
int cur_mex = 0;
bool vis[MAXN]; // whether node is currently in the active set (on path)

void dfs(int u, int p) {
    in[u] = timer;
    euler[timer++] = u;

    up[0][u] = p ? p : u;
    for (int k = 1; k < 17; ++k)
        up[k][u] = up[k-1][ up[k-1][u] ];

    for (auto [v, lbl] : adj[u]) if (v != p) {
        depthArr[v] = depthArr[u] + 1;
        // store label on child v; it's already provided in adj but also keep in A[v]
        A[v] = lbl;
        dfs(v, u);
    }

    out[u] = timer;
    euler[timer++] = u;
}

int lca(int u, int v) {
    if (depthArr[u] < depthArr[v]) swap(u, v);
    int diff = depthArr[u] - depthArr[v];
    for (int i = 16; i >= 0; --i)
        if (diff & (1<<i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 16; i >= 0; --i) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

// Add value of node (edge-label attached to this node). Root has A[root] = -1 and is ignored.
inline void add_node(int node) {
    int val = A[node];
    if (val < 0) return;
    ++freq[val];
    // if we just filled the current mex, advance it
    while (freq[cur_mex] > 0) ++cur_mex;
}

inline void remove_node(int node) {
    int val = A[node];
    if (val < 0) return;
    --freq[val];
    if (val < cur_mex) {
        // a smaller value became zero -> adjust cur_mex down then up to the first missing
        cur_mex = min(cur_mex, val);
        while (cur_mex > 0 && freq[cur_mex - 1] == 0) --cur_mex;
        while (freq[cur_mex] > 0) ++cur_mex;
    } else {
        // If val >= cur_mex nothing to do; cur_mex remains smallest missing
        if (freq[cur_mex] > 0) { while (freq[cur_mex] > 0) ++cur_mex; }
    }
}

inline void toggle(int node) {
    if (vis[node]) {
        remove_node(node);
        vis[node] = false;
    } else {
        add_node(node);
        vis[node] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    // clear
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
        A[i] = -1;
        vis[i] = false;
    }

    // read edges with labels (values on edges)
    for (int i = 0; i < N - 1; ++i) {
        int u, v; long long w;
        cin >> u >> v >> w;
        // label only matters if <= N (mex <= N). otherwise treat as -1
        int lab = (w <= N ? (int)w : -1);
        // store temporarily both ways; in dfs we will attach label to the child
        adj[u].push_back({v, lab});
        adj[v].push_back({u, lab});
    }

    // build euler + up + depth and store labels in A[child]
    timer = 0;
    depthArr[1] = 0;
    A[1] = -1; // root's "edge" label - ignore
    dfs(1, 0);

    // build queries
    block_size = max(1, (int)sqrt(timer));
    queries.clear();
    queries.reserve(Q);
    for (int i = 0; i < Q; ++i) {
        int u, v; cin >> u >> v;
        int w = lca(u, v);
        if (in[u] > in[v]) swap(u, v);
        if (w == u) {
            // u ancestor of v: use interval [in[u], in[v]] and do NOT add lca separately
            queries.push_back({ in[u], in[v], -1, i, u, v });
        } else {
            // u and v in different subtrees: use [out[u], in[v]] and add lca separately
            queries.push_back({ out[u], in[v], w, i, u, v });
        }
    }

    sort(queries.begin(), queries.end());

    // init freq & cur_mex
    for (int i = 0; i <= N; ++i) freq[i] = 0;
    cur_mex = 0;
    int L = 0, R = -1;
    vector<int> ans(Q, 0);

    for (auto &q : queries) {
        while (L > q.l) toggle(euler[--L]);
        while (R < q.r) toggle(euler[++R]);
        while (L < q.l) toggle(euler[L++]);
        while (R > q.r) toggle(euler[R--]);

        if (q.lca != -1) toggle(q.lca);

        ans[q.idx] = cur_mex;

        if (q.lca != -1) toggle(q.lca);
    }

    for (int i = 0; i < Q; ++i) cout << ans[i] << '\n';
    return 0;
}

