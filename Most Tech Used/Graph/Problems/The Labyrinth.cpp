// Codeforces : https://codeforces.com/problemset/problem/616/C
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

const int N = 1009;
int dx[] = {0, 0 , 1 , -1};
int dy[] = {1 , -1 , 0, 0};
int n, m, c;
vector<int> o;
char grid[N][N];
int vis[N][N];

bool valid(int x , int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

void dfs(int i , int j) {
    vis[i][j] = c;
    o[c]++;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x , y) && vis[x][y] == 0) {
            dfs(x , y);
        }
    }
}

void solve() {
    cin >> n >> m;
    o.resize(n * m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));
    c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*' || vis[i][j] != 0)
                continue;
            dfs(i, j);
            c++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.')
                cout << grid[i][j];
            else {
                int ans = 1;
                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (valid(x , y))
                        components.insert(vis[x][y]);
                }
                for (auto comp : components) {
                    ans += o[comp];
                }
                cout << (ans % 10);
            }
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