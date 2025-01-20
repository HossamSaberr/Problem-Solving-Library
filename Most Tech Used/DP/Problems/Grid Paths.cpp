// CSES : https://cses.fi/problemset/task/1638/
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
#define init memset(dp , INT_MAX , sizeof dp)
 
void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
const int MOD = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;
    int dp[n][n] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if(c == '*')
                dp[i][j] = -1;
        }
    }
    if(dp[0][0] == -1 || dp[n - 1][n - 1] == -1)
        return void(cout << 0);
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if(dp[i][0] == 0 && dp[i - 1][0] >= 0) {
            dp[i][0] += dp[i - 1][0];
            if(dp[i][0] >= MOD)
                dp[i][0] -= MOD;
        }
    }
    for (int i = 1; i < n; ++i) {
        if(dp[0][i] == 0 && dp[0][i - 1] >= 0) {
            dp[0][i] += dp[0][i - 1];
            if(dp[0][i] >= MOD)
                dp[0][i] -= MOD;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if(dp[i][j] < 0)
                continue;
            if(dp[i - 1][j] >= 0)
                dp[i][j] += dp[i - 1][j];
            if(dp[i][j - 1] >= 0)
                dp[i][j] += dp[i][j - 1];
            if(dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }
    }
    cout << dp[n - 1][n - 1];
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين