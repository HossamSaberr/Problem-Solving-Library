// atcoder : https://atcoder.jp/contests/dp/tasks/dp_h
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MOD = 1e9 + 7;

void solve() {
    int h , w;
    cin >> h >> w;
    vector<vector<char>> grid(h + 1 , vector<char> (w + 1 , '.'));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(h + 1 , vector<int> (w + 1 , 0));
    dp[1][1] = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(grid[i][j] == '.') {
                if(i > 0)
                    dp[i][j] += dp[i - 1][j];
                if(j > 0)
                    dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << dp[h][w] << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
