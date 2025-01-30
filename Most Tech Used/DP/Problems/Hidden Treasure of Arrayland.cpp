// Codeforces : https://codeforces.com/gym/105408/problem/H
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
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , k , h[100005] , dp[100005][105][2];

int idk(int i , int rem , bool used) {
    if(i == n)
        return 0;
    int &ret = dp[i][rem][used];
    if(~ret)
        return ret;
    int ch1 = -1e9 , ch2 = -1e9 , ch3 = -1e9;
    ch1 = max(0ll , idk(i + 1 , rem , used) + (used ? -h[i] : h[i])); // continue
    if(used == 0 && rem + 1 <= k)
        ch2 = idk(i + 1 , rem + 1 , 1) + -h[i]; // start flipping
    if(used)
        ch3 = idk(i + 1 , rem , 0) + h[i]; // end flipping
    return ret = max({ch1 , ch2 , ch3});
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    init;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans , idk(i , 0 , 0));
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين