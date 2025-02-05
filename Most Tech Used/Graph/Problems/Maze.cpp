// Codeforces : https://codeforces.com/contest/377/problem/A
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

int n , m , k;
const int N = 505 , M = 505;
vector<vector<char>> grid(N , vector<char> (M));
vector<vector<bool>> vis(N , vector<bool> (M));

bool valid(int i , int j ){
    return i < n && i >= 0 && j < m && j >= 0 && !vis[i][j] && grid[i][j] == '.';
}

void dfs(int i , int j) {
    vis[i][j] = true;
    if(valid(i - 1 , j))
        dfs(i - 1 , j);
    if(valid(i + 1 , j))
        dfs(i + 1 , j);
    if(valid(i , j - 1))
        dfs(i , j - 1);
    if(valid(i , j + 1))
        dfs(i , j + 1);
    if(k-- > 0)
        grid[i][j] = 'X';
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(valid(i , j)) {
                dfs(i, j);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}


int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين