// CSES : https://cses.fi/problemset/task/1686
/*
بسم الله الرحمن الرحيم
 
الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ
 
اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const long double pii = 3.1415926536;
#define endl '\n'
#define int long long
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) {solve(); }
#define all(x) begin(x) , end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp)
 
const int N = 2e5 + 5  , MOD = 1e9 +7;
const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
const char dir[] = {'U', 'D', 'L', 'R'};
int add(int x, int a) { return ((a % MOD) + (x % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int binpow(int x,int y,int m = MOD){x%=m;int ans=1;while(y>0){if(y&1)ans=((ans%m)*(x%m))%m;x=((x%m)*(x%m))%m;y/=2;}return ans;}
int gcd(int a , int b) {if(b == 0) return a; return gcd(b , a % b);}
 
void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
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
 
void solve() {
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
    vector<int> cost(sccs.size(), 0);
    for (int i = 0; i < sccs.size(); ++i) {
        for (int v : sccs[i]) {
            cost[i] += h[v];
        }
    }
//    for(auto x : dag) {
//        for(auto it : x)
//            cout << it << ' ';
//        cout << endl;
//    }
    vector<int> dp(sccs.size() , 0);
    int ans = 0;
    for (int i = 0; i < sccs.size(); ++i) {
        dp[i] += cost[i];
        for(auto neg : dag[i])
            dp[neg] = max(dp[neg] , dp[i]);
        ans = max(ans , dp[i]);
    }
    cout << ans << endl;
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
 
// الحمدلله رب العالمين
