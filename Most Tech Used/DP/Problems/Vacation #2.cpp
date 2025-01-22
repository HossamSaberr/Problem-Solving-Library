// atcoder : https://atcoder.jp/contests/dp/tasks/dp_c
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1 , 0) , b(n + 1 , 0) , c(n + 1 , 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    vector<vector<int>> dp(n + 1 , vector<int> (3 , 0));
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][1] , dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0] , dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0] , dp[i - 1][1]) + c[i];
    }
    cout << max({dp[n][0] , dp[n][1] , dp[n][2]}) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
