// CSES : https://cses.fi/problemset/task/1683/

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

template<typename T>
struct Kosaraju {
    int n;
    vector<vector<int>> adj, adj_rev;
    vector<bool> used;
    vector<int> order, component;

    Kosaraju(int n) : n(n), adj(n), adj_rev(n), used(n, false) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    void dfs1(int v) {
        used[v] = true;
        for (auto u : adj[v])
            if (!used[u])
                dfs1(u);
        order.push_back(v);
    }

    void dfs2(int v) {
        used[v] = true;
        component.push_back(v);
        for (auto u : adj_rev[v])
            if (!used[u])
                dfs2(u);
    }

    vector<vector<int>> find_sccs() {
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; ++i) if (!used[i]) {
                dfs1(i);
            }

        fill(used.begin(), used.end(), false);
        reverse(order.begin(), order.end());
        vector<vector<int>> sccs;
        for (auto v : order) if (!used[v]) {
                component.clear();
                dfs2(v);
                sccs.push_back(component);
            }
        return sccs;
    }
};

void solve() {
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
    vector<int> ans(n);
    int c = 1;
    for(auto x : sccs) {
        for(auto it : x)
            ans[it] = c;
        c++;
    }
    cout << sccs.size() << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين