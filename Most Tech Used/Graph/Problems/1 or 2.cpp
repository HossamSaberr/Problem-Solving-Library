// Atcoder : https://atcoder.jp/contests/abc126/tasks/abc126_e?lang=en
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
#define int long long
#define endl '\n'
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 2e5 + 5;

int n , m;
vector<int> adj[N];
vector<int> like[N];
vector<int> dislike[N];
vector<int> h;
vector<bool> vis(N);
vector<int> color(N);
vector<int> deg(N);

void dfs(int i , vector<int> &component) {
    vis[i] = true;
    component.push_back(i);
    for (auto to : adj[i]) {
        if (!vis[to]) {
            dfs(to , component);
        }
    }
}

vector<vector<int>> getConnectedComponents() {
    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> component;
            dfs(i , component);
            components.push_back(component);
        }
    }
    return components;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u , v , z;
        cin >> u >> v >> z;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> components = getConnectedComponents();
    int ans = components.size();
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين