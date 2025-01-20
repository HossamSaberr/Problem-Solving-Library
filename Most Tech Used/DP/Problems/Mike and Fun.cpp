// Codeforces : https://codeforces.com/contest/548/problem/B
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
    int n , m , q;
    cin >> n >> m >> q;
    vector<vector<int>> h(n , vector<int> (m));
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
            if(h[i][j])
                c++;
            else
                c = 0;
            dp[i] = max(dp[i] , c);
        }
    }
    while (q--) {
        int l , r;
        cin >> l >> r;
        l-- , r--;
        h[l][r] = 1 - h[l][r];
        dp[l] = 0;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if(h[l][i])
                ans++;
            else
                ans = 0;
            dp[l] = max(dp[l] , ans);
        }
        cout << *max_element(all(dp)) << endl;
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
