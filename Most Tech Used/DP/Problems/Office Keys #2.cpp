// Codeforces : https://codeforces.com/problemset/problem/830/A
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

void solve() {
    int n , k , o;
    cin >> n >> k >> o;
    int p[n] , key[k] , dp[n + 2][k + 2];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    for (int i = 0; i < k; ++i) {
        cin >> key[i];
    }
    sort(key, key + k);
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            dp[i][j] = 1e17;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (dp[i][j] == 1e17)
                continue;
            dp[i][j + 1] = min(dp[i][j + 1] , dp[i][j]); // skip this key;
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1] , max(dp[i][j] , abs(p[i] - key[j]) + abs(key[j] - o))); // take this key;
        }
    }
    int ans = 1e17;
    for (int j = 0; j <= k; ++j) {
        ans = min(ans , dp[n][j]);
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
