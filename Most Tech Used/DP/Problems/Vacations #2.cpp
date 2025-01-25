// Codeforces : https://codeforces.com/contest/698/problem/A
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
#define all(x) rbegin(x), rend(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve(){
    int n;
    cin >> n;
    int h[n] , dp[n + 1][3];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][1] , dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0] , dp[i - 1][2]);
        dp[i][2] = max(dp[i - 1][0] , dp[i - 1][1]);
        if(h[i - 1] == 1 || h[i - 1] == 3)
            dp[i][1]++; // do contest
        if(h[i - 1] == 2 || h[i - 1] == 3)
            dp[i][2]++; // do sport
    }
    cout << n - max({dp[n][0] , dp[n][1] , dp[n][2]}) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
