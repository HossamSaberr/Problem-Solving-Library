// Codeforces : https://codeforces.com/problemset/problem/534/B
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

int v1 , v2 , tr , d;
int dp[101][10009];

void solve() {
    cin >> v1 >> v2 >> tr >> d;
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 10009; ++j) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][v1] = 0;
    for (int i = 0; i < tr - 1; ++i) {
        for (int j = 0; j < 1199; ++j) {
            for (int k = -d; k <= d; ++k) {
                if(j + k < 0 || j + k > 1200)
                    continue;
                dp[i + 1][j + k] = max(dp[i + 1][j + k] , j + dp[i][j]);
            }
        }
    }
    cout << dp[tr - 1][v2] + v2 << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
