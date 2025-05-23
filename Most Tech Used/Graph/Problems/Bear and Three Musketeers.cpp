// Codeforces : https://codeforces.com/contest/574/problem/B
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

int n , m , mn = 1e17;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> h;

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
            mn = min(mn , mnn);
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

void solve() {
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        h.push_back(i);
        dfs(i);
        h.pop_back();
    }
    if(mn == 1e17)
        mn = -1;
    cout << mn << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين