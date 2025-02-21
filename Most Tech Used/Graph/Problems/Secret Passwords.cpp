// Codeforces : https://codeforces.com/problemset/problem/1263/D
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

const int N = 2005;

int n;
vector<int> h;
vector<int> color(N);
vector<int> deg(N);
map<string , vector<string>> adj;
map<string , bool> vis;

void dfs(string i) {
    vis[i] = true;
    for (auto to : adj[i]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
}

void solve() {
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for(auto ch : s) {
            string a = "";
            a += ch;
            adj[s].push_back(a);
            adj[a].push_back(s);
        }
    }
    int ans = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        string a;
        a += i;
        if (!vis[a] && adj[a].size()) {
            ans++;
            dfs(a);
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