#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200'000;
const int MAXA = 200'000;  // adjust to your maximum possible A[i]

struct PST {
    struct Node { int l, r, sum; } st[ MAXN * 20 ];
    int cnt = 0;
    int new_node(int from = 0) {
        ++cnt;
        st[cnt] = (from ? st[from] : Node{0,0,0});
        return cnt;
    }
    // point-update: add 1 at position pos
    int update(int prev, int l, int r, int pos) {
        int cur = new_node(prev);
        if (l == r) {
            st[cur].sum = st[prev].sum + 1;
        } else {
            int mid = (l + r) >> 1;
            if (pos <= mid)
                st[cur].l = update(st[prev].l, l, mid, pos);
            else
                st[cur].r = update(st[prev].r, mid+1, r, pos);
            st[cur].sum = st[ st[cur].l ].sum + st[ st[cur].r ].sum;
        }
        return cur;
    }
    // query mex: find smallest idx in [l..r] whose count == 0 
    int query_mex(int nu, int nv, int nw, int npw, int l, int r) {
        if (l == r) return l;
        int left_sum = 
            st[ st[nu].l ].sum + st[ st[nv].l ].sum
          - st[ st[nw].l ].sum - st[ st[npw].l ].sum;
        int mid = (l + r) >> 1;
        if (left_sum < (mid - l + 1))
            return query_mex(st[nu].l, st[nv].l, st[nw].l, st[npw].l, l, mid);
        else
            return query_mex(st[nu].r, st[nv].r, st[nw].r, st[npw].r, mid+1, r);
    }
} pst;

vector<int> adj[MAXN+1];
int A[MAXN+1], depth[MAXN+1], up[20][MAXN+1];
int rootVer[MAXN+1];

void dfs(int u, int p) {
    // build PST version for u
    rootVer[u] = pst.update(rootVer[p], 0, MAXA, A[u]);
    up[0][u] = p;
    depth[u] = depth[p] + 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < 20; i++)
        if (diff & (1<<i)) a = up[i][a];
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

int mex_on_path(int u, int v){
    int w = lca(u, v);
    int pw = up[0][w];
    return pst.query_mex(
        rootVer[u],
        rootVer[v],
        rootVer[w],
        rootVer[pw],
        0, MAXA
    );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. DFS build PST + parent[0] + depth
    dfs(1, 0);

    // 2. Binary‐lifting table
    for(int k = 1; k < 20; k++){
        for(int v = 1; v <= N; v++){
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }

    // 3. Answer queries
    while(Q--){
        int u, v;
        cin >> u >> v;
        cout << mex_on_path(u,v) << "\n";
    }
    return 0;
}


// value on the edges

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200'000;
const int MAXA = 200'000;  // adjust to your maximum possible edge value

struct PST {
    struct Node { int l, r, sum; } st[ MAXN * 22 ]; // a bit larger margin
    int cnt = 0;
    int new_node(int from = 0) {
        ++cnt;
        st[cnt] = (from ? st[from] : Node{0,0,0});
        return cnt;
    }
    // point-update: add 1 at position pos
    int update(int prev, int l, int r, int pos) {
        int cur = new_node(prev);
        if (l == r) {
            st[cur].sum = st[prev].sum + 1;
        } else {
            int mid = (l + r) >> 1;
            if (pos <= mid)
                st[cur].l = update(st[prev].l, l, mid, pos);
            else
                st[cur].r = update(st[prev].r, mid+1, r, pos);
            st[cur].sum = st[ st[cur].l ].sum + st[ st[cur].r ].sum;
        }
        return cur;
    }
    // query mex: find smallest idx in [l..r] whose count == 0 
    int query_mex(int nu, int nv, int nw, int npw, int l, int r) {
        if (l == r) return l;
        int left_sum = 
            st[ st[nu].l ].sum + st[ st[nv].l ].sum
          - st[ st[nw].l ].sum - st[ st[npw].l ].sum;
        int mid = (l + r) >> 1;
        if (left_sum < (mid - l + 1))
            return query_mex(st[nu].l, st[nv].l, st[nw].l, st[npw].l, l, mid);
        else
            return query_mex(st[nu].r, st[nv].r, st[nw].r, st[npw].r, mid+1, r);
    }
} pst;

// store neighbor + edge-value
vector<pair<int,int>> adj[MAXN+1];
int A[MAXN+1];              // A[v] := value of edge parent(v)-v; A[root] unused
int depth[MAXN+1], up[20][MAXN+1];
int rootVer[MAXN+1];

void dfs(int u, int p) {
    up[0][u] = p;
    depth[u] = depth[p] + 1;
    // if this node has a parent (i.e., its value comes from the parent->u edge),
    // create a new PST version adding A[u]; otherwise just copy parent's version
    if (p == 0) {
        rootVer[u] = rootVer[p]; // root: no incoming edge value added
    } else {
        rootVer[u] = pst.update(rootVer[p], 0, MAXA, A[u]);
    }

    for (auto [v, w] : adj[u]) if (v != p) {
        // when exploring child v, store edge-value in A[v] (value of edge u-v)
        A[v] = w;
        dfs(v, u);
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < 20; i++)
        if (diff & (1<<i)) a = up[i][a];
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

int mex_on_path(int u, int v){
    int w = lca(u, v);
    int pw = up[0][w]; // parent of LCA, may be 0 (we treat rootVer[0] = 0)
    return pst.query_mex(
        rootVer[u],
        rootVer[v],
        rootVer[w],
        rootVer[pw],
        0, MAXA
    );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Input: edges with values on them.
    // For each of N-1 lines: u v w  (w is the value on edge u-v)
    for(int i = 0; i < N-1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // initialize rootVer[0] = 0 (empty tree) -- pst.st[0] is zero-initialized
    rootVer[0] = 0;
    depth[0] = 0;
    // assume we use node 1 as root; A[1] remains unused
    dfs(1, 0);

    // binary lifting
    for(int k = 1; k < 20; k++){
        for(int v = 1; v <= N; v++){
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }

    while(Q--){
        int u, v;
        cin >> u >> v;
        cout << mex_on_path(u, v) << '\n';
    }
    return 0;
    
    
    // Here code
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define Shity ios_base::sync_with_stdio(0);
#define Code cin.tie(0),cout.tie(0);
#define By int t = 1;   //cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 2e5;

struct Node {
    int l = 0, r = 0;
    int mx = 0; // maximum depth for values in this node's interval
};

struct PersistentSeg {
    vector<Node> st;
    int N; // domain size: values 0..N
    PersistentSeg(int cap = 1) { init(cap); }
    void init(int cap) {
        N = cap;
        st.clear();
        st.reserve((N+5) * 4);
        st.push_back(Node()); // index 0 is null node (all zeros)
    }
    int new_node(int from = 0) {
        st.push_back(from ? st[from] : Node());
        return (int)st.size() - 1;
    }
    // update: set position pos to value val (we use max in combining but here we assign)
    int update(int prev, int tl, int tr, int pos, int val) {
        int cur = new_node(prev);
        if (tl == tr) {
            st[cur].mx = max(st[cur].mx, val); // safe: keep the deepest occurrence
            return cur;
        }
        int mid = (tl + tr) >> 1;
        if (pos <= mid) {
            st[cur].l = update(st[prev].l, tl, mid, pos, val);
        } else {
            st[cur].r = update(st[prev].r, mid+1, tr, pos, val);
        }
        int leftMx = st[ st[cur].l ].mx;
        int rightMx = st[ st[cur].r ].mx;
        st[cur].mx = max(leftMx, rightMx);
        return cur;
    }

    // find smallest index x in [tl..tr] such that max( verU[x], verV[x] ) <= depthW
    // nodes passed are indices in st for verU and verV
    int find_mex(int nu, int nv, int depthW, int tl, int tr) {
        // if the maximum of the combined interval <= depthW, then all values here are absent
        int combined_mx = max(st[nu].mx, st[nv].mx);
        if (combined_mx <= depthW) {
            return tl; // entire segment is missing -> smallest is left boundary
        }
        if (tl == tr) {
            // combined_mx > depthW -> this value is present; no missing here
            return -1;
        }
        int mid = (tl + tr) >> 1;
        // Try left child first (we want smallest index)
        int leftRes = -1;
        // But we can only prune left if left's combined_mx <= depthW (entire left missing)
        int leftCombinedMx = max(st[ st[nu].l ].mx, st[ st[nv].l ].mx);
        if (leftCombinedMx <= depthW) {
            // whole left is absent -> answer is tl (left boundary)
            return tl;
        } else {
            // we must descend into left to find if there exists a missing value inside
            leftRes = find_mex(st[nu].l, st[nv].l, depthW, tl, mid);
            if (leftRes != -1) return leftRes;
        }
        // else try right
        return find_mex(st[nu].r, st[nv].r, depthW, mid+1, tr);
    }
} pst;

vector<pair<int,int>> adj[N + 5];
int a[N + 5] , dep[N + 5], up[20][N + 5] , par[N + 5];

void dfs(int u, int p , int n) {
    up[0][u] = p;
    dep[u] = dep[p] + 1;
    if (p == 0)
        par[u] = par[p];
    else {
        if (a[u] >= 0)
            par[u] = pst.update(par[p], 0, n, a[u] , dep[u]);
        else
            par[u] = par[p];
    }
    for (auto [v, w] : adj[u]) {
        if (v != p) {
            a[v] = w;
            dfs(v, u , n);
        }
    }
}

int lca(int a, int b){
    if (dep[a] < dep[b])
        swap(a,b);
    int diff = dep[a] - dep[b];
    for (int i = 0; i < 20; i++) {
        if (diff & (1<<i))
            a = up[i][a];
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

int query(int u, int v , int n){
    int w = lca(u, v);
    int pw = up[0][w];return pst.find_mex(par[u] , par[v],dep[w],0, n);
}

void solve() {
    int n , q;
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        int ww = (w < n) ? w : -1;
        adj[u].push_back({v, ww});
        adj[v].push_back({u, ww});
    }
    a[1] = -1;
    par[0] = 0;
    dep[0] = 0;
    dfs(1, 0,n);
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= n; ++j){
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        int ans = query(u , v , n );
        if (ans < 0)
            ans = n;
        cout << ans << endl;
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
}


