// Codeforces : https://codeforces.com/contest/22/problem/C
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

int n , m , v;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> h;
vector<bool> vis(N);
vector<bool> vis2(N);
vector<int> color(N);
vector<int> deg(N);

void dfs(int node) {
    if(h.size() == 4) {
        if(h.front() == node) {
            int mnn = 0;
            for (int i = 0; i < 3; ++i) {
                for (auto neg: adj[h[i]]) {
                    if (i == 0)
                        mnn += ((neg != h[1]) && (neg != h[2]));
                    else if (i == 1)
                        mnn += ((neg != h[0]) && (neg != h[2]));
                    else
                        mnn += ((neg != h[0]) && (neg != h[1]));
                }
            }
        }
    }
    else {
        for(auto neig : adj[node]) {
            h.push_back(neig);
            dfs(neig);
            h.pop_back();
        }
    }
}

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
    cin >> n >> m >> v;
    int k = n - 2;
    if(m < n - 1 || (m > (k * (k + 1) / 2) + 1))
        return void(cout << -1 << endl);
    vector<pair<int , int>> ans;
    for(int i = 1; i <= n; ++i) {
        if(v == i)
            continue;
        if(m)
            --m , ans.push_back({i , v});
        else
            break;
    }
    for(int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v == i || v == j)
                continue;
            if(v == n && i == 1)
                continue;
            if (m)
                --m , ans.push_back({i , j});
            else
                break;
        }
    }
    for(auto x : ans)
        cout << x.first << ' ' << x.second << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين