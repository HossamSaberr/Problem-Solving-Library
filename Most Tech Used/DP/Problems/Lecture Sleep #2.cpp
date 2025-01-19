// Codeforces : https://codeforces.com/gym/302977/problem/D

// V2 : Push DP
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 resulting a 0 or 0xFF resulting -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , k;
const int N = 1e5 + 5;
int h[N] , c[N] , dp[N][2] , pre[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + h[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    init;
    // push DP
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(dp[i][j] == -1)
                continue;
            if(i + 1 <= n)
                dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j] + (c[i] > 0 ? h[i] : 0)); // skip
            if(j == 0 && i + k <= n)
                dp[i + k][1] = max(dp[i + k][1] , dp[i][j] + pre[i + k] - pre[i]); // use
        }
    }
    cout << dp[n][1] << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
