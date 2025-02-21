// Codeforces : https://codeforces.com/problemset/problem/585/B
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
#define By int t = 1;cin >> t;
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

char grid[10][1000];
int n , vis[10][1000];
bool hossam;

void dfs(int x ,int y) {
    if(y >= n) {
        hossam = 1;
        return;
    }
    vis[x][y] = 1;
    if(grid[x][y+1] != '.')
        return;
    if(x-1<=3&&x-1>=1&&grid[x-1][y+1]=='.'&&grid[x-1][y+2]=='.'&&grid[x-1][y+3]=='.')
        dfs(x-1,y+3);
    if(x+1<=3&&x+1>=1&&grid[x+1][y+1]=='.'&&grid[x+1][y+2]=='.'&&grid[x+1][y+3]=='.')
        dfs(x+1,y+3);
    if(!vis[x][y+3]&&grid[x][y+2]=='.'&&grid[x][y+3]=='.')
        dfs(x,y+3);
}

void solve(){
    hossam = 0;
    int k , x , y;
    cin >> n >> k;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            vis[i][j] = 0;
            if(grid[i][j] == 's') {
                x = i;
                y = j;
            }
        }
    }
    for(int i = 1; i <= 3; i++) {
        for (int j = n + 1; j <= n + 5; j++) {
            grid[i][j] = '.';
        }
    }
    dfs(x , y);
    if(hossam)
        YES;
    else
        NO;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين