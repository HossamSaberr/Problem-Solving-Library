// Codeforces : https://codeforces.com/problemset/problem/60/B
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

int n , m , k;
char s[11][11][11];
int ans = 0;
bool vis[11][11][11];

bool valid(int x , int y , int z) {
    return (x > 0 && y > 0 && z > 0 && x <= n && y <= m && z <= k && !vis[x][y][z] && s[x][y][z] == '.');
}

void dfs(int x , int y , int z) {
    if(!valid(x , y , z))
        return;
    vis[x][y][z] = 1;
    ans++;
    dfs(x + 1 , y , z);
    dfs(x - 1 , y , z);
    dfs(x , y + 1 , z);
    dfs(x , y - 1 , z);
    dfs(x , y , z + 1);
    dfs(x , y , z - 1);
}
void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int o = 1; o <= m; o++) {
            for(int j = 1;j <= k; j++) {
                cin >> s[i][o][j];
            }
        }
    }
    int y , z;
    cin >> y >> z;
    dfs(1 , y , z);
    cout << ans;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين