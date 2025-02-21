// Atcoder : https://atcoder.jp/contests/abc206/tasks/abc206_d?lang=en
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
//#define int long long
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


map<int ,vector<int>> adj;
map<int , int> vis;
int c;

void dfs(int i) {
    vis[i] = 1;
    c++;
    for(auto neg : adj[i]) {
        if (!vis[neg])
            dfs(neg);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    set<int> s;
    for (int i = 0 ; i <=n/2;  i++) {
        if (a[i] != a[n-i-1]) {
            adj[a[i]].emplace_back(a[n-i-1]);
            adj[a[n-i-1]].emplace_back(a[i]);
            s.insert(a[i]);
            s.insert(a[n-i-1]);
        }
    }
    int ans = 0 ;
    for (auto it : s) {
        if (!vis[it]) {
            c = 0;
            dfs(it);
            ans += (c - 1);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين