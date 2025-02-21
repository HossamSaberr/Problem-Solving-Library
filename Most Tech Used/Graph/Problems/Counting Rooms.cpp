// CSES : https://cses.fi/problemset/task/1192
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
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1005 , M = 1005;

int n , m;
vector<vector<char>> h(N , vector<char> (M));
vector<vector<bool>> vis(n , vector<bool> (M));

bool valid(int i , int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && h[i][j] == '.';
}

void dfs(int i , int j) {
    vis[i][j] = 1;
    if(valid(i - 1 , j))
        dfs(i - 1 , j);
    if(valid(i + 1 , j))
        dfs(i + 1 , j);
    if(valid(i , j - 1))
        dfs(i , j - 1);
    if(valid(i , j + 1))
        dfs(i , j + 1);
}

void solve() {
    cin >> n >> m;
    h.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(valid(i , j)) {
                ans++;
                dfs(i , j);
            }
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