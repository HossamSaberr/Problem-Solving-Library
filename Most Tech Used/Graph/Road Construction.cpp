// Codeforces : https://codeforces.com/contest/330/problem/B
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

int n , m;
const int N = 1e5 + 5;
vector<vector<int>> adj(N);
vector<bool> vis(N);
vector<bool> vis2(N);
vector<int> color(N);
vector<int> deg(N);

bool Cycle(int node , int parent) {
    vis[node] = true;
    for (auto to : adj[node]) {
        if (!vis[to]) {
            if (Cycle(to, node))
                return true;
        }
        else if (to != parent)
            return true;
    }
    return false;
}

void dfs(int node) {
    vis2[node] = true;
    for (auto to : adj[node]) {
        if (!vis2[to])
            dfs(to);
    }
}

bool Bipartite(int node) {
    bool ans = true;
    for(auto neig : adj[node]) {
        if(!color[neig]) {
            color[neig] = color[node] == 1 ? 2 : 1;
            ans &= Bipartite(neig);
        }
        else if(color[neig] == color[node])
            return false;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    vector<int> freq(n + 1);
    for (int i = 0; i < m * 2; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if(freq[i] == 0) {
            ans = i;
            break;
        }
    }
    cout << n - 1 << endl;
    for(int i = 1; i <= n; i++) {
        if(i != ans)
            cout << ans << ' ' << i << endl;
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين