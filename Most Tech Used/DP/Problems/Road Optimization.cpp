// Codeforces : https://codeforces.com/contest/1625/problem/C
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

int n , l , k , dp[505][505] , h[505] , d[505] , a[505];

int idk(int i , int rem) {
    if(i == n)
        return 0;
    int &ret = dp[i][rem];
    if(~ret)
        return ret;
    ret = 1e17;
    for (int j = i + 1; j <= n; ++j) {
        if(rem + (j - i - 1) <= k)
            ret = min(ret , idk(j , rem + (j - i - 1)) + (h[j] - h[i]) * d[i]);
    }
    return ret;
}

void solve() {
    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    h[n] = l;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    init;
    cout << idk(0 , 0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين