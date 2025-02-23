// Codeforces : https://codeforces.com/contest/983/problem/B
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
#define ll long long
#define endl '\n'
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x) , end(x)
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1 , vector<int> (n + 1 , 0));
    for (int i = 0; i < n; ++i) {
        dp[1][i] = a[i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            dp[i][j] = (dp[i - 1][j] ^ dp[i - 1][j + 1]);
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l , r;
        cin >> l >> r;
        l--;
        cout << dp[r - l][l] << endl;
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين